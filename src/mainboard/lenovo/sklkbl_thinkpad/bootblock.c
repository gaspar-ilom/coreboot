/* SPDX-License-Identifier: GPL-2.0-only */

#include <arch/io.h>
#include <bootblock_common.h>
#include <device/pci.h>
#include <soc/pci_devs.h>
#include "ec.h"

static void configure_uart(uint16_t port, uint16_t iobase, uint8_t irqno)
{
	microchip_pnp_enter_conf_state(port);

	// Select LPC I/F LDN
	pnp_write(port, PNP_LDN_SELECT, LDN_LPCIF);
	// Write UART BAR
	pnp_write_le32(port, LPCIF_BAR_UART, (uint32_t) iobase << 16 | 0x8707);
	// Set SIRQ4 to UART
	pnp_write(port, LPCIF_SIRQ(irqno), LDN_UART);

	// Configure UART LDN
	pnp_write(port, PNP_LDN_SELECT, LDN_UART);
	pnp_write(port, UART_ACTIVATE, 0x01);
	pnp_write(port, UART_CONFIG_SELECT, 0x00);

	microchip_pnp_exit_conf_state(port);

#ifdef CONFIG_BOARD_LENOVO_T480
	// Supply debug unlock key
	debug_write_key(DEBUG_RW_KEY_IDX, debug_rw_key);

	// Use debug writes to set UART_TX and UART_RX GPIOs
	debug_write_dword(0xf0c400 + 0x110, 0x00001000);
	debug_write_dword(0xf0c400 + 0x114, 0x00001000);
#endif
}


#define UART_PORT	0x3f8
#define UART_IRQ	4

void bootblock_mainboard_early_init(void)
{
	// Tell EC via BIOS Debug Port 1 that the world isn't on fire

	// Let the EC know that BIOS code is running
	outb(0x11, 0x86);
	outb(0x6e, 0x86);

	// Enable accesses to EC1 interface
	ec0_write(0, ec0_read(0) | 0x20);

	// Reset LEDs to power on state
	// (Without this warm reboot leaves LEDs off)
	ec0_write(0x0c, 0x80);
	ec0_write(0x0c, 0x07);
	ec0_write(0x0c, 0x8a);

	// Setup debug UART
	configure_uart(EC_CFG_PORT, UART_PORT, UART_IRQ);
}
