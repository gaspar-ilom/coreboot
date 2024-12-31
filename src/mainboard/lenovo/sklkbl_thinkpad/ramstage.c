/* SPDX-License-Identifier: GPL-2.0-only */

#include <arch/io.h>
#include <device/device.h>
#include <drivers/intel/gma/int15.h>
#include <option.h>
#include <soc/ramstage.h>
#include "ec.h"
#include "gpio.h"

#define GPIO_GPU_RST		GPP_E22 // active low
#define GPIO_1R8VIDEO_AON_ON	GPP_E23

#define GPIO_DGFX_PWRGD		GPP_F3

#define GPIO_DISCRETE_PRESENCE	GPP_D9	// active low
#define GPIO_DGFX_VRAM_ID0	GPP_D11
#define GPIO_DGFX_VRAM_ID1	GPP_D12

void mainboard_silicon_init_params(FSP_SIL_UPD *params)
{
	static const char * const dgfx_vram_id_str[] = { "1GB", "2GB", "4GB", "N/A" };

	int dgfx_vram_id;

	// Setup GPIOs
	variant_config_gpios();

	// Detect and enable dGPU
	if (gpio_get(GPIO_DISCRETE_PRESENCE) == 0) { // active low
		dgfx_vram_id = gpio_get(GPIO_DGFX_VRAM_ID0) | gpio_get(GPIO_DGFX_VRAM_ID1) << 1;
		printk(BIOS_DEBUG, "Discrete GPU present with %s VRAM\n", dgfx_vram_id_str[dgfx_vram_id]);

		// NOTE: i pulled this GPU enable sequence from thin air
		// it sometimes works but is buggy and the GPU disappears in some cases so disabling it by default.
		// also unrelated to this enable sequence the nouveau driver only works on 6.8-6.9 kernels
		if (get_uint_option("dgpu_enable", 0)) {
			printk(BIOS_DEBUG, "Enabling discrete GPU\n");
			gpio_set(GPIO_1R8VIDEO_AON_ON, 1);	// Enable GPU power rail
			while (!gpio_get(GPIO_DGFX_PWRGD))	// Wait for power good signal from GPU
				;
			gpio_set(GPIO_GPU_RST, 1);		// Release GPU from reset
		} else {
			printk(BIOS_DEBUG, "Discrete GPU will remain disabled\n");
		}

	} else {
		printk(BIOS_DEBUG, "Discrete GPU not present\n");
	}
}

static void dump_ec_cfg(uint16_t port)
{
	microchip_pnp_enter_conf_state(port);

	// Device info
	printk(BIOS_DEBUG, "Device id  %02x\n", pnp_read(port, EC_DEVICE_ID));
	printk(BIOS_DEBUG, "Device rev %02x\n", pnp_read(port, EC_DEVICE_REV));

	// Switch to LPCIF LDN
	pnp_write(port, PNP_LDN_SELECT, LDN_LPCIF);

	// Dump SIRQs
	for (int i = 0; i <= 15; i += 1)
		printk(BIOS_DEBUG, "SIRQ%d = %02x\n", i, pnp_read(port, LPCIF_SIRQ(i)));

	// Dump BARs
	printk(BIOS_DEBUG, "BAR CFG = %08x\n", pnp_read_le32(port, LPCIF_BAR_CFG));
	printk(BIOS_DEBUG, "BAR MAILBOX = %08x\n", pnp_read_le32(port, LPCIF_BAR_MAILBOX));
	printk(BIOS_DEBUG, "BAR 8042 = %08x\n", pnp_read_le32(port, LPCIF_BAR_8042));
	printk(BIOS_DEBUG, "BAR ACPI_EC0 = %08x\n", pnp_read_le32(port, LPCIF_BAR_ACPI_EC0));
	printk(BIOS_DEBUG, "BAR ACPI_EC1 = %08x\n", pnp_read_le32(port, LPCIF_BAR_ACPI_EC1));
	printk(BIOS_DEBUG, "BAR ACPI_EC2 = %08x\n", pnp_read_le32(port, LPCIF_BAR_ACPI_EC2));
	printk(BIOS_DEBUG, "BAR ACPI_EC3 = %08x\n", pnp_read_le32(port, LPCIF_BAR_ACPI_EC3));
	printk(BIOS_DEBUG, "BAR ACPI_PM0 = %08x\n", pnp_read_le32(port, LPCIF_BAR_ACPI_PM0));
	printk(BIOS_DEBUG, "BAR UART = %08x\n", pnp_read_le32(port, LPCIF_BAR_UART));
	printk(BIOS_DEBUG, "BAR FAST_KYBD = %08x\n", pnp_read_le32(port, LPCIF_BAR_FAST_KYBD));
	printk(BIOS_DEBUG, "BAR EMBED_FLASH = %08x\n", pnp_read_le32(port, LPCIF_BAR_EMBED_FLASH));
	printk(BIOS_DEBUG, "BAR GP_SPI = %08x\n", pnp_read_le32(port, LPCIF_BAR_GP_SPI));
	printk(BIOS_DEBUG, "BAR EMI = %08x\n", pnp_read_le32(port, LPCIF_BAR_EMI));
	printk(BIOS_DEBUG, "BAR PMH7 = %08x\n", pnp_read_le32(port, LPCIF_BAR_PMH7));
	printk(BIOS_DEBUG, "BAR PORT80_DBG0 = %08x\n", pnp_read_le32(port, LPCIF_BAR_PORT80_DBG0));
	printk(BIOS_DEBUG, "BAR PORT80_DBG1 = %08x\n", pnp_read_le32(port, LPCIF_BAR_PORT80_DBG1));
	printk(BIOS_DEBUG, "BAR RTC = %08x\n", pnp_read_le32(port, LPCIF_BAR_RTC));

	microchip_pnp_exit_conf_state(port);
}

static void mainboard_enable(struct device *dev)
{
	if (CONFIG(VGA_ROM_RUN))
		install_intel_vga_int15_handler(GMA_INT15_ACTIVE_LFP_EDP,
						GMA_INT15_PANEL_FIT_DEFAULT,
						GMA_INT15_BOOT_DISPLAY_DEFAULT, 0);
}

static void mainboard_init(void *chip_info)
{
	dump_ec_cfg(EC_CFG_PORT);
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
	.init = mainboard_init,
};
