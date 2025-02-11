/* SPDX-License-Identifier: GPL-2.0-only */

// #include <southbridge/intel/common/gpio.h>
#include <console/console.h>
#include <device/device.h>
#include <ec/acpi/ec.h>
#include <option.h>
#include <types.h>

#include "h8.h"
#include "chip.h"

/* Controls radio-off pin in WWAN MiniPCIe slot.  */
void h8_wwan_enable(int on)
{
	if (on)
		ec_set_bit(0x3a, 6);
	else
		ec_clr_bit(0x3a, 6);
}

/*
 * Detect WWAN on supported MBs.
 */
bool h8_has_wwan(const struct device *dev)
{
	struct ec_lenovo_h8_config *conf = dev->chip_info;

	if (1 || !conf->has_wwan_detection) {
		printk(BIOS_INFO, "H8: WWAN detection not implemented. "
				  "Assuming WWAN installed\n");
		return true;
	}

#if 0
	if (get_gpio(conf->wwan_gpio_num) == conf->wwan_gpio_lvl) {
		printk(BIOS_INFO, "H8: WWAN installed\n");
		return true;
	}
#endif

	printk(BIOS_INFO, "H8: WWAN not installed\n");
	return false;
}

/*
 * Return WWAN NVRAM setting.
 */
bool h8_wwan_nv_enable(void)
{
	return get_uint_option("wwan", true);
}
