/* SPDX-License-Identifier: GPL-2.0-only */

#include <arch/io.h>
#include "ec.h"

#define MICROCHIP_CONFIGURATION_ENTRY_KEY	0x55
#define MICROCHIP_CONFIGURATION_EXIT_KEY	0xaa

void microchip_pnp_enter_conf_state(uint16_t port)
{
	outb(MICROCHIP_CONFIGURATION_ENTRY_KEY, port);
}

void microchip_pnp_exit_conf_state(uint16_t port)
{
	outb(MICROCHIP_CONFIGURATION_EXIT_KEY, port);
}

uint8_t pnp_read(uint16_t port, uint8_t index)
{
	outb(index, port);
	return inb(port + 1);
}

uint32_t pnp_read_le32(uint16_t port, uint8_t index)
{
	return (uint32_t) pnp_read(port, index) |
			(uint32_t) pnp_read(port, index + 1) << 8 |
			(uint32_t) pnp_read(port, index + 2) << 16 |
			(uint32_t) pnp_read(port, index + 3) << 24;
}

void pnp_write(uint16_t port, uint8_t index, uint8_t value)
{
	outb(index, port);
	outb(value, port + 1);
}

void pnp_write_le32(uint16_t port, uint8_t index, uint32_t value)
{
	pnp_write(port, index, value & 0xff);
	pnp_write(port, index + 1, value >> 8 & 0xff);
	pnp_write(port, index + 2, value >> 16 & 0xff);
	pnp_write(port, index + 3, value >> 24 & 0xff);
}

static void ecN_clear_out_queue(uint16_t cmd_port, uint16_t data_port)
{
	while (inb(cmd_port) & EC_OBF)
		inb(data_port);
}

static void ecN_wait_to_send(uint16_t cmd_port, uint16_t data_port)
{
	while (inb(cmd_port) & EC_IBF)
		;
}

static void ecN_wait_to_recv(uint16_t cmd_port, uint16_t data_port)
{
	while (!(inb(cmd_port) & EC_OBF))
		;
}

uint8_t ecN_read(uint16_t cmd_port, uint16_t data_port, uint8_t addr)
{
	ecN_clear_out_queue(cmd_port, data_port);
	ecN_wait_to_send(cmd_port, data_port);
	outb(EC_READ, cmd_port);
	ecN_wait_to_send(cmd_port, data_port);
	outb(addr, data_port);
	ecN_wait_to_recv(cmd_port, data_port);
	return inb(data_port);
}

void ecN_write(uint16_t cmd_port, uint16_t data_port, uint8_t addr, uint8_t val)
{
	ecN_clear_out_queue(cmd_port, data_port);
	ecN_wait_to_send(cmd_port, data_port);
	outb(EC_WRITE, cmd_port);
	ecN_wait_to_send(cmd_port, data_port);
	outb(addr, data_port);
	ecN_wait_to_send(cmd_port, data_port);
	outb(val, data_port);
}

uint8_t eeprom_read(uint16_t addr)
{
	ecN_clear_out_queue(EC2_CMD, EC2_DATA);
	ecN_wait_to_send(EC2_CMD, EC2_DATA);
	outl(1, EC2_CMD);
	ecN_wait_to_send(EC2_CMD, EC2_DATA);
	outl(addr, EC2_DATA);
	ecN_wait_to_recv(EC2_CMD, EC2_DATA);
	return inl(EC2_DATA);
}

void eeprom_write(uint16_t addr, uint8_t val)
{
	ecN_clear_out_queue(EC2_CMD, EC2_DATA);
	ecN_wait_to_send(EC2_CMD, EC2_DATA);
	outl(2, EC2_CMD);
	ecN_wait_to_send(EC2_CMD, EC2_DATA);
	outl((uint32_t) addr | (uint32_t) val << 16, EC2_DATA);
	ecN_wait_to_recv(EC2_CMD, EC2_DATA);
	inl(EC2_DATA);
}

uint16_t debug_loaded_keys(void)
{
	return (uint16_t) ec0_read(0x87) << 8 | (uint16_t) ec0_read(0x86);
}

static void debug_cmd(uint8_t cmd)
{
	ec0_write(EC_DEBUG_CMD, cmd);
	while (ec0_read(EC_DEBUG_CMD) & 0x80)
		;
}

void debug_read_key(uint8_t i, uint8_t *key)
{
	debug_cmd(0x80 | (i & 0xf));
	for (int j = 0; j < 8; ++j)
		key[j] = ec0_read(0x3e + j);
}

void debug_write_key(uint8_t i, const uint8_t *key)
{
	for (int j = 0; j < 8; ++j)
		ec0_write(0x3e + j, key[j]);
	debug_cmd(0xc0 |  (i & 0xf));
}

uint32_t debug_read_dword(uint32_t addr)
{
	ecN_clear_out_queue(EC3_CMD, EC3_DATA);
	ecN_wait_to_send(EC3_CMD, EC3_DATA);
	outl(addr << 8 | 0xE2, EC3_DATA);
	ecN_wait_to_recv(EC3_CMD, EC3_DATA);
	return inl(EC3_DATA);
}

void debug_write_dword(uint32_t addr, uint32_t val)
{
	ecN_clear_out_queue(EC3_CMD, EC3_DATA);
	ecN_wait_to_send(EC3_CMD, EC3_DATA);
	outl(addr << 8 | 0xEA, EC3_DATA);
	ecN_wait_to_send(EC3_CMD, EC3_DATA);
	outl(val, EC3_DATA);
}

const uint8_t debug_rw_key[8] = { 0x7a, 0x41, 0xb1, 0x49, 0xfe, 0x21, 0x01, 0xcf };
