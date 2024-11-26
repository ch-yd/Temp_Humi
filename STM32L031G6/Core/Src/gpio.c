/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
//      a
//		 --
//	f |  | b
//		 --  g
//	e |  | c
//		 --. dp
//      d
//															0			1			2			3			4			5			6			7			8			9			.
const uint8_t sgh_value[11] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x7F};
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED2_SER_Pin|LED2_RCLK_Pin|LED2_SCLK_Pin|DIG_SER_Pin
                          |DIG_RCLK_Pin|LED1_SER_Pin|LED1_RCLK_Pin|LED1_SCLK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DIG_SCLK_GPIO_Port, DIG_SCLK_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIO_TEST_GPIO_Port, GPIO_TEST_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin : PA2 */
  GPIO_InitStruct.Pin = GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin
                           PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = LED2_SER_Pin|LED2_RCLK_Pin|LED2_SCLK_Pin|DIG_SER_Pin
                          |DIG_RCLK_Pin|LED1_SER_Pin|LED1_RCLK_Pin|LED1_SCLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = DIG_SCLK_Pin|GPIO_TEST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);

}

/* USER CODE BEGIN 2 */
/**
  * @brief  SN74HC595发送数据函数
  * @param  sn_num：	 595器件序号
	* @param  sendValue：要发送的数据
  * @retval None
  */
void SN74HC595_Send_Data(unsigned char sn_num,unsigned int sendValue)
{
		uint8_t i = 0;
		if(sn_num == SN_DIG)
		{
				for(i = 0; i < 8; i++)
				{
						if((sendValue << i) & 0x80)
						{
								HAL_GPIO_WritePin(DIG_SER_GPIO_Port, DIG_SER_Pin, GPIO_PIN_SET);
						}
						else
						{
								HAL_GPIO_WritePin(DIG_SER_GPIO_Port, DIG_SER_Pin, GPIO_PIN_RESET);
						}
						HAL_GPIO_WritePin(DIG_SCLK_GPIO_Port, DIG_SCLK_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(DIG_SCLK_GPIO_Port, DIG_SCLK_Pin, GPIO_PIN_SET);
				}
				HAL_GPIO_WritePin(DIG_RCLK_GPIO_Port, DIG_RCLK_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(DIG_RCLK_GPIO_Port, DIG_RCLK_Pin, GPIO_PIN_SET);
		}
		else if(sn_num == SN_LED1)
		{
				for(i = 0; i < 8; i++)
				{
						if((sendValue << i) & 0x80)
						{
								HAL_GPIO_WritePin(LED1_SER_GPIO_Port, LED1_SER_Pin, GPIO_PIN_SET);
						}
						else
						{
								HAL_GPIO_WritePin(LED1_SER_GPIO_Port, LED1_SER_Pin, GPIO_PIN_RESET);
						}
						HAL_GPIO_WritePin(LED1_SCLK_GPIO_Port, LED1_SCLK_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(LED1_SCLK_GPIO_Port, LED1_SCLK_Pin, GPIO_PIN_SET);
				}
				HAL_GPIO_WritePin(LED1_RCLK_GPIO_Port, LED1_RCLK_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED1_RCLK_GPIO_Port, LED1_RCLK_Pin, GPIO_PIN_SET);
		}
		else if(sn_num == SN_LED2)
		{
				for(i = 0; i < 8; i++)
				{
						if((sendValue << i) & 0x80)
						{
								HAL_GPIO_WritePin(LED2_SER_GPIO_Port, LED2_SER_Pin, GPIO_PIN_SET);
						}
						else
						{
								HAL_GPIO_WritePin(LED2_SER_GPIO_Port, LED2_SER_Pin, GPIO_PIN_RESET);
						}
						HAL_GPIO_WritePin(LED2_SCLK_GPIO_Port, LED2_SCLK_Pin, GPIO_PIN_RESET);
						HAL_GPIO_WritePin(LED2_SCLK_GPIO_Port, LED2_SCLK_Pin, GPIO_PIN_SET);
				}
				HAL_GPIO_WritePin(LED2_RCLK_GPIO_Port, LED2_RCLK_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(LED2_RCLK_GPIO_Port, LED2_RCLK_Pin, GPIO_PIN_SET);
		}
}

/**
  * @brief  数码管显示数据函数
  * @param  row：	  行号
  * @param  column：列号
	* @param  value： 显示数据
  * @retval None
  */
void ShowNum(uint8_t row, uint8_t column, uint8_t value)
{
		if(row == 1)
		{
				switch(column)
				{
						case 1:				//第1排第一个
								SN74HC595_Send_Data(SN_DIG, 0xC1);							//0xC1 = 0xC0 | 0x01,0xC0是为了让G和H输出高，熄灭led
								SN74HC595_Send_Data(SN_LED1, sgh_value[value]);
								break;
						case 2:				//第1排第二个
								SN74HC595_Send_Data(SN_DIG, 0xC2);
								SN74HC595_Send_Data(SN_LED1, sgh_value[value] & 0x7F);
								break;
						case 3:				//第1排第三个
								SN74HC595_Send_Data(SN_DIG, 0xC4);
								SN74HC595_Send_Data(SN_LED1, sgh_value[value]);
								break;
						default:
								break;
				}
//				HAL_Delay(1);
				SN74HC595_Send_Data(SN_LED1,0xFF);
		}
		else if(row == 2)
		{
				switch(column)
				{
						case 1:				//第2排第一个
								SN74HC595_Send_Data(SN_DIG, 0xC8);
								SN74HC595_Send_Data(SN_LED2, sgh_value[value]);
								break;
						case 2:				//第2排第二个
								SN74HC595_Send_Data(SN_DIG, 0xD0);
								SN74HC595_Send_Data(SN_LED2, sgh_value[value] & 0x7F);
								break;
						case 3:				//第2排第三个
								SN74HC595_Send_Data(SN_DIG, 0xE0);
								SN74HC595_Send_Data(SN_LED2, sgh_value[value]);
								break;
						default:
								break;
				}
//				HAL_Delay(1);
				SN74HC595_Send_Data(SN_LED2,0xFF);
		}
		
}

/* USER CODE END 2 */
