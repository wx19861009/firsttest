#ifndef BOARD_CONFIG_H
#define BOARD_CONFIG_H

/*
 *  板级配置选择，需要删去app_config.h中前面跟此头文件重复的宏定义，不然此头文件宏定义无效
 */

#define __FLASH_SIZE__    (4 * 1024 * 1024)
#define __SDRAM_SIZE__    (8 * 1024 * 1024)
#define TCFG_SD0_ENABLE                    1
#define TCFG_ADKEY_ENABLE                  1         //AD按键

#define TCFG_IOKEY_ENABLE				   1		 //GPIO按键
#if TCFG_IOKEY_ENABLE
#define MULT_KEY_ENABLE					   1		 //支持同时按多个按键
#endif


#define TCFG_SD_PORTS                      'D'			//SD0/SD1的ABCD组(默认为开发板SD0-D),注意:IO占用问题
#define TCFG_SD_DAT_WIDTH                  1		  // 1:单线模式, 4:四线模式
#define TCFG_SD_DET_MODE                  SD_CMD_DECT // SD_IO_DECT	//检测模式:命令检测，时钟检测，IO检测
#define TCFG_SD_DET_IO                     -1			//SD_DET_MODE为SD_IO_DECT时有效
#define TCFG_SD_DET_IO_LEVEL               0			//IO检卡上线的电平(0/1),SD_DET_MODE为SD_IO_DECT时有效
#define TCFG_SD_CLK                        24000000		//SD时钟

#define CONFIG_ASR_CLOUD_ADC_CHANNEL        3		//云端识别mic通道
#define CONFIG_VOICE_NET_CFG_ADC_CHANNEL    3		//声波配网mic通道
#define CONFIG_AISP_MIC0_ADC_CHANNEL        3		//本地唤醒左mic通道
#define CONFIG_AISP_MIC1_ADC_CHANNEL        3		//本地唤醒右mic通道
#define CONFIG_AISP_LINEIN_ADC_CHANNEL      3		//本地唤醒LINEIN回采DAC通道
#define CONFIG_REVERB_ADC_CHANNEL           3		//混响mic通道
#define CONFIG_PHONE_CALL_ADC_CHANNEL       3		//通话mic通道
#define CONFIG_UAC_MIC_ADC_CHANNEL          1		//UAC mic通道
#define CONFIG_AISP_MIC_ADC_GAIN            80		//本地唤醒mic增益
#define CONFIG_AISP_LINEIN_ADC_GAIN         60		//本地唤醒LINEIN增益

#define CONFIG_AUDIO_ENC_SAMPLE_SOURCE      AUDIO_ENC_SAMPLE_SOURCE_MIC




//sjz add------------------------------------------------------

//选择4G模块
//#define __USE_QUECTEL_EC600N__
//#define __USE_MEIG_SLM328__
//#define __USE_UNIONMAN_UMA50X__

#ifdef __USE_UNIONMAN_UMA50X__
//支持实体卡和虚拟卡切换
#define __SUPPORT_SIM_CHANGE__
#ifdef __SUPPORT_SIM_CHANGE__
//使用虚拟卡
#define __USE_M4G_VSIM__
#endif
#endif

#define NC  -1


//一机一码
//#define PINCODE_BIND_FUNCION

#define USBIC_BOARD_CONFIG		0//有USBIC,填0为不接USB IC

#define ADC_KEY_IO			IO_PORTB_01
#define ADC_KEY_CH			AD_CH_PB01

#define ADC_KEY_IO1			-1//IO_PORTC_01
#define ADC_KEY_CH1			-1//AD_CH_PC01

#define ADC_KEY_IO2			-1//IO_PORTC_01
#define ADC_KEY_CH2			-1//AD_CH_PC01


#if (ADC_KEY_IO != -1 && ADC_KEY_IO1 != -1&&ADC_KEY_IO2!= -1)
#define ADC_KEY_NUM				3
#elif ((ADC_KEY_IO != -1 && ADC_KEY_IO1 != -1)||(ADC_KEY_IO != -1 && ADC_KEY_IO2 != -1)||(ADC_KEY_IO1 != -1 && ADC_KEY_IO2 != -1))
#define ADC_KEY_NUM				2
#else
#define ADC_KEY_NUM				1
#endif
#define LCD_BUSY_PIN    		-1
#define LCD_BL_IO				-1

//charge led
#define CHARGE_LED_RED          NC
#define CHARGE_LED_R_ACT        1
#define CHARGE_LED_GREEN        NC
#define CHARGE_LED_G_ACT        0
#define INDICATION_LED_RED_GPIO			IO_PORTC_01//PB_5
#define INDICATION_LED_RED_ACT			0
#define INDICATION_LED_GREEN_GPIO		IO_PORTC_02//PB_6
#define INDICATION_LED_GREEN_ACT		0

#define CHARGE_LED_YELLOW       IO_PORTA_04//IO_PORTA_01
#define CHARGE_LED_Y_ACT        0

//oid led
#define OID_LED_GPIO            IO_PORTA_03
#define OID_LED_ACT             0

//wifi led
#define WIFI_LED_GPIO           NC//IO_PORTA_02
#define WIFI_LED_ACT            0
//wifi download process
#define PRO_LED_GPIO            NC
#define PRO_LED_ACT             1


#define USB_DET_IO				IO_PORTC_00
#define CHARGE_DET_IO			IO_PORTC_06
#define CHARGE_EN_IO			-1//IO_PORTC_06//-1
#define TEST_CHECK_IO1			-1//IO_PORTA_08//-1//IO_PORTA_01
#define TEST_CHECK_IO2			-1
#define TEST_CHECK_IO3			-1
#define ADC_CHANGEVOL_IO		IO_PORTA_05//IO_PORTC_05
#define TOUCH_INT				-1	//touch int
#define TOUCH_EVT				EVENT_PH7
#define TOUCH_RST				-1	//touch reset
#define AMP_EN_IO				IO_PORTH_09//amplifier
#define HP_DET_IO				-1 //headphone detect
#define HP_PA_IO				-1 //headphone pa
//耳机是否使用USB接口
#define HP_USE_USB				0
//oid pen
#define OID_MASTR_SDA			IO_PORTA_07
#define OID_MASTR_SCL			IO_PORTA_06
//4g module
#define M4G_POWER_IO			-1
#define M4G_ONOFF_IO			-1
#define M4G_RST_IO				-1
#define M4G_MAIN_RI_IO			-1
#define M4G_MAIN_DTR_IO			-1
#define M4G_AP_RDY_IO			-1
#define M4G_EN_1_8V_IO			-1
#define M4G_CTS_IO				-1
#define M4G_RTS_IO				-1
#define M4G_CHK_OFF				-1
//休眠唤醒脚状态
#ifdef __USE_UNIONMAN_UMA50X__
#define M4G_SLEEP_LEVEL			0
#else
#define M4G_SLEEP_LEVEL			1
#endif
//external rtc
#define EXT_RTC_CLK				-1//IO_PORTA_07
#define EXT_RTC_SDA				-1//IO_PORTA_08

//TEMPERATURE
//#define CHARGE_CONTROL_IO   IO_PORTC_06   //充电控制IO:高电平充电 低电平不充电
#define TEMPERATURE_ADC_IO  -1//IO_PORTA_10   //温度检测

#define USBIC_IO			-1//IO_PORTC_07
//sjz add------------------------------------------------------

//*********************************************************************************//
//                        SD 配置（暂只支持打开一个SD外设）                        //
//*********************************************************************************//
//SD0 	cmd,  clk,  data0, data1, data2, data3
//A     PB6   PB7   PB5    PB5    PB3    PB2
//B     PA7   PA8   PA9    PA10   PA5    PA6
//C     PH1   PH2   PH0    PH3    PH4    PH5
//D     PC9   PC10  PC8    PC7    PC6    PC5

//SD1 	cmd,  clk,  data0, data1, data2, data3
//A     PH6   PH7   PH5    PH4    PH3    PH2
//B     PC0   PC1   PC2    PC3    PC4    PC5


#endif

