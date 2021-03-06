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

#ifndef _CUST_KPD_H_
#define _CUST_KPD_H_
#include <linux/input.h>
#include <cust_eint.h>
#define KPD_YES		1
#define KPD_NO		0
/* available keys (Linux keycodes) */
#define KEY_CALL	KEY_SEND
#define KEY_ENDCALL	KEY_END
#undef KEY_OK
#define KEY_OK		KEY_REPLY	/* DPAD_CENTER */
#define KEY_FOCUS	KEY_HP
#define KEY_AT		KEY_EMAIL
#define KEY_POUND	228	/* KEY_KBDILLUMTOGGLE */
#define KEY_STAR	227	/* KEY_SWITCHVIDEOMODE */
#define KEY_DEL	KEY_BACKSPACE
#define KEY_SYM		KEY_COMPOSE
#define KEY_STEM_1	265
#define KEY_STEM_2	266
#define KEY_STEM_3	267
/* KEY_HOME */
/* KEY_BACK */
/* KEY_VOLUMEDOWN */
/* KEY_VOLUMEUP */
/* KEY_MUTE */
/* KEY_MENU */
/* KEY_UP */
/* KEY_DOWN */
/* KEY_LEFT */
/* KEY_RIGHT */
/* KEY_CAMERA */
/* KEY_POWER */
/* KEY_TAB */
/* KEY_ENTER */
/* KEY_LEFTSHIFT */
/* KEY_COMMA */
				     /* KEY_DOT *//* PERIOD */
/* KEY_SLASH */
/* KEY_LEFTALT */
/* KEY_RIGHTALT */
/* KEY_SPACE */
/* KEY_SEARCH */
/* KEY_0 ~ KEY_9 */
/* KEY_A ~ KEY_Z */
/*
* Power key's HW keycodes are 8, 17, 26, 35, 44, 53, 62, 71.  Only [8] works
* for Power key in Keypad driver, so we set KEY_ENDCALL in [8] because
* EndCall key is Power key in Android.  If KPD_PWRKEY_USE_EINT is YES, these
* eight keycodes will not work for Power key.
*/


#define KPD_KEY_DEBOUNCE  1024	/* (val / 32) ms */
#define KPD_PWRKEY_MAP    KEY_POWER
#define MTK_PMIC_PWR_KEY    8

#define KPD_USE_EXTEND_TYPE   KPD_NO

/* HW keycode [0 ~ 71] -> Linux keycode */
#define KPD_INIT_KEYMAP()	\
{	\
	[0] = KEY_STEM_1,		\
}
/*****************************************************************/
/*******************Preload Customation***************************/
/*****************************************************************/
#define KPD_PWRKEY_EINT_GPIO  GPIO0

#define KPD_PWRKEY_GPIO_DIN  0

#define  KPD_DL_KEY1  8		/* KEY_POWER */
#define  KPD_DL_KEY2  0		/* KEY_VOLUMEDOWN */
/*****************************************************************/
/*******************Uboot Customation***************************/
/*****************************************************************/
#define MT65XX_FACTORY_KEY  0	/* KEY_VOLUMEDOWN */
/*****************************************************************/
/*******************factory Customation***************************/
/*****************************************************************/
#define KEYS_PWRKEY_MAP		{ KEY_POWER, "Power" }
#define KEYS_STEM_1_MAP		{ KEY_STEM_1, "Stem1" }
#define DEFINE_KEYS_KEYMAP(x)	\
 struct key x[] = {		\
	KEYS_PWRKEY_MAP,	\
	KEYS_STEM_1_MAP,	\
}
/*****************************************************************/
/*******************recovery Customation****************************/
/*****************************************************************/



#endif
