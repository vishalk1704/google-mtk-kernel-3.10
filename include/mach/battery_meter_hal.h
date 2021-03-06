/*
* Copyright (C) 2011-2014 MediaTek Inc.
* 
* This program is free software: you can redistribute it and/or modify it under the terms of the 
* GNU General Public License version 2 as published by the Free Software Foundation.
* 
* This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
* without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See the GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with this program.
* If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _BATTERY_METER_HAL_H
#define _BATTERY_METER_HAL_H

#include <mach/mt_typedefs.h>

/* ============================================================ */
/* define */
/* ============================================================ */
#define BM_LOG_CRTI 1
#define BM_LOG_FULL 2

#define bm_init_print(num, fmt, args...)   \
do {									\
	if (Enable_FGADC_LOG >= (int)num) {				\
		pr_notice(fmt, ##args); \
	}								   \
} while (0)

#define bm_print(num, fmt, args...)   \
do {									\
	if (Enable_FGADC_LOG >= (int)num) {				\
		pr_notice(fmt, ##args); \
	}								   \
} while (0)


/* ============================================================ */
/* ENUM */
/* ============================================================ */
typedef enum {
	BATTERY_METER_CMD_HW_FG_INIT,

	BATTERY_METER_CMD_GET_HW_FG_CURRENT,	/* fgauge_read_current */
	BATTERY_METER_CMD_GET_HW_FG_CURRENT_SIGN,	/*  */
	BATTERY_METER_CMD_GET_HW_FG_CAR,	/* fgauge_read_columb */

	BATTERY_METER_CMD_HW_RESET,	/* FGADC_Reset_SW_Parameter */

	BATTERY_METER_CMD_GET_ADC_V_BAT_SENSE,
	BATTERY_METER_CMD_GET_ADC_V_I_SENSE,
	BATTERY_METER_CMD_GET_ADC_V_BAT_TEMP,
	BATTERY_METER_CMD_GET_ADC_V_CHARGER,

	BATTERY_METER_CMD_GET_HW_OCV,

	BATTERY_METER_CMD_DUMP_REGISTER,

	BATTERY_METER_CMD_NUMBER
} BATTERY_METER_CTRL_CMD;

/* ============================================================ */
/* structure */
/* ============================================================ */

/* ============================================================ */
/* typedef */
/* ============================================================ */
typedef kal_int32(*BATTERY_METER_CONTROL) (BATTERY_METER_CTRL_CMD cmd, void *data);

/* ============================================================ */
/* External Variables */
/* ============================================================ */
extern int Enable_FGADC_LOG;

/* ============================================================ */
/* External function */
/* ============================================================ */
extern kal_int32 bm_ctrl_cmd(BATTERY_METER_CTRL_CMD cmd, void *data);


#endif				/* #ifndef _BATTERY_METER_HAL_H */
