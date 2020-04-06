/**
 * @file xmc4_rtc.h
 * @date 2015-05-20
 *
 * @cond
 *****************************************************************************
 * XMClib v2.2.0 - XMC Peripheral Driver Library 
 *
 * Copyright (c) 2015-2020, Infineon Technologies AG
 * All rights reserved.                        
 *                                             
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *                                                                              
 * To improve the quality of the software, users are encouraged to share 
 * modifications, enhancements or bug fixes with Infineon Technologies AG 
 * at XMCSupport@infineon.com.
 *****************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-20:
 *     - Initial
 *      
 * 2015-05-20:
 *     - Documentation updates <br>
 *   
 * @endcond 
 *
 */

#ifndef XMC4_RTC_H
#define XMC4_RTC_H

/**
 * @addtogroup XMClib XMC Peripheral Library
 * @{
 */

/**
 * @addtogroup RTC
 * @{
 */

/*********************************************************************************************************************
 * ENUMS
 *********************************************************************************************************************/

/**
 * Wakeup events for RTC from hibernate domain
 */
typedef enum XMC_RTC_WAKEUP_EVENT
{
  XMC_RTC_WAKEUP_EVENT_ON_ALARM   = RTC_CTR_TAE_Msk,  /**< Wakeup from alarm event */
  XMC_RTC_WAKEUP_EVENT_ON_SECONDS = RTC_CTR_ESEC_Msk, /**< Wakeup from seconds event */
  XMC_RTC_WAKEUP_EVENT_ON_MINUTES = RTC_CTR_EMIC_Msk, /**< Wakeup from minutes event */
  XMC_RTC_WAKEUP_EVENT_ON_HOURS   = RTC_CTR_EHOC_Msk, /**< Wakeup from hours event */
  XMC_RTC_WAKEUP_EVENT_ON_DAYS    = RTC_CTR_EDAC_Msk, /**< Wakeup from days event */
  XMC_RTC_WAKEUP_EVENT_ON_MONTHS  = RTC_CTR_EMOC_Msk, /**< Wakeup from months event */
  XMC_RTC_WAKEUP_EVENT_ON_YEARS   = RTC_CTR_EYEC_Msk  /**< Wakeup from years event */
} XMC_RTC_WAKEUP_EVENT_t;

/*********************************************************************************************************************
 * API PROTOTYPES
 *********************************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @param event A valid RTC Wakeup event (::XMC_RTC_WAKEUP_EVENT_t) or a valid combination of
 *              logically OR'd events
 * @return None
 *
 * \par<b>Description: </b><br>
 * Enable Wakeup from hibernate mode <br>
 *
 * \par
 * The function sets the bitfields of CTR register to enable wakeup from hibernate mode.  
 * Setting the masking value for the RTC wakeup events containing in the ::XMC_RTC_WAKEUP_EVENT_t 
 * leads to a wakeup from hibernate mode.
 * 
 * \par<b>Related APIs:</b><br>
 * XMC_RTC_DisableHibernationWakeUp()
 */
void XMC_RTC_EnableHibernationWakeUp(const uint32_t event);

/**
 * @param event A valid RTC Wakeup event (::XMC_RTC_WAKEUP_EVENT_t) or a valid combination of
 *              logically OR'd events          
 * @return None
 *
 * \par<b>Description: </b><br>
 * Disable Wakeup from hibernate mode <br>
 *
 * \par
 * The function resets the bitfields of CTR register to disable wakeup from hibernate mode.  
 * Resetting the masking value for the RTC wakeup events containing in the ::XMC_RTC_WAKEUP_EVENT_t  
 * disables wakeup from hibernate mode.
 * 
 * \par<b>Related APIs:</b><br>
 * XMC_RTC_EnableHibernationWakeUp()
 */
void XMC_RTC_DisableHibernationWakeUp(const uint32_t event);

#ifdef __cplusplus
}
#endif

/**
 * @}
 */

/**
 * @}
 */

#endif /* XMC4_RTC_H */
