/* SPDX-License-Identifier: GPL-2.0-only */

#include <gpio.h>
#include <soc/meminit.h>
#include <soc/romstage.h>
#include <string.h>
#include <variants.h>
#include <types.h>

/* Early pad configuration in bootblock. */
const struct pad_config early_gpio_table[] = {
	/* GPIO_64:	UART2_TXD	*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_64, UP_20K, DEEP, NF1, HIZCRx1, DISPUPD),
	/* GPIO_65:	UART2_RXD	*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_65, UP_20K, DEEP, NF1, TxLASTRxE, DISPUPD),
};

const struct pad_config *variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}

/* Pad configuration in ramstage. */
const struct pad_config gpio_table[] = {
	/* ------- GPIO Group NorthWest ------- */
	/* GPIO_0:	XDP_H_TCK		*/
	PAD_NC(GPIO_0, DN_20K),
	/* GPIO_1:	XDP_H_TRST_N		*/
	PAD_NC(GPIO_1, DN_20K),
	/* GPIO_2:	XDP_H_TMS		*/
	PAD_NC(GPIO_2, DN_20K),
	/* GPIO_3:	XDP_H_TDI		*/
	PAD_NC(GPIO_3, DN_20K),
	/* GPIO_4:	XDP_H_TDO		*/
	PAD_NC(GPIO_4, DN_20K),
	/* GPIO_5:	Not Connected		*/
	PAD_NC(GPIO_5, DN_20K),
	/* GPIO_6:	XDP_H_PREQ_N		*/
	PAD_NC(GPIO_6, DN_20K),
	/* GPIO_7:	XDP_H_PRDY_N		*/
	PAD_NC(GPIO_7, DN_20K),
	/* GPIO_8:	Not Connected		*/
	PAD_NC(GPIO_8, DN_20K),
	/* GPIO_9:	Not Connected		*/
	PAD_NC(GPIO_9, DN_20K),
	/* GPIO_10:	Not Connected		*/
	PAD_NC(GPIO_10, DN_20K),
	/* GPIO_11:	Not Connected		*/
	PAD_NC(GPIO_11, DN_20K),
	/* GPIO_12:	Not Connected		*/
	PAD_NC(GPIO_12, DN_20K),
	/* GPIO_13:	ACCEL1_INT		*/
	PAD_NC(GPIO_13, DN_20K),
	/* GPIO_14:	ACCEL2_INT		*/
	PAD_NC(GPIO_14, DN_20K),
	/* GPIO_15:	Not Connected		*/
	PAD_NC(GPIO_15, DN_20K),
	/* GPIO_16:	SATA_DEVSLP		*/
	PAD_NC(GPIO_16, NONE),
	/* GPIO_17:	Not Connected		*/
	PAD_NC(GPIO_17, DN_20K),
	/* GPIO_18:	Not Connected		*/
	PAD_NC(GPIO_18, DN_20K),
	/* GPIO_19:	PMIC_IRQ#		*/
	PAD_CFG_GPI_APIC_IOS(GPIO_19, UP_20K, DEEP, EDGE_SINGLE, NONE, TxDRxE, SAME),
	/* GPIO_20:	Not Connected		*/
	PAD_NC(GPIO_20, DN_20K),
	/* GPIO_21:	WLAN_WWAN_COEX3		*/
	PAD_NC(GPIO_21, DN_20K),
	/* GPIO_22:	WLAN_WWAN_COEX3		*/
	PAD_NC(GPIO_22, DN_20K),
	/* GPIO_23:	WLAN_WWAN_COEX3		*/
	PAD_NC(GPIO_23, DN_20K),
	/* GPIO_24:	Not Connected		*/
	PAD_NC(GPIO_24, DN_20K),
	/* GPIO_25:	Not Connected		*/
	PAD_NC(GPIO_25, DN_20K),
	/* GPIO_26:	TPNL_INT#		*/
	PAD_NC(GPIO_26, DN_20K),
	/* GPIO_27:	eMMC Strap		*/
	PAD_NC(GPIO_27, NONE),
	/* GPIO_28:	SPI Strap		*/
	PAD_NC(GPIO_28, NONE),
	/* GPIO_29:	Not Connected		*/
	PAD_NC(GPIO_29, DN_20K),
	/* GPIO_30:	Not Connected		*/
	PAD_NC(GPIO_30, DN_20K),
	/* GPIO_31:	Not Connected		*/
	PAD_NC(GPIO_31, DN_20K),
	/* GPIO_32:	Not Connected		*/
	PAD_NC(GPIO_32, DN_20K),
	/* GPIO_33:	BT_ON_SOC		*/
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_33, 1, DEEP, UP_20K, TxLASTRxE, DISPUPD),
	/* GPIO_34:	WIFI_ON_SOC		*/
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_34, 1, DEEP, NONE, IGNORE, DISPUPD),
	/* GPIO_35:	Not Connected		*/
	PAD_NC(GPIO_35, DN_20K),
	/* GPIO_36:	Not Connected		*/
	PAD_NC(GPIO_36, DN_20K),
	/* GPIO_37:	Not Connected		*/
	PAD_NC(GPIO_37, DN_20K),
	/* GPIO_38:	WAKE_SCI#		*/
	PAD_CFG_GPI_SCI_IOS(GPIO_38, UP_20K, DEEP, EDGE_SINGLE, INVERT, IGNORE, SAME),
	/* GPIO_39:	FP_RST#			*/
	PAD_NC(GPIO_39, DN_20K),
	/* GPIO_40:	Not Connected		*/
	PAD_NC(GPIO_40, DN_20K),
	/* GPIO_41:	Not Connected		*/
	PAD_NC(GPIO_41, DN_20K),
	/* GPIO_42:	SECURITY_FLASH		*/
	PAD_NC(GPIO_42, DN_20K),
	/* GPIO_43:	GPIO_43			*/
	PAD_NC(GPIO_43, DN_20K),
	/* GPIO_44:	USB OC0			*/
	PAD_NC(GPIO_44, DN_20K),
	/* GPIO_45:	USB_OC1			*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_45, UP_20K, DEEP, NF1, TxDRxE, ENPU),
	/* GPIO_46:	Not Connected		*/
	PAD_NC(GPIO_46, DN_20K),
	/* GPIO_47:	Not Connected		*/
	PAD_NC(GPIO_47, DN_20K),
	/* GPIO_48:	PMC_I2C_SDA		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_48, UP_1K, DEEP, NF1),
	/* GPIO_49:	PMC_I2C_SCL		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_49, UP_1K, DEEP, NF1),
	/* GPIO_50:	I2C_0 SDA		*/
	PAD_NC(GPIO_50, DN_20K),
	/* GPIO_51:	I2C_0 SDL		*/
	PAD_NC(GPIO_51, DN_20K),
	/* GPIO_52:	I2C_1 SDA		*/
	PAD_NC(GPIO_52, DN_20K),
	/* GPIO_53:	I2C_1 SDL		*/
	PAD_NC(GPIO_53, DN_20K),
	/* GPIO_54:	I2C_2 SDA		*/
	PAD_NC(GPIO_54, DN_20K),
	/* GPIO_55:	I2C_2 SDL		*/
	PAD_NC(GPIO_55, DN_20K),
	/* GPIO_56:	I2C_3 SDA		*/
	PAD_NC(GPIO_56, DN_20K),
	/* GPIO_57:	I2C_3 SDL		*/
	PAD_NC(GPIO_57, DN_20K),
	/* GPIO_58:	I2C4_SDA		*/
	PAD_NC(GPIO_58, DN_20K),
	/* GPIO_59:	I2C4_SCL		*/
	PAD_NC(GPIO_59, DN_20K),
	/* GPIO_60:	UART0 RXD			*/
	PAD_NC(GPIO_60, DN_20K),
	/* GPIO_61:	UART0 TXD		*/
	PAD_NC(GPIO_61, DN_20K),
	/* GPIO_62:	UART0 RTS		*/
	PAD_NC(GPIO_62, DN_20K),
	/* GPIO_63:	UART0 CTS		*/
	PAD_NC(GPIO_63, DN_20K),
	/* GPIO_66:	GPIO_66			*/
	PAD_NC(GPIO_66, DN_20K),
	/* GPIO_67:	SMC_EXTSMI#		*/
	PAD_CFG_GPI_SMI_IOS(GPIO_67, UP_20K, DEEP, EDGE_SINGLE, NONE, IGNORE, SAME),
	/* GPIO_68:	Not Connected		*/
	PAD_NC(GPIO_68, DN_20K),
	/* GPIO_69:	Not Connected		*/
	PAD_NC(GPIO_69, DN_20K),
	/* GPIO_70:	Not Connected		*/
	PAD_NC(GPIO_70, DN_20K),
	/* GPIO_71:	Not Connected		*/
	PAD_NC(GPIO_71, DN_20K),
	/* GPIO_72:	Not Connected		*/
	PAD_NC(GPIO_72, DN_20K),
	/* GPIO_73:	Not Connected		*/
	PAD_NC(GPIO_73, DN_20K),
	/* GPIO_74:	PMIC_THERMTRIP#		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_74, UP_20K, DEEP, NF1, TxDRxE, ENPU),
	/* GPIO_75:	PROCHOT#_CPU		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_75, NONE, DEEP, NF1, TxDRxE, DISPUPD),
	/* GPIO_211:	EMMC_RST#_CPU		*/
	PAD_NC(GPIO_211, UP_20K),
	/* GPIO_212:	BRD_ID_0		*/
	PAD_NC(GPIO_212, DN_20K),
	/* GPIO_213:	BRD_ID_1		*/
	PAD_NC(GPIO_213, DN_20K),
	/* GPIO_214:	BRD_ID_2		*/
	PAD_NC(GPIO_214, DN_20K),

	/* ------- GPIO Group North ------- */
	/* GPIO_76:	Not Connected		*/
	PAD_NC(GPIO_76, DN_20K),
	/* GPIO_77:	Not Connected		*/
	PAD_NC(GPIO_77, DN_20K),
	/* GPIO_78:	Not Connected		*/
	PAD_NC(GPIO_78, DN_20K),
	/* GPIO_79:	GPIO_79			*/
	PAD_NC(GPIO_79, DN_20K),
	/* GPIO_80:	FP_FS0			*/
	PAD_NC(GPIO_80, DN_20K),
	/* GPIO_81:	GPIO_81			*/
	PAD_NC(GPIO_81, DN_20K),
	/* GPIO_82:	FP_MISO			*/
	PAD_NC(GPIO_82, DN_20K),
	/* GPIO_83:	LPC 1.8V/3.3V Select	*/
	PAD_NC(GPIO_83, DN_20K),
	/* GPIO_84:	Allow SPI Boot			*/
	PAD_NC(GPIO_84, UP_20K),
	/* GPIO_85:	Not Connected		*/
	PAD_NC(GPIO_85, DN_20K),
	/* GPIO_86:	GPIO_86			*/
	PAD_NC(GPIO_86, DN_20K),
	/* GPIO_87:	Not Connected		*/
	PAD_NC(GPIO_87, DN_20K),
	/* GPIO_88:	Not Connected		*/
	PAD_NC(GPIO_88, DN_20K),
	/* GPIO_89:	Not Connected		*/
	PAD_NC(GPIO_89, DN_20K),
	/* GPIO_90:	FLASH_SPI_CS0_N		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_90, NATIVE, DEEP, NF1),
	/* GPIO_91:	Not Connected		*/
	PAD_NC(GPIO_91, DN_20K),
	/* GPIO_92:	FLASH_SPI_MOSI		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_92, DN_20K, DEEP, NF1),
	/* GPIO_93:	FLASH_SPI_MISO		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_93, NATIVE, DEEP, NF1),
	/* GPIO_94:	FLASH_SPI_IO2		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_94, NATIVE, DEEP, NF1),
	/* GPIO_95:	FLASH_SPI_IO3		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_95, NATIVE, DEEP, NF1),
	/* GPIO_96:	FLASH_SPI_CLK		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_96, NATIVE, DEEP, NF1),
	/* GPIO_98:	PMU_PLT_RST#_CPU	*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_98, NONE, DEEP, NF1),
	/* GPIO_99:	PM_PWRBTN#		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_99, UP_20K, DEEP, NF1),
	/* GPIO_100:	SLP_S0#			*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_100, NONE, DEEP, NF1),
	/* GPIO_101:	SLP_S3#			*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_101, NONE, DEEP, NF1),
	/* GPIO_102:	SLP_S4#			*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_102, NONE, DEEP, NF1),
	/* GPIO_103:	SUSPWRDNACK		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_103, NONE, DEEP, NF1),
	/* GPIO_104:	Not Connected		*/
	PAD_NC(GPIO_104, UP_20K),
	/* GPIO_105:	GPIO_105		*/
	PAD_NC(GPIO_105, UP_20K),
	/* GPIO_106:	PMU_BATLOW#		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_106, UP_20K, DEEP, NF1),
	/* GPIO_107:	PMU_RSTBTN#		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_107, UP_20K, DEEP, NF1),
	/* GPIO_108:	SUS_CLK			*/
	PAD_NC(GPIO_108, NONE),
	/* GPIO_109:	PMU_SUS_STAT#		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_109, NONE, DEEP, NF1),
	/* GPIO_110:	I2C_5 SDA		*/
	PAD_NC(GPIO_110, DN_20K),
	/* GPIO_111:	I2C_5 SDL		*/
	PAD_NC(GPIO_111, DN_20K),
	/* GPIO_112:	I2C_6 SDA		*/
	PAD_NC(GPIO_112, DN_20K),
	/* GPIO_113:	I2C_6 SCL		*/
	PAD_NC(GPIO_113, DN_20K),
	/* GPIO_114:	I2C_7 SDA		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_114, NONE, DEEP, NF1, HIZCRx1, DISPUPD),
	/* GPIO_115:	I2C_7 SCL		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_115, NONE, DEEP, NF1, HIZCRx1, DISPUPD),
	/* GPIO_116:	WLAN_PCIE_WAKE#		*/
	PAD_NC(GPIO_116, DN_20K),
	/* GPIO_117:	Not Connected		*/
	PAD_NC(GPIO_117, DN_20K),
	/* GPIO_118:	Not Connected		*/
	PAD_NC(GPIO_118, DN_20K),
	/* GPIO_119:	Not Connected		*/
	PAD_NC(GPIO_119, DN_20K),
	/* GPIO_120:	WLAN_CLK_REQ#		*/
	PAD_NC(GPIO_120, DN_20K),
	/* GPIO_121:	Not Connected		*/
	PAD_NC(GPIO_121, DN_20K),
	/* GPIO_122:	Not Connected		*/
	PAD_NC(GPIO_122, DN_20K),
	/* GPIO_123:	Not Connected		*/
	PAD_NC(GPIO_123, DN_20K),
	/* GPIO_124:	DDI0_DDC_SDA		*/
	PAD_CFG_NF_IOSSTATE(GPIO_124, UP_20K, DEEP, NF1, HIZCRx0),
	/* GPIO_125:	DDI0_DDC_SCL		*/
	PAD_CFG_NF_IOSSTATE(GPIO_125, UP_20K, DEEP, NF1, HIZCRx0),
	/* GPIO_126:	Not Connected		*/
	PAD_NC(GPIO_126, DN_20K),
	/* GPIO_127:	Not Connected		*/
	PAD_NC(GPIO_127, DN_20K),
	/* GPIO_128:	EDP_VDD_EN		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_128, NONE, DEEP, NF1, Tx0RxDCRx0, DISPUPD),
	/* GPIO_129:	EDP_BKLT_EN		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_129, NONE, DEEP, NF1, Tx0RxDCRx0, DISPUPD),
	/* GPIO_130:	eDP_BKLCTL_3P3		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_130, NONE, DEEP, NF1, Tx0RxDCRx0, DISPUPD),
	/* GPIO_131:	HDMI_HPD_CPU		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_131, NONE, DEEP, NF1, HIZCRx1, DISPUPD),
	/* GPIO_132:	DDI1_HPD_SOC_N		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_132, NONE, DEEP, NF1, HIZCRx1, DISPUPD),
	/* GPIO_133:	EDP_HPD_CPU		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_133, NONE, DEEP, NF1, HIZCRx1, DISPUPD),
	/* GPIO_134:	Touch_Panel_RST#	*/
	PAD_NC(GPIO_134, DN_20K),
	/* GPIO_135:	TCH_HOME_KEY		*/
	PAD_NC(GPIO_135, DN_20K),
	/* GPIO_136:	Not Connected		*/
	PAD_NC(GPIO_136, DN_20K),
	/* GPIO_137:	Not Connected		*/
	PAD_NC(GPIO_137, DN_20K),
	/* GPIO_138:	Not Connected		*/
	PAD_NC(GPIO_138, DN_20K),
	/* GPIO_139:	Not Connected		*/
	PAD_NC(GPIO_139, DN_20K),
	/* GPIO_140:	Not Connected		*/
	PAD_NC(GPIO_140, DN_20K),
	/* GPIO_141:	Not Connected		*/
	PAD_NC(GPIO_141, DN_20K),
	/* GPIO_142:	PMU_WAKE#		*/
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_142, 1, DEEP, UP_20K, IGNORE, SAME),
	/* GPIO_143:	Not Connected		*/
	PAD_NC(GPIO_143, DN_20K),
	/* GPIO_144:	Not Connected		*/
	PAD_NC(GPIO_144, DN_20K),
	/* GPIO_145:	Not Connected		*/
	PAD_NC(GPIO_145, DN_20K),
	/* GPIO_146:	Not Connected		*/
	PAD_NC(GPIO_146, DN_20K),
	/* GPIO_147:	LPC_SERIRQ		*/
	_PAD_CFG_STRUCT(GPIO_147, PAD_FUNC(NF1) | PAD_RESET(DEEP) | PAD_TRIG(OFF) |
		PAD_BUF(TX_RX_DISABLE) | (1 << 1), PAD_PULL(UP_20K) | PAD_IOSTERM(ENPU)),
	/* GPIO_148:	LPC_CLK0		*/
	_PAD_CFG_STRUCT(GPIO_148, PAD_FUNC(NF1) | PAD_RESET(DEEP) | PAD_TRIG(OFF) |
		PAD_BUF(TX_RX_DISABLE), PAD_IOSSTATE(HIZCRx1)),
	/* GPIO_149:	LPC_CLK_DBG_CPU		*/
	_PAD_CFG_STRUCT(GPIO_149, PAD_FUNC(NF1) | PAD_RESET(DEEP) | PAD_TRIG(OFF) |
		PAD_BUF(TX_RX_DISABLE), PAD_IOSSTATE(HIZCRx1)),
	/* GPIO_150:	LPC_AD0			*/
	_PAD_CFG_STRUCT(GPIO_150, PAD_FUNC(NF1) | PAD_RESET(DEEP) | PAD_TRIG(OFF) |
		PAD_BUF(TX_RX_DISABLE) | (1 << 1), PAD_PULL(UP_20K) | PAD_IOSSTATE(HIZCRx1) |
		PAD_IOSTERM(ENPU)),
	/* GPIO_151:	LPC_AD1			*/
	_PAD_CFG_STRUCT(GPIO_151, PAD_FUNC(NF1) | PAD_RESET(DEEP) | PAD_TRIG(OFF) |
		PAD_BUF(TX_RX_DISABLE) | (1 << 1), PAD_PULL(UP_20K) | PAD_IOSSTATE(HIZCRx1) |
		PAD_IOSTERM(ENPU)),
	/* GPIO_152:	LPC_AD2			*/
	_PAD_CFG_STRUCT(GPIO_152, PAD_FUNC(NF1) | PAD_RESET(DEEP) | PAD_TRIG(OFF) |
		PAD_BUF(TX_RX_DISABLE) | (1 << 1), PAD_PULL(UP_20K) | PAD_IOSSTATE(HIZCRx1) |
		PAD_IOSTERM(ENPU)),
	/* GPIO_153:	LPC_AD3			*/
	_PAD_CFG_STRUCT(GPIO_153, PAD_FUNC(NF1) | PAD_RESET(DEEP) | PAD_TRIG(OFF) |
		PAD_BUF(TX_RX_DISABLE) | (1 << 1), PAD_PULL(UP_20K) | PAD_IOSSTATE(HIZCRx1) |
		PAD_IOSTERM(ENPU)),
	/* GPIO_154:	LPC_CLKRUN#		*/
	_PAD_CFG_STRUCT(GPIO_154, PAD_FUNC(NF1) | PAD_RESET(DEEP) | PAD_TRIG(OFF) |
		PAD_BUF(TX_RX_DISABLE) | (1 << 1), PAD_PULL(UP_20K)),
	/* GPIO_155:	LPC_FRAME#		*/
	_PAD_CFG_STRUCT(GPIO_155, PAD_FUNC(NF1) | PAD_RESET(DEEP) | PAD_TRIG(OFF) |
		PAD_BUF(TX_RX_DISABLE), PAD_PULL(UP_20K) | PAD_IOSSTATE(HIZCRx1) |
		PAD_IOSTERM(ENPU)),

	/* ----- GPIO Group Audio ----- */
	/* GPIO_156:	FP_INT#			*/
	PAD_NC(GPIO_156, DN_20K),
	/* GPIO_157:	Not Connected		*/
	PAD_NC(GPIO_157, DN_20K),
	/* GPIO_158:	Not Connected		*/
	PAD_NC(GPIO_158, DN_20K),
	/* GPIO_159:	Not Connected		*/
	PAD_NC(GPIO_159, DN_20K),
	/* GPIO_160:	Not Connected		*/
	PAD_NC(GPIO_160, DN_20K),
	/* GPIO_161:	GPIO_161		*/
	PAD_NC(GPIO_161, DN_20K),
	/* GPIO_162:	Not Connected		*/
	PAD_NC(GPIO_162, DN_20K),
	/* GPIO_163:	GPIO_163		*/
	PAD_NC(GPIO_163, DN_20K),
	/* GPIO_164:	GPIO_164		*/
	PAD_NC(GPIO_164, DN_20K),
	/* GPIO_165:	GPIO_165		*/
	PAD_NC(GPIO_165, DN_20K),
	/* GPIO_166:	HDA_BCLK_CPU_R		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_166, NONE, DEEP, NF1, HIZCRx0, DISPUPD),
	/* GPIO_167:	HDA_SYNC_CPU_R		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_167, NONE, DEEP, NF1, HIZCRx0, DISPUPD),
	/* GPIO_168:	GPIO_168		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_168, NONE, DEEP, NF1, HIZCRx0, DISPUPD),
	/* GPIO_169:	HDA_SDATAOUT		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_169, NONE, DEEP, NF1, HIZCRx0, DISPUPD),
	/* GPIO_170:	HDA_RST#		*/
	PAD_CFG_NF_IOSSTATE_IOSTERM(GPIO_170, NONE, DEEP, NF1, HIZCRx0, DISPUPD),
	/* GPIO_171:	Not Connected		*/
	PAD_NC(GPIO_171, DN_20K),
	/* GPIO_172:	Not Connected		*/
	PAD_NC(GPIO_172, DN_20K),
	/* GPIO_173:	Not Connected		*/
	PAD_NC(GPIO_173, DN_20K),
	/* GPIO_174:	VDD2 1.20V / 1.24V Mode	*/
	PAD_CFG_GPO_IOSSTATE_IOSTERM(GPIO_174, 1, DEEP, DN_20K, TxLASTRxE, ENPU),
	/* GPIO_175:	eSPI / LPC Mode		*/
	PAD_NC(GPIO_175, NONE),

	/* ----- GPIO Group SCC ----- */
	/* GPIO_176:	Not Connected		*/
	PAD_NC(GPIO_176, DN_20K),
	/* GPIO_177:	TP_INT#			*/
	PAD_CFG_GPI_GPIO_DRIVER(GPIO_177, NONE, PLTRST),
	/* GPIO_178:	Not Connected		*/
	PAD_NC(GPIO_178, DN_20K),
	/* GPIO_187:	Not Connected		*/
	PAD_NC(GPIO_187, DN_20K),
	/* GPIO_179:	Not Connected		*/
	PAD_NC(GPIO_179, DN_20K),
	/* GPIO_181:	Not Connected		*/
	PAD_NC(GPIO_181, DN_20K),
	/* GPIO_182:	Not Connected		*/
	PAD_NC(GPIO_182, DN_20K),
	/* GPIO_183:	Not Connected		*/
	PAD_NC(GPIO_183, DN_20K),
	/* GPIO_184:	Not Connected		*/
	PAD_NC(GPIO_184, DN_20K),
	/* GPIO_185:	WLAN_RST_N_R		*/
	PAD_NC(GPIO_185, DN_20K),
	/* GPIO_186:	Not Connected		*/
	PAD_NC(GPIO_186, DN_20K),
	/* GPIO_188:	Not Connected		*/
	PAD_NC(GPIO_188, DN_20K),
	/* GPIO_210:	Not Connected		*/
	PAD_NC(GPIO_210, DN_20K),
	/* GPIO_189:	Not Connected		*/
	PAD_NC(GPIO_189, DN_20K),
	/* GPIO_190:	Not Connected		*/
	PAD_NC(GPIO_190, DN_20K),
	/* GPIO_191:	eSPI Flash Sharing	*/
	PAD_NC(GPIO_191, NONE),
	/* GPIO_192:	CNVI_BRI_RSP		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_192, UP_20K, DEEP, NF1),
	/* GPIO_193:	CNVI_RGI_DT		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_193, NONE, DEEP, NF1),
	/* GPIO_194:	GPIO_194		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_194, UP_20K, DEEP, NF1),
	/* GPIO_195:	CNVI_RF_RESET_N		*/
	PAD_CFG_NF_IOSTANDBY_IGNORE(GPIO_195, NONE, DEEP, NF1),
	/* GPIO_198:	EMMC_CLK		*/
	PAD_NC(GPIO_198, DN_20K),
	/* GPIO_200:	EMMC_DATA_0		*/
	PAD_NC(GPIO_200, DN_20K),
	/* GPIO_201:	EMMC_DATA_1		*/
	PAD_NC(GPIO_201, DN_20K),
	/* GPIO_202:	EMMC_DATA_2		*/
	PAD_NC(GPIO_202, DN_20K),
	/* GPIO_203:	EMMC_DATA_3		*/
	PAD_NC(GPIO_203, DN_20K),
	/* GPIO_204:	EMMC_DATA_4		*/
	PAD_NC(GPIO_204, DN_20K),
	/* GPIO_205:	EMMC_DATA_5		*/
	PAD_NC(GPIO_205, DN_20K),
	/* GPIO_206:	EMMC_DATA_6		*/
	PAD_NC(GPIO_206, DN_20K),
	/* GPIO_207:	EMMC_DATA_7		*/
	PAD_NC(GPIO_207, DN_20K),
	/* GPIO_208:	EMMC_CMD		*/
	PAD_NC(GPIO_208, DN_20K),
	/* GPIO_209:	EMMC_STROBE		*/
	PAD_NC(GPIO_209, DN_20K),
};

const struct pad_config *variant_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(gpio_table);
	return gpio_table;
}
