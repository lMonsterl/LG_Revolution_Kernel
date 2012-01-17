/* linux/include/mach/rpc_hsusb.h
 *
 * Copyright (c) 2008-2010, Code Aurora Forum. All rights reserved.
 *
 * All source code in this file is licensed under the following license except
 * where indicated.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you can find it at http://www.fsf.org
 */

#ifndef __ASM_ARCH_MSM_RPC_HSUSB_H
#define __ASM_ARCH_MSM_RPC_HSUSB_H

#include <mach/msm_rpcrouter.h>
#include <mach/msm_otg.h>
#include <mach/msm_hsusb.h>

#if defined(CONFIG_MSM_ONCRPCROUTER) && !defined(CONFIG_ARCH_MSM8X60)
int msm_hsusb_rpc_connect(void);
int msm_hsusb_phy_reset(void);
int msm_hsusb_vbus_powerup(void);
int msm_hsusb_vbus_shutdown(void);
/*LGE_CHANGE : Refered from bryce froyo */
#if defined(CONFIG_MACH_LGE_BRYCE)
int msm_hsusb_send_productID(uint32_t product_id);
int msm_hsusb_send_serial_number(char *serial_number);
int msm_hsusb_is_serial_num_null(uint32_t val);
#endif /* CONFIG_MACH_LGE_BRYCE */
int msm_hsusb_reset_rework_installed(void);
int msm_hsusb_enable_pmic_ulpidata0(void);
int msm_hsusb_disable_pmic_ulpidata0(void);
int msm_hsusb_rpc_close(void);

int msm_chg_rpc_connect(void);
int msm_chg_usb_charger_connected(uint32_t type);
int msm_chg_usb_i_is_available(uint32_t sample);
int msm_chg_usb_i_is_not_available(void);
int msm_chg_usb_charger_disconnected(void);
int msm_chg_rpc_close(void);

#ifdef CONFIG_USB_GADGET_MSM_72K
int hsusb_chg_init(int connect);
void hsusb_chg_vbus_draw(unsigned mA);
void hsusb_chg_connected(enum chg_type chgtype);
#endif


int msm_fsusb_rpc_init(struct msm_otg_ops *ops);
int msm_fsusb_init_phy(void);
int msm_fsusb_reset_phy(void);
int msm_fsusb_suspend_phy(void);
int msm_fsusb_resume_phy(void);
int msm_fsusb_rpc_close(void);
int msm_fsusb_remote_dev_disconnected(void);
int msm_fsusb_set_remote_wakeup(void);
void msm_fsusb_rpc_deinit(void);

/* wrapper to send pid and serial# info to bootloader */
int usb_diag_update_pid_and_serial_num(uint32_t pid, const char *snum);

// BEGIN: 0010099 hyunjong.do@lge.com 2010-10-21
// ADD: 0010099: [Power] Charging current control by thermister on Kernel
#if defined(CONFIG_MACH_LGE_BRYCE)
/* ADD THUNDER feature TO USE VS740 BATT DRIVER
 * 2010-05-13, taehung.kim@lge.com
 */
/* woonghee@lge.com 2009-09-25, battery charging */
int msm_hsusb_get_charger_type(void);
#endif /* CONFIG_MACH_LGE_BRYCE */
/* LGE_CHANGE_S [hyunhui.park@lge.com] 2009-04-21, Detect charger type using RPC  */
int msm_hsusb_detect_chg_type(void);
/* LGE_CHANGE_E [hyunhui.park@lge.com] 2009-04-21 */
// END:  0010099 hyunjong.do@lge.com 2010-10-21

#else
static inline int msm_hsusb_rpc_connect(void) { return 0; }
static inline int msm_hsusb_phy_reset(void) { return 0; }
static inline int msm_hsusb_vbus_powerup(void) { return 0; }
static inline int msm_hsusb_vbus_shutdown(void) { return 0; }
static inline int msm_hsusb_reset_rework_installed(void) { return 0; }
static inline int msm_hsusb_enable_pmic_ulpidata0(void) { return 0; }
static inline int msm_hsusb_disable_pmic_ulpidata0(void) { return 0; }
static inline int msm_hsusb_rpc_close(void) { return 0; }

static inline int msm_chg_rpc_connect(void) { return 0; }
static inline int msm_chg_usb_charger_connected(uint32_t type) { return 0; }
static inline int msm_chg_usb_i_is_available(uint32_t sample) { return 0; }
static inline int msm_chg_usb_i_is_not_available(void) { return 0; }
static inline int msm_chg_usb_charger_disconnected(void) { return 0; }
static inline int msm_chg_rpc_close(void) { return 0; }

#ifdef CONFIG_USB_GADGET_MSM_72K
static inline int hsusb_chg_init(int connect) { return 0; }
static inline void hsusb_chg_vbus_draw(unsigned mA) { }
static inline void hsusb_chg_connected(enum chg_type chgtype) { }
#endif

static inline int msm_fsusb_rpc_init(struct msm_otg_ops *ops) { return 0; }
static inline int msm_fsusb_init_phy(void) { return 0; }
static inline int msm_fsusb_reset_phy(void) { return 0; }
static inline int msm_fsusb_suspend_phy(void) { return 0; }
static inline int msm_fsusb_resume_phy(void) { return 0; }
static inline int msm_fsusb_rpc_close(void) { return 0; }
static inline int msm_fsusb_remote_dev_disconnected(void) { return 0; }
static inline int msm_fsusb_set_remote_wakeup(void) { return 0; }
static inline void msm_fsusb_rpc_deinit(void) { }
static inline int
usb_diag_update_pid_and_serial_num(uint32_t pid, const char *snum) { return 0; }
#endif
#endif