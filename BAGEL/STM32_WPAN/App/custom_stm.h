/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    App/custom_stm.h
  * @author  MCD Application Team
  * @brief   Header for custom_stm.c module.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef CUSTOM_STM_H
#define CUSTOM_STM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
typedef enum
{
  /* BAGEL_2 */
  CUSTOM_STM_SWITCH_4,
  CUSTOM_STM_SWITCH_5,
  CUSTOM_STM_SWITCH_6,
  /* BAGEL_1 */
  CUSTOM_STM_SWITCH_1,
  CUSTOM_STM_SWITCH_2,
  CUSTOM_STM_SWITCH_3,
  CUSTOM_STM_BATTERY_VOLTAGE,
} Custom_STM_Char_Opcode_t;

typedef enum
{
  /* SWITCH_4 */
  CUSTOM_STM_SWITCH_4_READ_EVT,
  CUSTOM_STM_SWITCH_4_WRITE_EVT,
  CUSTOM_STM_SWITCH_4_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_SWITCH_4_NOTIFY_DISABLED_EVT,
  /* SWITCH_5 */
  CUSTOM_STM_SWITCH_5_READ_EVT,
  CUSTOM_STM_SWITCH_5_WRITE_EVT,
  CUSTOM_STM_SWITCH_5_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_SWITCH_5_NOTIFY_DISABLED_EVT,
  /* SWITCH_6 */
  CUSTOM_STM_SWITCH_6_READ_EVT,
  CUSTOM_STM_SWITCH_6_WRITE_EVT,
  CUSTOM_STM_SWITCH_6_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_SWITCH_6_NOTIFY_DISABLED_EVT,
  /* Switch_1 */
  CUSTOM_STM_SWITCH_1_READ_EVT,
  CUSTOM_STM_SWITCH_1_WRITE_EVT,
  CUSTOM_STM_SWITCH_1_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_SWITCH_1_NOTIFY_DISABLED_EVT,
  /* Switch_2 */
  CUSTOM_STM_SWITCH_2_READ_EVT,
  CUSTOM_STM_SWITCH_2_WRITE_EVT,
  CUSTOM_STM_SWITCH_2_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_SWITCH_2_NOTIFY_DISABLED_EVT,
  /* Switch_3 */
  CUSTOM_STM_SWITCH_3_READ_EVT,
  CUSTOM_STM_SWITCH_3_WRITE_EVT,
  CUSTOM_STM_SWITCH_3_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_SWITCH_3_NOTIFY_DISABLED_EVT,
  /* BATTERY_VOLTAGE */
  CUSTOM_STM_BATTERY_VOLTAGE_READ_EVT,
  CUSTOM_STM_BATTERY_VOLTAGE_NOTIFY_ENABLED_EVT,
  CUSTOM_STM_BATTERY_VOLTAGE_NOTIFY_DISABLED_EVT,
  CUSTOM_STM_NOTIFICATION_COMPLETE_EVT,

  CUSTOM_STM_BOOT_REQUEST_EVT
} Custom_STM_Opcode_evt_t;

typedef struct
{
  uint8_t * pPayload;
  uint8_t   Length;
} Custom_STM_Data_t;

typedef struct
{
  Custom_STM_Opcode_evt_t       Custom_Evt_Opcode;
  Custom_STM_Data_t             DataTransfered;
  uint16_t                      ConnectionHandle;
  uint8_t                       ServiceInstance;
  uint16_t                      AttrHandle;
} Custom_STM_App_Notification_evt_t;

/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
extern uint16_t SizeSwitch_4;
extern uint16_t SizeSwitch_5;
extern uint16_t SizeSwitch_6;
extern uint16_t SizeSwitch_1;
extern uint16_t SizeSwitch_2;
extern uint16_t SizeSwitch_3;
extern uint16_t SizeBattery_Voltage;

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macros -----------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions ------------------------------------------------------- */
void SVCCTL_InitCustomSvc(void);
void Custom_STM_App_Notification(Custom_STM_App_Notification_evt_t *pNotification);
tBleStatus Custom_STM_App_Update_Char(Custom_STM_Char_Opcode_t CharOpcode,  uint8_t *pPayload);
tBleStatus Custom_STM_App_Update_Char_Variable_Length(Custom_STM_Char_Opcode_t CharOpcode, uint8_t *pPayload, uint8_t size);
tBleStatus Custom_STM_App_Update_Char_Ext(uint16_t Connection_Handle, Custom_STM_Char_Opcode_t CharOpcode, uint8_t *pPayload);
/* USER CODE BEGIN EF */

/* USER CODE END EF */

#ifdef __cplusplus
}
#endif

#endif /*CUSTOM_STM_H */
