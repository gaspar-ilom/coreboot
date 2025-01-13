/* SPDX-License-Identifier: GPL-2.0-only OR MIT */

#ifndef __SOC_MEDIATEK_MT8196_INCLUDE_SOC_ADDRESSMAP_H__
#define __SOC_MEDIATEK_MT8196_INCLUDE_SOC_ADDRESSMAP_H__

enum {
	SRAM_BASE		= 0x00100000,
	MCUSYS_BASE		= 0x0C000000,
	MCUPM_CFG_BASE		= 0x0C240000,
	MCUPM_SRAM_BASE		= 0x0C250000,
	BUS_TRACE_MONITOR_BASE	= 0x0D040000,
	IO_PHYS			= 0x10000000,
	MFGSYS_BASE		= 0x40000000,
};

enum {
	MCUCFG_BASE		= MCUSYS_BASE,
	CCIPLL_PLL_CTRL_BASE	= MCUSYS_BASE + 0x00030000,
	ARMPLL_LL_PLL_CTRL_BASE	= MCUSYS_BASE + 0x00030400,
	ARMPLL_BL_PLL_CTRL_BASE	= MCUSYS_BASE + 0x00030800,
	ARMPLL_B_PLL_CTRL_BASE	= MCUSYS_BASE + 0x00030C00,
	PTPPLL_PLL_CTRL_BASE	= MCUSYS_BASE + 0x00034000,
};

enum {
	EINT_E_BASE		= IO_PHYS + 0x02080000,
	EINT_S_BASE		= IO_PHYS + 0x02880000,
	EINT_W_BASE		= IO_PHYS + 0x03080000,
	EINT_N_BASE		= IO_PHYS + 0x03880000,
	EINT_C_BASE		= IO_PHYS + 0x0C54A000,
};

enum {
	CKSYS_BASE		= IO_PHYS + 0x00000000,
	APMIXED_BASE		= IO_PHYS + 0x00000800,
	INFRACFG_AO_BASE	= IO_PHYS + 0x00001000,
	CKSYS_GP2_BASE		= IO_PHYS + 0x0000C000,
	DRM_DEBUG_BASE		= IO_PHYS + 0x0000D000,
	APMIXEDSYS_GP2_BASE	= IO_PHYS + 0x0000C800,
	BCRM_INFRA_AO_BASE	= IO_PHYS + 0x00022000,
	PMIF_SPI_BASE		= IO_PHYS + 0x00024000,
	PMICSPI_MST_BASE	= IO_PHYS + 0x00025000,
	BCRM_INFRA1_AO_BASE	= IO_PHYS + 0x0002A000,
	IFRBUS_AO_REG_BUS_BASE	= IO_PHYS + 0x0002C000,
	GPIO_BASE		= IO_PHYS + 0x0002D000,
	DBGSYS_AO_DEBUG_BASE	= IO_PHYS + 0x00031000,
	APINFRA_IO_AO_DEBUG_BASE	= IO_PHYS + 0x00155000,
	APINFRA_IO_CTRL_AO_BCRM_BASE	= IO_PHYS + 0x00156000,
	APINFRA_IO_CTRL_AO_DEBUG_BASE	= IO_PHYS + 0x00157000,
	DEVAPC_INFRA_SECU_AO_BASE	= IO_PHYS + 0x001C8000,
	DRAMC_CHA_AO_BASE	= IO_PHYS + 0x00230000,
	APINFRA_DRAMC_AO_DEBUG_BASE	= IO_PHYS + 0x002F1000,
	EMI0_BASE		= IO_PHYS + 0x00469000,
	EMI0_MPU_BASE		= IO_PHYS + 0x00468000,
	NEMI_AO_DEBUG_BASE	= IO_PHYS + 0x00416000,
	SEMI_AO_DEBUG_BASE	= IO_PHYS + 0x00516000,
	EMI1_BASE		= IO_PHYS + 0x00569000,
	APINFRA_EMI_AO_DEBUG_BASE	= IO_PHYS + 0x00611000,
	EMI_INFRA_AO_DEBUG_BASE		= IO_PHYS + 0x00644000,
	APINFRA_BIG4_AO_DEBUG_BASE	= IO_PHYS + 0x00691000,
	DPM_PM_SRAM_BASE	= IO_PHYS + 0x00900000,
	DPM_DM_SRAM_BASE	= IO_PHYS + 0x00920000,
	DPM_CFG_BASE		= IO_PHYS + 0x00940000,
	DPM_PM_SRAM_BASE2	= IO_PHYS + 0x00A00000,
	DPM_DM_SRAM_BASE2	= IO_PHYS + 0x00A20000,
	DPM_CFG_BASE2		= IO_PHYS + 0x00A40000,
	IOCFG_RT_BASE		= IO_PHYS + 0x02000000,
	IOCFG_RM1_BASE		= IO_PHYS + 0x02020000,
	IOCFG_RM2_BASE		= IO_PHYS + 0x02040000,
	IOCFG_RB_BASE		= IO_PHYS + 0x02060000,
	I2C5_BASE		= IO_PHYS + 0x020A0000,
	IOCFG_BM1_BASE		= IO_PHYS + 0x02820000,
	IOCFG_BM2_BASE		= IO_PHYS + 0x02840000,
	IOCFG_BM3_BASE		= IO_PHYS + 0x02860000,
	IOCFG_LT_BASE		= IO_PHYS + 0x03000000,
	IOCFG_LM1_BASE		= IO_PHYS + 0x03020000,
	IOCFG_LM2_BASE		= IO_PHYS + 0x03040000,
	EDP_PHY_BASE		= IO_PHYS + 0x030A0000,
	MIPITX0_BASE		= IO_PHYS + 0x030b0000,
	IOCFG_LB1_BASE		= IO_PHYS + 0x030f0000,
	IOCFG_LB2_BASE		= IO_PHYS + 0x03110000,
	I2C0_BASE		= IO_PHYS + 0x03130000,
	I2C3_BASE		= IO_PHYS + 0x03150000,
	I2C6_BASE		= IO_PHYS + 0x03170000,
	I2C10_BASE		= IO_PHYS + 0x03190000,
	EFUSEC_BASE		= IO_PHYS + 0x03260000,
	IOCFG_TM1_BASE		= IO_PHYS + 0x03800000,
	IOCFG_TM2_BASE		= IO_PHYS + 0x03820000,
	IOCFG_TM3_BASE		= IO_PHYS + 0x03860000,
	I2C1_BASE		= IO_PHYS + 0x03930000,
	I2C2_BASE		= IO_PHYS + 0x039B0000,
	I2C4_BASE		= IO_PHYS + 0x03A30000,
	I2C7_BASE		= IO_PHYS + 0x03AB0000,
	I2C8_BASE		= IO_PHYS + 0x03B30000,
	I2C9_BASE		= IO_PHYS + 0x03BB0000,
	IMP_IIC_WRAP_N_BASE	= IO_PHYS + 0x03C30000,
	APINFRA_IO_INTF_AO_DEBUG_BASE	= IO_PHYS + 0x04011000,
	APINFRA_IO_NOC_AO_BCRM_BASE	= IO_PHYS + 0x04012000,
	APINFRA_MEM_INTF_AO_DEBUG_BASE	= IO_PHYS + 0x04031000,
	APINFRA_MEM_NOC_AO_BCRM_BASE	= IO_PHYS + 0x04032000,
	APINFRA_INT_AO_DEBUG_BASE	= IO_PHYS + 0x04051000,
	APINFRA_MMU_AO_DEBUG_BASE	= IO_PHYS + 0x04071000,
	APINFRA_SLB_AO_DEBUG_BASE	= IO_PHYS + 0x04091000,
	APINFRA_MEM_AO_DEBUG_BASE	= IO_PHYS + 0x04116000,
	APINFRA_MEM_CTRL_AO_BCRM_BASE	= IO_PHYS + 0x04124000,
	APINFRA_MEM_CTRL_AO_DEBUG_BASE	= IO_PHYS + 0x04125000,
	APIFRBUS_AO_MEM_REG_BASE	= IO_PHYS + 0x04126000,
	THERM_CTRL_BASE		= IO_PHYS + 0x04414000,
	INFRACFG_AO_SEC_BASE    = IO_PHYS + 0x04461000,
	VOTE_BASE		= IO_PHYS + 0x04500000,
	DBG_TRACKER_BASE	= IO_PHYS + 0x04780000,
	INFRA_TRACKER_BASE	= IO_PHYS + 0x047A0000,
	UART0_BASE		= IO_PHYS + 0x06000000,
	SPI0_BASE		= IO_PHYS + 0x06110000,
	SPI1_BASE		= IO_PHYS + 0x06130000,
	SPI2_BASE		= IO_PHYS + 0x06150000,
	SPI3_BASE		= IO_PHYS + 0x06170000,
	SPI4_BASE		= IO_PHYS + 0x06190000,
	SPI5_BASE		= IO_PHYS + 0x061B0000,
	SPI6_BASE		= IO_PHYS + 0x0619D000,
	SPI7_BASE		= IO_PHYS + 0x061F0000,
	I2C11_BASE		= IO_PHYS + 0x06200000,
	I2C12_BASE		= IO_PHYS + 0x06240000,
	I2C13_BASE		= IO_PHYS + 0x06280000,
	I2C14_BASE		= IO_PHYS + 0x062C0000,
	SFLASH_REG_BASE         = IO_PHYS + 0x06340000,
	I2C0_DMA_BASE		= IO_PHYS + 0x06370000,
	I2C1_DMA_BASE		= IO_PHYS + 0x06380000,
	I2C2_DMA_BASE		= IO_PHYS + 0x06390000,
	I2C3_DMA_BASE		= IO_PHYS + 0x063C0000,
	I2C4_DMA_BASE		= IO_PHYS + 0x063D0000,
	I2C5_DMA_BASE		= IO_PHYS + 0x06400000,
	I2C6_DMA_BASE		= IO_PHYS + 0x06410000,
	I2C7_DMA_BASE		= IO_PHYS + 0x06420000,
	I2C8_DMA_BASE		= IO_PHYS + 0x06450000,
	I2C9_DMA_BASE		= IO_PHYS + 0x06480000,
	I2C10_DMA_BASE		= IO_PHYS + 0x064B0000,
	I2C11_DMA_BASE		= IO_PHYS + 0x064C0000,
	I2C12_DMA_BASE		= IO_PHYS + 0x064D0000,
	I2C13_DMA_BASE		= IO_PHYS + 0x064F0000,
	I2C14_DMA_BASE		= IO_PHYS + 0x06500000,
	PERI_PAR_BCRM_BASE	= IO_PHYS + 0x06610000,
	PERICFG_AO_SEC_BASE	= IO_PHYS + 0x06630000,
	PERICFG_AO_BASE		= IO_PHYS + 0x06640000,
	PERI_PAR_AO_DEBUG_BASE	= IO_PHYS + 0x06680000,
	SSUSB_IPPC_BASE		= IO_PHYS + 0x06703E00,
	SSUSB_SIF_BASE		= IO_PHYS + 0x06730300,
	USB_BUS_BCRM_BASE	= IO_PHYS + 0x06781000,
	UFSHCI_BASE		= IO_PHYS + 0x06810000,
	SSR_TOP_BASE		= IO_PHYS + 0x08000000,
	APINFRA_SSR_AO_DEBUG_BASE	= IO_PHYS + 0x080F1000,
	AUDIO_BASE		= IO_PHYS + 0x0A110000,
	VLP_AO_BASE		= IO_PHYS + 0x0C000000,
	VLP_CFG_BASE		= IO_PHYS + 0x0C001000,
	SPM_BASE		= IO_PHYS + 0x0C004000,
	SPM_PBUS_BASE		= IO_PHYS + 0x0C00D000,
	RGU_BASE		= IO_PHYS + 0x0C010000,
	RC_BASE			= IO_PHYS + 0x0C011000,
	GPT_BASE		= IO_PHYS + 0x0C015000,
	VLP_CKSYS_BASE		= IO_PHYS + 0x0C016000,
	PMIF_SPMI_P_BASE	= IO_PHYS + 0x0C018000,
	PMIF_SPMI_BASE		= IO_PHYS + 0x0C01A000,
	SPMI_MST_BASE		= IO_PHYS + 0x0C01C000,
	SPMI_MST_P_BASE		= IO_PHYS + 0x0C01C800,
	VLP_AO_DEBUG_BASE	= IO_PHYS + 0x0C031000,
	SSPM_SRAM_BASE		= IO_PHYS + 0x0C300000,
	SSPM_CFG_BASE		= IO_PHYS + 0x0C340000,
	SYSTIMER_BASE		= IO_PHYS + 0x0C400000,
	VLP_TRACKER_BASE        = IO_PHYS + 0x0C4E0000,
	VLP_DEVAPC_BASE         = IO_PHYS + 0x0C550A00,
	MMVOTE_MMSYS_CONFIG_BASE	= IO_PHYS + 0x12000000,
	MMVOTE_MMSYS1_CONFIG_BASE	= IO_PHYS + 0x12400000,
	MMVOTE_OVLSYS_CONFIG_BASE	= IO_PHYS + 0x12800000,
	MMVOTE_OVLSYS1_CONFIG_BASE	= IO_PHYS + 0x12C00000,
	MMVOTE_IMGSYS_MAIN_BASE		= IO_PHYS + 0x14000000,
	MMVOTE_IMG_VCORE_D1A_BASE	= IO_PHYS + 0x14780000,
	MMVOTE_VDEC_SOC_GCON_BASE	= IO_PHYS + 0x1600f000,
	MMVOTE_VDEC_GCON_BASE		= IO_PHYS + 0x1602f000,
	MMVOTE_VENC_GCON_BASE		= IO_PHYS + 0x18000000,
	MMVOTE_VENC_GCON_CORE1_BASE	= IO_PHYS + 0x18800000,
	MMVOTE_VENC_GCON_CORE2_BASE	= IO_PHYS + 0x18C00000,
	MMVOTE_CAM_MAIN_R1A_BASE	= IO_PHYS + 0x1A000000,
	MMVOTE_CCU_MAIN_BASE		= IO_PHYS + 0x1C800000,
	MMVOTE_DISP_VDISP_AO_CONFIG_BASE	= IO_PHYS + 0x1E800000,
	MMINFRA_CONFIG		= IO_PHYS + 0x20000000,
	MMINFRA_SEC_CONFIG	= IO_PHYS + 0x20010000,
	MMINFRA_AO_CONFIG	= IO_PHYS + 0x20080000,
	MMINFRA_BUS_HRE_BASE	= IO_PHYS + 0x200A0000,
	MMINFRA_BUS_HRE2_BASE	= IO_PHYS + 0x200B0000,
	MMINFRA1_CONFIG		= IO_PHYS + 0x20A00000,
	MMUP_AO_DEBUG_BASE	= IO_PHYS + 0x21A22000,
	MMVOTE_BASE		= IO_PHYS + 0x21B00000,
	MMPC_BASE		= IO_PHYS + 0x21B50000,
	MMSYS_CONFIG_BASE	= IO_PHYS + 0x22000000,
	MMSYS1_CONFIG_BASE	= IO_PHYS + 0x22400000,
	DSI0_BASE		= IO_PHYS + 0x22490000,
	DISP_DVO0		= IO_PHYS + 0x224C0000,
	OVLSYS_CONFIG_BASE	= IO_PHYS + 0x22800000,
	OVLSYS1_CONFIG_BASE	= IO_PHYS + 0x22C00000,
	DISP_VDISP_AO_CONFIG_BASE	= IO_PHYS + 0x2E800000,
	EDP_CLK_BASE		= IO_PHYS + 0x21B50000,
	EDP_BASE		= IO_PHYS + 0x2EC40000,
	MFG_TOP_CFG_BASE		= MFGSYS_BASE + 0x08500000,
	MFG_GPUEB_BASE			= MFGSYS_BASE + 0x0B000000,
	MFG_GPUEB_RPC_BASE		= MFGSYS_BASE + 0x0B800000,
	MFG_PLL_PLL_CTRL_BASE		= MFGSYS_BASE + 0x0B810000,
	MFG_PLL_SC0_PLL_CTRL_BASE	= MFGSYS_BASE + 0x0B810400,
	MFG_PLL_SC1_PLL_CTRL_BASE	= MFGSYS_BASE + 0x0B810800,
	MFG_VCORE_AO_CFG_BASE		= MFGSYS_BASE + 0x0B860000,
};

#endif
