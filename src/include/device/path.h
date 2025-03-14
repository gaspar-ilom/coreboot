/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef DEVICE_PATH_H
#define DEVICE_PATH_H

#include <stdint.h>

enum device_path_type {
	DEVICE_PATH_NONE = 0,
	DEVICE_PATH_ROOT,
	DEVICE_PATH_PCI,
	DEVICE_PATH_PNP,
	DEVICE_PATH_I2C,
	DEVICE_PATH_APIC,
	DEVICE_PATH_DOMAIN,
	DEVICE_PATH_CPU_CLUSTER,
	DEVICE_PATH_CPU,
	DEVICE_PATH_CPU_BUS,
	DEVICE_PATH_IOAPIC,
	DEVICE_PATH_GENERIC,
	DEVICE_PATH_SPI,
	DEVICE_PATH_USB,
	DEVICE_PATH_MMIO,
	DEVICE_PATH_GPIO,
	DEVICE_PATH_MDIO,
	DEVICE_PATH_GICC_V3,

	/*
	 * When adding path types to this table, please also update the
	 * DEVICE_PATH_NAMES macro below.
	 */
};

#define DEVICE_PATH_NAMES {			\
		"DEVICE_PATH_NONE",		\
		"DEVICE_PATH_ROOT",		\
		"DEVICE_PATH_PCI",		\
		"DEVICE_PATH_PNP",		\
		"DEVICE_PATH_I2C",		\
		"DEVICE_PATH_APIC",		\
		"DEVICE_PATH_DOMAIN",		\
		"DEVICE_PATH_CPU_CLUSTER",	\
		"DEVICE_PATH_CPU",		\
		"DEVICE_PATH_CPU_BUS",		\
		"DEVICE_PATH_IOAPIC",		\
		"DEVICE_PATH_GENERIC",		\
		"DEVICE_PATH_SPI",		\
		"DEVICE_PATH_USB",		\
		"DEVICE_PATH_MMIO",		\
		"DEVICE_PATH_GPIO",		\
		"DEVICE_PATH_MDIO",		\
		"DEVICE_PATH_GICC_V3",		\
}

struct domain_path {
	unsigned int domain_id;
};

struct pci_path {
	unsigned int devfn;
};

struct pnp_path {
	unsigned int port;
	unsigned int device;
};

struct i2c_path {
	unsigned int device;
	unsigned int mode_10bit;
};

struct spi_path {
	unsigned int cs;
};

struct apic_path {
	unsigned int initial_lapicid;
	unsigned int apic_id;
	unsigned int package_id;
	unsigned int node_id;
	unsigned int core_id;
	unsigned int thread_id;
	unsigned int module_id;
	/*
	 * Core identifier within the package, including the die group, die, tile, module, and
	 * specific core.
	 */
	unsigned int core_id_within_package;
	unsigned char core_type;
};

struct ioapic_path {
	uintptr_t addr;
	unsigned int ioapic_id;
	unsigned int gsi_base;
};

struct cpu_cluster_path {
	unsigned int cluster;
};

struct cpu_path {
	unsigned int id;
};

struct cpu_bus_path {
	unsigned int id;
};

struct generic_path {
	unsigned int id;
	unsigned int subid;
};

struct usb_path {
	unsigned int port_type;
	unsigned int port_id;
};

struct mmio_path {
	uintptr_t addr;
};

struct gpio_path {
	unsigned int id;
};

struct mdio_path {
	unsigned int addr;
};

struct gicc_v3_path {
	unsigned long long mpidr;
	unsigned int vgic_mi;
	unsigned int pi_gsiv;
};

struct device_path {
	enum device_path_type type;
	union {
		struct pci_path		pci;
		struct pnp_path		pnp;
		struct i2c_path		i2c;
		struct apic_path	apic;
		struct ioapic_path	ioapic;
		struct domain_path	domain;
		struct cpu_cluster_path cpu_cluster;
		struct cpu_path		cpu;
		struct cpu_bus_path	cpu_bus;
		struct generic_path	generic;
		struct spi_path		spi;
		struct usb_path		usb;
		struct mmio_path	mmio;
		struct gpio_path	gpio;
		struct mdio_path	mdio;
		struct gicc_v3_path	gicc_v3;
	};
};

#define DEVICE_PATH_MAX 40
#define BUS_PATH_MAX (DEVICE_PATH_MAX+10)

extern const char *dev_path_name(enum device_path_type type);

#endif /* DEVICE_PATH_H */
