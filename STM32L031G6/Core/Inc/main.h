/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
extern float temperature;	
extern float humidity;
extern bool  keypressflag;
extern uint32_t tickstart;
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BAT_VOL_Pin GPIO_PIN_1
#define BAT_VOL_GPIO_Port GPIOA
#define LED2_SER_Pin GPIO_PIN_3
#define LED2_SER_GPIO_Port GPIOA
#define LED2_RCLK_Pin GPIO_PIN_4
#define LED2_RCLK_GPIO_Port GPIOA
#define LED2_SCLK_Pin GPIO_PIN_5
#define LED2_SCLK_GPIO_Port GPIOA
#define DIG_SER_Pin GPIO_PIN_6
#define DIG_SER_GPIO_Port GPIOA
#define DIG_RCLK_Pin GPIO_PIN_7
#define DIG_RCLK_GPIO_Port GPIOA
#define DIG_SCLK_Pin GPIO_PIN_0
#define DIG_SCLK_GPIO_Port GPIOB
#define GPIO_TEST_Pin GPIO_PIN_1
#define GPIO_TEST_GPIO_Port GPIOB
#define LED1_SER_Pin GPIO_PIN_8
#define LED1_SER_GPIO_Port GPIOA
#define LED1_RCLK_Pin GPIO_PIN_9
#define LED1_RCLK_GPIO_Port GPIOA
#define LED1_SCLK_Pin GPIO_PIN_10
#define LED1_SCLK_GPIO_Port GPIOA
#define SHTC3_SCL_Pin GPIO_PIN_6
#define SHTC3_SCL_GPIO_Port GPIOB
#define SHTC3_SDA_Pin GPIO_PIN_7
#define SHTC3_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
