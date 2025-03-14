## SPDX-License-Identifier: GPL-2.0-only

bootblock-y += bootblock.c
bootblock-y += memmap.c

romstage-y += ../qemu-i440fx/memmap.c
romstage-y += memmap.c

postcar-y += ../qemu-i440fx/memmap.c
postcar-y += ../qemu-i440fx/exit_car.S
postcar-y += memmap.c

ramstage-y += ../qemu-i440fx/memmap.c
ramstage-y += ../qemu-i440fx/northbridge.c
ramstage-y += ../qemu-i440fx/rom_media.c
ramstage-y += memmap.c
ramstage-y += cpu.c

all-y += ../qemu-i440fx/bootmode.c

ramstage-$(CONFIG_CHROMEOS) += chromeos.c

smm-y += ../qemu-i440fx/rom_media.c
smm-y += memmap.c
smm-y += smihandler.c
