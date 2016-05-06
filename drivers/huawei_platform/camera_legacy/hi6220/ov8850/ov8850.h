/*
 *  OV8850 camera driver head file
 *
 *  CopyRight (C) Hisilicon Co., Ltd.
 *	Author :
 *  Version:  1.2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _OV8850_H
#define _OV8850_H

#include "../isp/k3_isp_io.h"

#define OV8850REG_SOFTWARE_RESET	0x0103

/* High 4 bits are clock, low 4 bits are reset */
#define OV8850REG_CLKRST0		0x3016
#define OV8850REG_CLKRST1		0x3017
#define OV8850REG_CLKRST2		0x3018

#define OV8850REG_PLL1_MULTIPLIER	0x30b3
#define OV8850REG_PLL1_PREDIV		0x30b4
#define OV8850REG_PLL1_OP_PIX_DIV	0x30b5
#define OV8850REG_PLL1_OS_SYS_DIV	0x30b6

#define OV8850REG_PLL2_PREDIV		0x3090
#define OV8850REG_PLL2_MULTIPLIER	0x3091
#define OV8850REG_PLL2_DIVS			0x3092
#define OV8850REG_PLL2_SELD5		0x3093

#define OV8850REG_PLL3_PREDIV		0x3098
#define OV8850REG_PLL3_MULT1		0x309c
#define OV8850REG_PLL3_MULT2		0x3099
#define OV8850REG_PLL3_DIVS		0x309a
#define OV8850REG_PLL3_DIV		0x309b

#define OV8850REG_WIDTH			0x3808
#define OV8850REG_HEIGHT		0x380a

//#define OV8850REG_HTS			0x380c
//#define OV8850REG_VTS			0x380e

#define OV8850REG_X_ADDR_START		0x3800
#define OV8850REG_Y_ADDR_START		0x3802
#define OV8850REG_X_ADDR_END		0x3804
#define OV8850REG_Y_ADDR_END		0x3806

#define OV8850REG_H_OFFSET		0x3810
#define OV8850REG_V_OFFSET		0x3812

/*
 * bit[7:4]: odd inc
 * bit[3:0]: even inc
 */
#define OV8850REG_X_INC			0x3814
#define OV8850REG_Y_INC			0x3815

/*
 * bit[6]: digital vertical flip
 * bit[1]: array vertical flip
 * bit[0]: vertical binning
 */
#define OV8850REG_TIMING_FORMAT1	0x3820

/*
 * bit[2:1]: 00-normal;11-horizontal mirror
 * bit[0]: horizontal binning
 */
#define OV8850REG_TIMING_FORMAT2	0x3821


/* exposure: three bytes */
#define OV8850REG_LONG_EXPOSURE	0x3500

/*
 * bit[5]: Gain delay option: 0-one frame latch; 1-delay one frame latch
 * bit[4]: choose delay option: 0-delay disable; 1-delay enable
 * bit[1]: AGC manual enable
 * bit[0]: AEC manual enable
 */
#define OV8850REG_AEC_MANUAL		0x3503

/* exposure: three bytes */
#define OV8850REG_SHORT_EXPOSURE	0x3506

#define OV8850REG_GAIN_CONVERT		0x3509

#define OV8850REG_AEC_GAIN		0x350a

/*
 * bit[7:4]: lane num
 * bit[0]: 1-mipi;0-dvp
 */
#define OV8850REG_MIPI_SC_CTRL0		0x3011

/*
 * bit[7:4]: disable each lane
 * bit[3]: phy mode; 1-mipi;0-dvp
 */
#define OV8850REG_MIPI_SC_CTRL2		0x3015

#define OV8850REG_GENERAL_COLORBAR	0x5e00
#define OV8850REG_GROUP_ACCESS	0x3208

#define MIPI_4LANE

#define ORIENTATION_PHONE

/* For Huawei OTP */
struct otp_struct {
	//module info
	u8 year;
	u8 month;
	u8 day;
	u8 user_id_1;
	u8 user_id_2;
	u8 user_id_3;
	u8 cam_code;
	u8 vendor_version;
	//awb
	u8 rg_h;
	u8 rg_l;
	u8 bg_h;
	u8 bg_l;
	u8 rg_coff;
	u8 bg_coff;
	//vcm
	u8 start_curr;
	u8 end_curr;
	//lenc
	u8 lenc[62];
};

typedef enum {
	OV8850_MODULE_SAMSUNG = 0,
	OV8850_MODULE_FOXCONN,
	OV8850_MODULE_MAX,
} flash_moudle_t ;

#define OTP_BUFFER_START_ADDRESS		0x3d00
#define RG_TYPICAL 0x400
#define BG_TYPICAL 0x400

/*OVISP register*/
#define REG_D65_LIMIT		0x6620d
#define REG_D65_SPLIT		0x6620f
#define REG_A_LIMIT			0x6620e
#define REG_A_SPLIT			0x66210
#define REG_CWF_X			0x66209
#define REG_CWF_Y			0x6620a
#define REG_CENTER_CT		0x1c1c8
#define REG_LEFT_CT			0x1c1cc
#define REG_RIGHT_CT		0x1c1d0
#define REG_K_Y2X			0x6620b
#define REG_K_X2Y			0x6620c
#define REG_CT_A			0x1ccd5
#define REG_CT_CWF			0x1ccd6
#define REG_CT_D			0x1ccd7
#define REG_CT_HIGH_LIGHT_1		0x1c5d4
#define REG_CT_HIGH_LIGHT_2		0x1c5d5
#define REG_CT_HIGH_LIGHT_D50_B	0x1c5d6
#define REG_CT_HIGH_LIGHT_D50_R	0x1c5d7

int ov8850_check_otp_group(u16 index);
void ov8850_read_otp_mi_wb_vcm(u16 index, struct otp_struct *potp);
void ov8850_update_otp_wb(u16 otp_index);
void ov8850_update_otp_lenc(u16 otp_index);
void ov8850_update_blc(void);


/***********************************************************************
 *
 * ov8850 init sensor registers list
 *
 ***********************************************************************/
/* default is 1600*1200 9fps 2lane */
const struct _sensor_reg_t ov8850_init_regs[] = {
     /*
	*@@ init_1632x1224_BIN2_30fps
	*100 99 1632 1224
	*100 98 1 0
	*102 81 0
	*102 3601 BB8
	*/
	//{0x0103, 0x01},	
	{0x0102, 0x01}, 
	{0x3002, 0x08}, 
	{0x3004, 0x00}, 
	{0x3005, 0x00}, 
	{0x3011, 0x41}, 
	{0x3012, 0x08}, 
	{0x3014, 0x4a}, 
	{0x3015, 0x0a}, 
	{0x3021, 0x00}, 
	{0x3022, 0x02}, 
	{0x3081, 0x02}, 
	{0x3083, 0x01}, 
	{0x3090, 0x02}, 
	{0x3091, 0x16}, 	//for 20Mhz XVCLK, 12 for 24Mhz XVCLK 
	{0x3092, 0x00}, 
	{0x3093, 0x00}, 
	{0x3094, 0x00}, 
	{0x3098, 0x03}, 
	{0x3099, 0x12}, //0x24	//for 20Mhz XVCLK, 1e for 24Mhz XVCLK 
	{0x309a, 0x00}, 
	{0x309b, 0x00}, 
	{0x309c, 0x01}, //0x00
	{0x30b3, 0x5a}, //0x78	//for 20Mhz XVCLK, 64 for 24Mhz XVCLK 
	{0x30b4, 0x03}, 
	{0x30b5, 0x04}, 
	{0x30b6, 0x01}, 
	{0x3104, 0xa1}, 
	{0x3106, 0x01}, 
	{0x3500, 0x00}, 
	{0x3501, 0x7C}, 
	{0x3502, 0x40}, 
	{0x3503, 0x07}, 
	{0x350a, 0x00}, 
	{0x350b, 0x38}, 
	{0x3602, 0x50}, 
	{0x3620, 0x64}, 
	{0x3622, 0x0f}, 
	{0x3623, 0x68}, 
	{0x3624, 0x04}, 
	{0x3625, 0x40}, 
	{0x3631, 0x83}, 
	{0x3633, 0x34}, 
	{0x3634, 0x03}, 
	{0x364c, 0x00}, 
	{0x364d, 0x00}, 
	{0x364e, 0x00}, 
	{0x364f, 0x00}, 
	{0x3660, 0x80}, 
	{0x3662, 0x10}, 
	{0x3665, 0x00}, 
	{0x3666, 0x00}, 
	{0x366f, 0x20}, 
	{0x3680, 0xe0}, 
	{0x3702, 0xdb}, 
	{0x3703, 0x2e}, 
	{0x3704, 0x71}, 
	{0x3708, 0xe6}, 
	{0x3709, 0xc3}, 
	{0x371f, 0x18}, 
	{0x3732, 0x05}, 
	{0x3739, 0x30}, 
	{0x373a, 0x51}, 
	{0x373c, 0x38}, 
	{0x373d, 0x22}, 
	{0x3754, 0xc0}, 
	{0x3756, 0x2a}, 
	{0x3759, 0x0f}, 
	{0x376b, 0x44}, 
	{0x3781, 0x0c}, 
	{0x3786, 0x16}, 
	{0x3795, 0x00}, 
	{0x3796, 0x78}, 
	{0x379c, 0x0c}, 
	{0x3800, 0x00},      //x start                  
	{0x3801, 0x00},                                 
	{0x3802, 0x00},      //y start                  
	{0x3803, 0x00},                                 
	{0x3804, 0x0c},      //x end                    
	{0x3805, 0xcf},                                 
	{0x3806, 0x09},      //y end                    
	{0x3807, 0x9f},                                 
	{0x3808, 0x06},      //width                    
	{0x3809, 0x60},                                 
	{0x380a, 0x04},      //height
	{0x380b, 0xc8},                                 
	{0x380c, 0x0e},      //hts                      
	{0x380d, 0x18},                                 
	{0x380e, 0x07},      //vts
	{0x380f, 0xcC},                                 
	{0x3810, 0x00},      //H_OFFSET                 
	{0x3811, 0x04},                                 
	{0x3812, 0x00},      //V_OFFSET                 
	{0x3813, 0x04},                                 
	{0x3814, 0x31}, 
	{0x3815, 0x31}, 
	{0x3820, 0x11}, 
	{0x3821, 0x0f}, 
	{0x3826, 0x00}, 
	{0x3a04, 0x03}, 
	{0x3a05, 0xb0}, 
	{0x4000, 0x18}, 
	{0x4001, 0x02}, 
	{0x4002, 0xc5}, 
	{0x4004, 0x04}, 
	{0x4005, 0x18}, 
	{0x4006, 0x20}, 
	{0x4008, 0x20}, 
	{0x4009, 0x10}, 
	{0x404f, 0x7f}, 
	{0x4100, 0x04}, 
	{0x4101, 0x04}, 
	{0x4102, 0x04}, 
	{0x4104, 0x04}, 
	{0x4109, 0x04}, 
	{0x4300, 0xff}, 
	{0x4301, 0x00}, 
	{0x4315, 0x00}, 
	{0x4512, 0x01}, 
	{0x4837, 0x0d}, //0x08, 0x0a
	{0x4a00, 0xaa}, 
	{0x4a03, 0x01}, 
	{0x4a05, 0x08}, 
	{0x4d00, 0x04}, 
	{0x4d01, 0x52}, 
	{0x4d02, 0xfe}, 
	{0x4d03, 0x05}, 
	{0x4d04, 0xff}, 
	{0x4d05, 0xff}, 
	{0x5000, 0x06}, 
	{0x5001, 0x01}, 
	{0x5002, 0x00}, 
	{0x5041, 0x04}, 
	{0x5043, 0x48}, 
	{0x5e00, 0x00}, 
	{0x5e10, 0x1c}, 
	{0x0100, 0x01}, 
};

const struct _sensor_reg_t ov8850_framesize_1632x1224[] = {
	/*
	 *@@preview 1632x1224
	 *100 99 1632 1224
	 *100 98 1 0
	 *102 81 0
	 *102 3601 BB8
	 */
	{0x0100, 0x00}, 
	{0x3011, 0x41}, 
	{0x3015, 0x0a}, 
	{0x3090, 0x02}, 
	{0x3091, 0x16}, 	//for 20Mhz XVCLK, 12 for 24Mhz XVCLK 
	{0x3092, 0x00}, 
	{0x3093, 0x00}, 
	{0x3094, 0x00}, 
	{0x3098, 0x03}, 
	{0x3099, 0x12}, //0x24	//for 20Mhz XVCLK, 1e for 24Mhz XVCLK 
	{0x309c, 0x01}, //0x00 	new add by lisuna	
	{0x30b3, 0x5a},//0x78 	//for 20Mhz XVCLK, 64 for 24Mhz XVCLK 
	{0x30b4, 0x03}, 
	{0x30b5, 0x04}, 
	{0x30b6, 0x01}, 
	{0x3500, 0x00}, 
	{0x3501, 0x7c}, 
	{0x3502, 0x40}, 
	{0x3624, 0x04}, 
	{0x3680, 0xe0}, 
	{0x3702, 0xdb}, 
	{0x3704, 0x71}, 
	{0x3708, 0xe6}, 
	{0x3709, 0xc3}, 
	{0x371F, 0x18}, 
	{0x3739, 0x30}, 
	{0x373a, 0x51}, 
	{0x373C, 0x38}, 
	{0x3781, 0x0c}, 
	{0x3786, 0x16}, 
	{0x3796, 0x78}, 
	{0x3800, 0x00}, 			//x start          0          
	{0x3801, 0x00},                                              
	{0x3802, 0x00},                 //y start         0           
	{0x3803, 0x00},                                              
	{0x3804, 0x0c},                 //x end         3279             
	{0x3805, 0xcf},                                              
	{0x3806, 0x09},                 //y end          2463            
	{0x3807, 0x9f},                                              
	{0x3808, 0x06},                 //width          1632            
	{0x3809, 0x60},                                              
	{0x380a, 0x04},                 //height        1224
	{0x380b, 0xC8},                                              
	{0x380c, 0x0E},                 //hts            3608            
	{0x380d, 0x18},                                              
	{0x380e, 0x07},                 //vts	    2028
	{0x380f, 0xec}, //0xcc                                       
	{0x3814, 0x31}, 
	{0x3815, 0x31}, 
	{0x3820, 0x11}, 
	{0x3821, 0x0f}, 
	{0x4001, 0x02}, 
	{0x4004, 0x04}, 
	{0x4100, 0x04}, 
	{0x4101, 0x04}, 
	{0x4102, 0x04}, 
	{0x4104, 0x04}, 
	{0x4109, 0x04}, 
	{0x0100, 0x01}, 	//wake up from software standby
};

const struct _sensor_reg_t ov8850_framesize_3264x2448[] = {
     /*
	*@@capture
	*100 99 3264 2448
	*100 98 1 0
	*102 81 0
	*102 3601 960
	*/
	{0x0100, 0x00},
	{0x3011, 0x41},
	{0x3015, 0x0a},
	{0x3090, 0x02},
	{0x3091, 0x16},	//for 20Mhz XVCLK, 12 for 24Mhz XVCLK 
	{0x3092, 0x00},
	{0x3093, 0x00},
	{0x3094, 0x00},
	{0x3098, 0x03},
	{0x3099, 0x12},//0x24	//for 20Mhz XVCLK, 1e for 24Mhz XVCLK 
	{0x309c, 0x01}, //0x00 	new add by lisuna	
	{0x30b3, 0x5a},//0x78	//for 20Mhz XVCLK, 64 for 24Mhz XVCLK 
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x3500, 0x00},
	{0x3501, 0x9b},
	{0x3502, 0x60},
	{0x3624, 0x04},
	{0x3680, 0xE0},
	{0x3702, 0xDB},
	{0x3704, 0x71},
	{0x3708, 0xe4},
	{0x3709, 0xc3},
	{0x371F, 0x18},
	{0x3739, 0x30},
	{0x373a, 0x51},
	{0x373C, 0x38},
	{0x3781, 0x0C},
	{0x3786, 0x16},
	{0x3796, 0x78},
	{0x3800, 0x00},			//x start	6                     
	{0x3801, 0x06},                                               
	{0x3802, 0x00},                 //y start	4                     
	{0x3803, 0x04},                                               
	{0x3804, 0x0c},                 //x end	3275                       
	{0x3805, 0xcb},                                               
	{0x3806, 0x09},                 //y end	2467                       
	{0x3807, 0xa3},                                               
	{0x3808, 0x0c},                 //width	3264                       
	{0x3809, 0xc0},                                               
	{0x380a, 0x09},                 //height	2448  
	{0x380b, 0x90},                                               
	{0x380c, 0x0e},                 //hts 	3608                        
	{0x380d, 0x18},                                               
	{0x380e, 0x09},                 //vts	2542
	{0x380f, 0xee},	//0xbe
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10},
	{0x3821, 0x0e},
	{0x4001, 0x02},
	{0x4004, 0x08},
	{0x4100, 0x04},
	{0x4101, 0x04},
	{0x4102, 0x04},
	{0x4104, 0x04},
	{0x4109, 0x04},
	{0x0100, 0x01},	//wake up from software standby
};

/*RES_3264x2448 full size 24fps*/
const struct _sensor_reg_t ov8850_framesize_full_24fps[] = {
	/* Full Size(3264*2448) 16.375M MCLK 10bit 2/4 lane 24fps */
	{0x0100, 0x00},
	{0x3708, 0xe3}, //no binning
	{0x3709, 0x03},
	{0x3800, 0x00},
	{0x3801, 0x0c},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x0c},
	{0x3805, 0xd3},
	{0x3806, 0x09},
	{0x3807, 0xa3},
	{0x3808, 0x0c},
	{0x3809, 0xc0},
	{0x380a, 0x09},
	{0x380b, 0x90},
	{0x380c, 0x0e},
	{0x380d, 0x18},
	{0x380e, 0x09},
	{0x380f, 0xb4},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10}, // flip
	{0x3821, 0x0e}, // mirror
	{0x3a04, 0x09},
	{0x3a05, 0xa9},
	{0x4512, 0x01},

#ifdef MIPI_4LANE
	/* MIPI 4lane,655Mbps/lane,212.88Msclk,,4lane,23.75fps,1/100s->0x24e,1/120s->0x1eb */
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x02},
	{0x3091, 0x1a},
	{0x3092, 0x00},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},
#else
	/*MIPI 2lane,1007Mbps/lane,212.88Msclk,2lane,23.75fps,1/100s->0x24e,1/120s->0x1eb */
	{0x3011, 0x21},
	{0x3015, 0xc8},
	{0x3090, 0x01},
	{0x3091, 0x1a},
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x7b},
	{0x30b4, 0x02},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x08},
	{0x3098, 0x02},
	{0x0100, 0x01},
#endif
};

//support solutions and fps in datasheet P23.
const struct _sensor_reg_t ov8850_framesize_full_15fps[] = {
	//Mormo
	/* Full Size(3264*2448) 20M MCLK 10bit 2/4 lane 14fps */
	{0x0100, 0x00},
	{0x3708, 0xe3}, //no binning
	{0x3709, 0x03},
	{0x3800, 0x00},
	{0x3801, 0x0c},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x0c},
	{0x3805, 0xd3},
	{0x3806, 0x09},
	{0x3807, 0xa3},
	{0x3808, 0x0c},
	{0x3809, 0xc0},
	{0x380a, 0x09},
	{0x380b, 0x90},
	{0x380c, 0x0e}, //hts
	{0x380d, 0xcc},
	{0x380e, 0x0a}, //vts set to 0xad1(cs 15fps, es 13fps)
	{0x380f, 0x4d},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10}, // flip
	{0x3821, 0x0e}, // mirror
	{0x3a04, 0x09},
	{0x3a05, 0xa9},
	{0x4004, 0x08},
	{0x4512, 0x01},

#ifdef MIPI_4LANE
	/* MIPI 4lane,655Mbps/lane,122.8Msclk,4lane,14fps,1/100s->0x152,1/120s->0x11b */
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x01},
	{0x3091, 0x0f},//multiplier is 15.
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},
#else
	/*MIPI 2lane,1007Mbps/lane,122.8Msclk,2lane,14fps,1/100s->0x152,1/120s->0x11b */
	{0x3011, 0x21},
	{0x3015, 0xc8},
	{0x3090, 0x01},
	{0x3091, 0x0f},
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x7b},
	{0x30b4, 0x02},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x08},
	{0x3098, 0x02},
	{0x0100, 0x01},
#endif
};

const struct _sensor_reg_t ov8850_framesize_full_es[] = {
	//Mormo
	/* Full Size(3264*2448) 20M MCLK 10bit 2/4 lane 14fps */
	{0x0100, 0x00},
	{0x3708, 0xe3}, //no binning
	{0x3709, 0x03},
	{0x3800, 0x00},
	{0x3801, 0x0c},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x0c},
	{0x3805, 0xd3},
	{0x3806, 0x09},
	{0x3807, 0xa3},
	{0x3808, 0x0c},
	{0x3809, 0xc0},
	{0x380a, 0x09},
	{0x380b, 0x90},
	{0x380c, 0x0e}, //hts
	{0x380d, 0x18},
	{0x380e, 0x0a}, //vts set to 0xad1(cs 15fps, es 13fps)
	{0x380f, 0xd1},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10}, // flip
	{0x3821, 0x0e}, // mirror
	{0x3a04, 0x09},
	{0x3a05, 0xa9},
	{0x4512, 0x01},

#ifdef MIPI_4LANE
	/* MIPI 4lane,655Mbps/lane,122.8Msclk,4lane,14fps,1/100s->0x152,1/120s->0x11b */
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x03},
	{0x3091, 0x2e},//multiplier is 46, div 3=15.38.
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},
#else

#endif
};

/* j00179721_2012-05-07 */
/*RES_3264x1836 crop 30fps ????*/	
const struct _sensor_reg_t ov8850_framesize_3264x1840[] = {
/* Full Size(3264*1840) 20M MCLK 10bit 2/4 lane 19fps */
	{0x0100, 0x00},
	{0x3708, 0xe3}, //no binning
	{0x3709, 0x03},

	{0x3800, 0x00},
	{0x3801, 0x0c},
	{0x3802, 0x01},
	{0x3803, 0x3c},

	{0x3804, 0x0c},
	{0x3805, 0xd3},
	{0x3806, 0x08},
	{0x3807, 0x73},

	{0x3808, 0x0c},
	{0x3809, 0xc0},
	{0x380a, 0x07},
	{0x380b, 0x30},

	{0x380c, 0x0e}, //hts
	{0x380d, 0xcc},
	{0x380e, 0x08}, //vts set to 0xad1(cs 15fps, es 13fps)
	{0x380f, 0x23},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10}, // flip
	{0x3821, 0x0e}, // mirror
	{0x3a04, 0x07},
	{0x3a05, 0x49},
	{0x4004, 0x08},
	{0x4512, 0x01},

#ifdef MIPI_4LANE
	/* MIPI 4lane,655Mbps/lane,122.8Msclk,4lane,14fps,1/100s->0x152,1/120s->0x11b */
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x01},
	{0x3091, 0x0f},//multiplier is 15.
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},
#else
	/*MIPI 2lane,1007Mbps/lane,122.8Msclk,2lane,14fps,1/100s->0x152,1/120s->0x11b */
	{0x3011, 0x21},
	{0x3015, 0xc8},
	{0x3090, 0x01},
	{0x3091, 0x0f},
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x7b},
	{0x30b4, 0x02},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x08},
	{0x3098, 0x02},
	{0x0100, 0x01},
#endif
};


//h00206029_20120120
const struct _sensor_reg_t ov8850_framesize_2592x1944[] = {

	//P2592*1944 16.375M MCLK 10bit 2/4 lane 20fps 655Mbps/lane
	{0x0100, 0x00},
	{0x3708, 0xe3}, //no binning
	{0x3709, 0x03},
	{0x3800, 0x00},
	{0x3801, 0x18},
	{0x3802, 0x00},
	{0x3803, 0x14},
	{0x3804, 0x0C},
	{0x3805, 0xC7},
	{0x3806, 0x09},
	{0x3807, 0x99},
	{0x3808, 0x0A},
	{0x3809, 0x20},
	{0x380A, 0x07},//height, change from 1944 to 1952
	{0x380B, 0x98},
	{0x380C, 0x0E},
	{0x380D, 0x18},
	{0x380E, 0x09},
	{0x380F, 0xA2},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10}, // flip
	{0x3821, 0x0e}, // mirror
	{0x3a04, 0x07},
	{0x3a05, 0x49},
	{0x4512, 0x01},

#ifdef MIPI_4LANE
	//MIPI 4lane,655Mbps/lane,191.94Msclk,,4lane,20fps,1/100s->0x1dc,1/120s->0x18d
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x01},
	{0x3091, 0x15},
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},

#else
	//MIPI 2lane,819Mbps/lane,191.94Msclk,,2lane,20fps,1/100s->0x1dc,1/120s->0x18d
	{0x3011, 0x21},
	{0x3015, 0xc8},
	{0x3090, 0x01},
	{0x3091, 0x15},
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x96},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},
#endif
};
/*2048x1536*/
const struct _sensor_reg_t ov8850_framesize_2048x1536[] = {

	/* P2048*1536 16.375M MCLK 10bit 2/4 lane 25fps 655Mbps/lane */
	{0x0100, 0x00},
	{0x3708, 0xe3},//no binning
	{0x3709, 0x03},
	{0x3800, 0x00},
	{0x3801, 0x6C},
	{0x3802, 0x00},
	{0x3803, 0x54},
	{0x3804, 0x0C},
	{0x3805, 0x73},
	{0x3806, 0x09},
	{0x3807, 0x5B},
	{0x3808, 0x08},
	{0x3809, 0x00},
	{0x380A, 0x06},
	{0x380B, 0x00},
	{0x380C, 0x0E},
	{0x380D, 0x18},
	{0x380E, 0x09}, //vts set to 0xb3e(cs 25fps, es 21fps)
	{0x380F, 0x86},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10}, // flip
	{0x3821, 0x0e}, // mirror
	{0x3a04, 0x07},
	{0x3a05, 0x49},
	{0x4512, 0x01},

#ifdef MIPI_4LANE
	/* MIPI 4lane,655Mbps/lane,212.88Msclk,,4lane,25fps,1/100s->0x24e,1/120s->0x1eb */
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x02},
	{0x3091, 0x16},
	{0x3092, 0x00},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},
#else
	/* MIPI 2lane,655Mbps/lane,212.88Msclk,,2lane,25fps,1/100s->0x24e,1/120s->0x1eb */
	{0x3011, 0x21},
	{0x3015, 0xc8},
	{0x3090, 0x01},
	{0x3091, 0x1a},
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0c},
	{0x3098, 0x02},
	{0x0100, 0x01},
#endif
};


/*1600x1200*/
const struct _sensor_reg_t ov8850_framesize_1600x1200[] = {
	/* 1600*1200 16.375M MCLK 10bit 2/4 lane 30fps 655Mbps/lane */
	{0x0100, 0x00},
	{0x3708, 0xe6}, //binning
	{0x3709, 0x03},
	{0x3800, 0x00},
	{0x3801, 0x28},
	{0x3802, 0x00},
	{0x3803, 0x20},
	{0x3804, 0x0c},
	{0x3805, 0xb7},
	{0x3806, 0x09},
	{0x3807, 0x8f},
	{0x3808, 0x06},//1600
	{0x3809, 0x40},
	{0x380a, 0x04},//1200
	{0x380b, 0xb0},
	{0x380c, 0x0e}, //hts	//3608
	{0x380d, 0x18},
	{0x380e, 0x07}, //vts set to 0x795(cs 25fps, es 21fps)	//1941
	{0x380f, 0x95},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x31},
	{0x3815, 0x31},
	{0x3820, 0x11}, // flip
	{0x3821, 0x0f}, // mirror
	{0x3a04, 0x04},
	{0x3a05, 0xc9},
	{0x4004, 0x02},
	{0x4512, 0x00},

#ifdef MIPI_4LANE
	/*MIPI 4lane,655Mbps,143.28Msclk,4lane,30fps,1/100s->0x18d,1/120s->0x14a */
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x02},
	{0x3091, 0x2a},
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},
#else
	/*MIPI 2lane,655MMbps,143.28Msclk,2lane,30fps,1/100s->0x18d,1/120s->0x14a */
	{0x3011, 0x21},
	{0x3015, 0xc8},
	{0x3090, 0x02},
	{0x3091, 0x23},
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0c},
	{0x3098, 0x02},
	{0x0100, 0x01},
#endif
};


/*1920x1080*/
const struct _sensor_reg_t ov8850_framesize_1080p[] = {
	/* 1920*1080 16.375M MCLK 10bit 2/4 lane 24fps 655Mbps/lane */
	{0x0100, 0x00},
	{0x3708, 0xe3}, //no binning
	{0x3709, 0x03},
	{0x3800, 0x00}, //x start
	{0x3801, 0x0c},
	{0x3802, 0x01}, //y start
	{0x3803, 0x40},
	{0x3804, 0x0c}, //x end
	{0x3805, 0xd3},
	{0x3806, 0x08}, //y end
	{0x3807, 0x73},
	{0x3808, 0x07}, //width
	{0x3809, 0x80},
	{0x380a, 0x04}, //height, in fact is 1088
	{0x380b, 0x40},
	{0x380c, 0x0e}, //hts
	{0x380d, 0x18},
	{0x380e, 0x09}, //vts set to 0xb48(cs 25fps, es 21fps)
	{0x380f, 0x88},
	{0x3810, 0x00}, //H_OFFSET
	{0x3811, 0x04},
	{0x3812, 0x00}, //V_OFFSET
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10}, // flip
	{0x3821, 0x0e}, // mirror
	{0x3a04, 0x07},
	{0x3a05, 0x49},
	{0x4004, 0x08},
	{0x4512, 0x01},

#ifdef MIPI_4LANE
	/* MIPI 4lane,655Mbps/lane,212.88Msclk,,4lane,24fps,1/100s->0x24e,1/120s->0x1eb */
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x02},
	{0x3091, 0x16},
	{0x3092, 0x00},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},
#else
	/* MIPI 2lane 655Mbps/lane,212.88Msclk,2lane,24fps,1/100s->0x24e,1/120s->0x1eb */
	{0x3011, 0x21},
	{0x3015, 0xc8},
	{0x3090, 0x02},
	{0x3091, 0x1a},
	{0x3092, 0x00},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0c},
	{0x3098, 0x02},
	{0x0100, 0x01},
#endif
};

/*2112x1200*/
const struct _sensor_reg_t ov8850_framesize_1080pEIS[] = {

	/* P2112*1188 16.375M MCLK 10bit 2/4 lane 30fps 655Mbps/lane */
	{0x0100, 0x00},
	{0x3708, 0xe3}, //no binning
	{0x3709, 0x03},
	{0x3800, 0x00},
	{0x3801, 0x3C},
	{0x3802, 0x01},
	{0x3803, 0x58},
	{0x3804, 0x0C},
	{0x3805, 0xA3},
	{0x3806, 0x08},
	{0x3807, 0x55},
	{0x3808, 0x08},
	{0x3809, 0x40},
	{0x380A, 0x04},
	{0x380B, 0xB0},
	{0x380C, 0x0F}, //hts
	{0x380D, 0x18},
	{0x380E, 0x08}, //vts set to 0xa82(cs 25fps, es 21fps)
	{0x380F, 0xe8},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	{0x3820, 0x10}, // flip
	{0x3821, 0x0e}, // mirror
	{0x3a04, 0x07},
	{0x3a05, 0x49},
	{0x4004, 0x08},
	{0x4512, 0x01},

#ifdef MIPI_4LANE
	/* MIPI 4lane,655Mbps/lane,212.88Msclk,,4lane,30fps,1/100s->0x24e,1/120s->0x1eb */
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x02},
	{0x3091, 0x16},
	{0x3092, 0x00},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x0100, 0x01},
#else
	/* MIPI 2lane,655Mbps/lane,212.88Msclk,,4lane,30fps,1/100s->0x24e,1/120s->0x1eb */
	{0x3011, 0x21},
	{0x3015, 0xc8},
	{0x3090, 0x01},
	{0x3091, 0x1a},
	{0x3092, 0x01},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x4837, 0x0c},
	{0x3098, 0x02},
	{0x0100, 0x01},
#endif

};

/*the new setting is supplied by shanghai OV FAE zhanghouxin 0206*/
const struct _sensor_reg_t ov8850_init_regs_new[] = {
	//100 99 1632 1224
	//100 98 1 0
	//102 81 0
	{0x0103, 0x01},
	{0x0102, 0x01},
	{0x3002, 0x08},
	{0x3004, 0x00},
	{0x3005, 0x00},
	{0x3011, 0x41},
	{0x3012, 0x08},
	{0x3014, 0x4a},
	{0x3015, 0x0a},
	{0x3021, 0x00},
	{0x3022, 0x02},
	{0x3081, 0x02},
	{0x3083, 0x01},
	{0x3092, 0x00},
	{0x3093, 0x00},
	{0x309a, 0x00},
	{0x309b, 0x00},
	{0x309c, 0x00},
	{0x30b3, 0x64},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	{0x30b6, 0x01},
	{0x3104, 0xa1},
	{0x3106, 0x01},
	{0x3503, 0x27},//ae unstable 0x07->0x27
	{0x350a, 0x00},
	{0x350b, 0x38},
	{0x3602, 0x70},
	{0x3620, 0x64},
	{0x3622, 0x0f},
	{0x3623, 0x68},
	{0x3625, 0x40},
	{0x3631, 0x83},
	{0x3633, 0x34},
	{0x3634, 0x03},
	{0x364c, 0x00},
	{0x364d, 0x00},
	{0x364e, 0x00},
	{0x364f, 0x00},
	{0x3660, 0x80},
	{0x3662, 0x10},
	{0x3665, 0x00},
	{0x3666, 0x00},
	{0x366f, 0x20},
	{0x3703, 0x2e},
	{0x3732, 0x05},
	{0x373a, 0x51},
	{0x373d, 0x22},
	{0x3754, 0xc0},
	{0x3756, 0x2a},
	{0x3759, 0x0f},
	{0x376b, 0x44},
	{0x3795, 0x00},
	{0x379c, 0x0c},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3826, 0x00},
	{0x4000, 0x18},
	{0x4002, 0xc5},
	{0x4005, 0x18},
	{0x4006, 0x20},
	{0x4008, 0x20},
	{0x4009, 0x10},
	{0x404f, 0xA0},
	{0x4100, 0x1d},
	{0x4101, 0x23},
	{0x4102, 0x44},
	{0x4104, 0x5c},
	{0x4109, 0x03},
	{0x4300, 0xff},
	{0x4301, 0x00},
	{0x4315, 0x00},
	{0x4512, 0x01},
	{0x4837, 0x08},
	{0x4a00, 0xaa},
	{0x4a03, 0x01},
	{0x4a05, 0x08},
	{0x4d00, 0x04},
	{0x4d01, 0x52},
	{0x4d02, 0xfe},
	{0x4d03, 0x05},
	{0x4d04, 0xff},
	{0x4d05, 0xff},
	{0x5000, 0x06},
	{0x5001, 0x01},
	{0x5002, 0x80},
	{0x5041, 0x04},
	{0x5043, 0x48},
	{0x5e00, 0x00},
	{0x5e10, 0x1c},

	//1632x1224
	{0x3500, 0x00},
	{0x3501, 0x7c},
	{0x3502, 0x00},
	{0x3090, 0x02},
	{0x3091, 0x12},
	{0x3094, 0x00},
	{0x3098, 0x03},
	{0x3099, 0x1e},
	{0x3624, 0x00},
	{0x3680, 0xe0},
	{0x3702, 0xf3},
	{0x3704, 0x71},
	{0x3708, 0xe6},
	{0x3709, 0xc3},
	{0x371f, 0x0c},
	{0x3739, 0x30},
	{0x373c, 0x20},
	{0x3781, 0x0c},
	{0x3786, 0x16},
	{0x3796, 0x64},
	{0x3a04, 0x07},
	{0x3a05, 0xc8},
	{0x4001, 0x02},
	{0x4004, 0x04},
    //{0x0100, 0x01},
};

const struct _sensor_reg_t ov8850_framesize_1600x1200_new[] = {
	//1600x1200
	{0x0100, 0x00},
	{0x3708, 0xe6},	//binning
	{0x3800, 0x00},
	{0x3801, 0x28},
	{0x3802, 0x00},
	{0x3803, 0x20},
	{0x3804, 0x0c},
	{0x3805, 0xb7},
	{0x3806, 0x09},
	{0x3807, 0x8f},
	{0x3808, 0x06},
	{0x3809, 0x40},
	{0x380a, 0x04},
	{0x380b, 0xb0},
	{0x380c, 0x1c},/* hts=7216 *///{0x380c, 0x0E},
	{0x380d, 0x18},
	//{0x380e, 0x07},
	//{0x380f, 0x38},
    {0x380e, 0x04},/* vts=1228 fps=7 */
    {0x380f, 0xcc},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x31},
	{0x3815, 0x31},
	/*here just change binning state when framesizes swtich,and mirror and flip changed in update-flip func*/
	{0x3820, 0x11, 0x42},
	{0x3821, 0x0f, 0x06},
	//bining sum
	{0x4512, 0x00},
	{0x4101, 0x33},
	//pll for 20Mclk
	{0x3011, 0x41},
	{0x3015, 0x08},
	{0x3090, 0x02},
	//{0x3091, 0x28},	//200MHz//0x2a  210MHz is over
	//{0x3092, 0x01},
    {0x3091, 0x20},/* sclk=20M */
    {0x3092, 0x07},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	//{0x30b6, 0x01},
    {0x30b6, 0x02},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x3099, 0x19},
	{0x309a, 0x00},
	{0x309b, 0x00},
	{0x309c, 0x00},
	{0x0100, 0x01},
};

const struct _sensor_reg_t ov8850_framesize_3264x2448_new[] = {
	{0x0100, 0x00},
	{0x3708, 0xe4},
	{0x3709, 0xc3},
	{0x3800, 0x00},
	{0x3801, 0x0c},
	{0x3802, 0x00},
	{0x3803, 0x0c},
	{0x3804, 0x0c},
	{0x3805, 0xd3},
	{0x3806, 0x09},
	{0x3807, 0xa3},
	{0x3808, 0x0c},
	{0x3809, 0xc0},
	{0x380a, 0x09},
	{0x380b, 0x90},
	{0x380c, 0x0e},/* hts=3788 */
	{0x380d, 0xcc},
	{0x380e, 0x14},//{0x380e, 0x0a},/* vts=5278 fps=1 */
	{0x380f, 0x9e},//{0x380f, 0x4d},
	{0x3810, 0x00},
	{0x3811, 0x04},
	{0x3812, 0x00},
	{0x3813, 0x04},
	{0x3814, 0x11},
	{0x3815, 0x11},
	/*here just change binning state when framesizes swtich,and mirror and flip changed in update-flip func*/
	{0x3820, 0x10, 0x42},
	{0x3821, 0x0e, 0x06},
	{0x3a04, 0x09},
	{0x3a05, 0xcc},
	{0x4001, 0x06},
	{0x4004, 0x04},
	{0x4512, 0x01},
	{0x3011, 0x41},
	{0x3015, 0x08},
	//{0x3090, 0x01},
	//{0x3091, 0x0f},
	//{0x3092, 0x01},
	{0x3090, 0x02},/* sclk=20M */
	{0x3091, 0x20},
	{0x3092, 0x07},
	{0x3093, 0x01},
	{0x30b3, 0x78},
	{0x30b4, 0x03},
	{0x30b5, 0x04},
	//{0x30b6, 0x01},
	{0x30b6, 0x02},
	{0x4837, 0x0a},
	{0x3098, 0x02},
	{0x3099, 0x12},
	{0x309a, 0x00},
	{0x309b, 0x00},
	{0x309c, 0x00},
	{0x0100, 0x01},
};
#endif /* OV8850_H_INCLUDED */

/************************** END ***************************/