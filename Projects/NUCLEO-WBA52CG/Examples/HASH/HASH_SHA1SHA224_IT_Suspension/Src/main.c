/**
  ******************************************************************************
  * @file    HASH/HASH_SHA1SHA224_IT_Suspension/Src/main.c
  * @author  MCD Application Team
  * @brief   This example provides a short description of HASH processing suspension
  *          and resumption applied to SHA-1 and SHA-224 algorithms.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) $COPYRIGHT_YEAR$ STMicroelectronics. 
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the 
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup $FAMILYNAME_UC$_HAL_Examples
  * @{
  */

/** @addtogroup HASH_SHA1SHA224_IT_Suspension
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define LOW_PRIO_INPUT_TAB_SIZE    ((uint32_t) 261)      /* The size of the input data "aInput_LowPrio" */
#define HIGH_PRIO_INPUT_TAB_SIZE   ((uint32_t) 264)     /* The size of the input data "aInput_HighPrio" */

#define HASHTimeout        0xFF

#define SHA1_DIGEST_LENGTH   20
#define SHA224_DIGEST_LENGTH 28
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* HASH handler declaration */
HASH_HandleTypeDef     HashHandle;


uint8_t Key261_Input[261] __attribute__ ((aligned (128)))= {
0x54, 0x68, 0x65, 0x20, 0x68, 0x61, 0x73, 0x68, 0x20, 0x70, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73,
	0x6f, 0x72, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20, 0x66, 0x75, 0x6c, 0x6c, 0x79, 0x20, 0x63, 0x6f,
	0x6d, 0x70, 0x6c, 0x69, 0x61, 0x6e, 0x74, 0x20, 0x69, 0x6d, 0x70, 0x6c, 0x65, 0x6d, 0x65, 0x6e,
	0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68, 0x65, 0x20, 0x73, 0x65,
	0x63, 0x75, 0x72, 0x65, 0x20, 0x68, 0x61, 0x73, 0x68, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72, 0x69,
	0x74, 0x68, 0x6d, 0x20, 0x28, 0x53, 0x48, 0x41, 0x2d, 0x31, 0x29, 0x2c, 0x20, 0x74, 0x68, 0x65,
	0x20, 0x4d, 0x44, 0x35, 0x20, 0x28, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x2d, 0x64, 0x69,
	0x67, 0x65, 0x73, 0x74, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72, 0x69, 0x74, 0x68, 0x6d, 0x20, 0x35,
	0x29, 0x20, 0x68, 0x61, 0x73, 0x68, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72, 0x69, 0x74, 0x68, 0x6d,
	0x20, 0x61, 0x6e, 0x64, 0x20, 0x74, 0x68, 0x65, 0x20, 0x48, 0x4d, 0x41, 0x43, 0x20, 0x28, 0x6b,
	0x65, 0x79, 0x65, 0x64, 0x2d, 0x68, 0x61, 0x73, 0x68, 0x20, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67,
	0x65, 0x20, 0x61, 0x75, 0x74, 0x68, 0x65, 0x6e, 0x74, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e,
	0x20, 0x63, 0x6f, 0x64, 0x65, 0x29, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72, 0x69, 0x74, 0x68, 0x6d,
	0x20, 0x73, 0x75, 0x69, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x61, 0x20,
	0x76, 0x61, 0x72, 0x69, 0x65, 0x74, 0x79, 0x20, 0x6f, 0x66, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69,
	0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x2e, 0x2a, 0x2a, 0x2a, 0x20, 0x53, 0x54, 0x4d, 0x33,
	0x32, 0x20, 0x2a, 0x2a, 0x2a
	};
/*
  "The hash processor is a fully compliant implementation of the secure
   hash algorithm (SHA-1, SHA-224, SHA-256), the MD5 (message-digest algorithm 5) 
   hash algorithm and the HMAC (keyed-hash message authentication code)
   algorithm suitable for a variety of applications.*** STM32 ***"
*/
__ALIGN_BEGIN uint8_t aInput_LowPrio[LOW_PRIO_INPUT_TAB_SIZE] __ALIGN_END =
                        {0x54,0x68,0x65,0x20,0x68,0x61,0x73,0x68,
                         0x20,0x70,0x72,0x6f,0x63,0x65,0x73,0x73,
                         0x6f,0x72,0x20,0x69,0x73,0x20,0x61,0x20,
                         0x66,0x75,0x6c,0x6c,0x79,0x20,0x63,0x6f,
                         0x6d,0x70,0x6c,0x69,0x61,0x6e,0x74,0x20,
                         0x69,0x6d,0x70,0x6c,0x65,0x6d,0x65,0x6e,
                         0x74,0x61,0x74,0x69,0x6f,0x6e,0x20,0x6f,
                         0x66,0x20,0x74,0x68,0x65,0x20,0x73,0x65,
                         0x63,0x75,0x72,0x65,0x20,0x68,0x61,0x73,
                         0x68,0x20,0x61,0x6c,0x67,0x6f,0x72,0x69,
                         0x74,0x68,0x6d,0x20,0x28,0x53,0x48,0x41,
                         0x2d,0x31,0x29,0x2c,0x20,0x74,0x68,0x65,
                         0x20,0x4d,0x44,0x35,0x20,0x28,0x6d,0x65,
                         0x73,0x73,0x61,0x67,0x65,0x2d,0x64,0x69,
                         0x67,0x65,0x73,0x74,0x20,0x61,0x6c,0x67,
                         0x6f,0x72,0x69,0x74,0x68,0x6d,0x20,0x35,
                         0x29,0x20,0x68,0x61,0x73,0x68,0x20,0x61,
                         0x6c,0x67,0x6f,0x72,0x69,0x74,0x68,0x6d,
                         0x20,0x61,0x6e,0x64,0x20,0x74,0x68,0x65,
                         0x20,0x48,0x4d,0x41,0x43,0x20,0x28,0x6b,
                         0x65,0x79,0x65,0x64,0x2d,0x68,0x61,0x73,
                         0x68,0x20,0x6d,0x65,0x73,0x73,0x61,0x67,
                         0x65,0x20,0x61,0x75,0x74,0x68,0x65,0x6e,
                         0x74,0x69,0x63,0x61,0x74,0x69,0x6f,0x6e,
                         0x20,0x63,0x6f,0x64,0x65,0x29,0x20,0x61,
                         0x6c,0x67,0x6f,0x72,0x69,0x74,0x68,0x6d,
                         0x20,0x73,0x75,0x69,0x74,0x61,0x62,0x6c,
                         0x65,0x20,0x66,0x6f,0x72,0x20,0x61,0x20,
                         0x76,0x61,0x72,0x69,0x65,0x74,0x79,0x20,
                         0x6f,0x66,0x20,0x61,0x70,0x70,0x6c,0x69,
                         0x63,0x61,0x74,0x69,0x6f,0x6e,0x73,0x2e,
                         0x2a,0x2a,0x2a,0x20,0x53,0x54,0x4d,0x33,
                         0x32,0x20,0x2a,0x2a,0x2a};
                         
__ALIGN_BEGIN uint8_t aInput_HighPrio[HIGH_PRIO_INPUT_TAB_SIZE] __ALIGN_END =                         
                        {0x68,0x54,0x20,0x65,0x61,0x68,0x68,0x73,
                         0x70,0x20,0x6f,0x72,0x65,0x63,0x73,0x73,
                         0x72,0x6f,0x69,0x20,0x20,0x73,0x20,0x61,
                         0x75,0x66,0x6c,0x6c,0x20,0x79,0x6f,0x63,
                         0x70,0x6d,0x69,0x6c,0x6e,0x61,0x20,0x74,
                         0x6d,0x69,0x6c,0x70,0x6d,0x65,0x6e,0x65,
                         0x61,0x74,0x69,0x74,0x6e,0x6f,0x6f,0x20,
                         0x20,0x66,0x68,0x74,0x20,0x65,0x65,0x73,
                         0x75,0x63,0x65,0x72,0x68,0x20,0x73,0x61,
                         0x20,0x68,0x6c,0x61,0x6f,0x67,0x69,0x72,
                         0x68,0x74,0x20,0x6d,0x53,0x28,0x41,0x48,
                         0x31,0x2d,0x2c,0x29,0x74,0x20,0x65,0x68,
                         0x4d,0x20,0x35,0x44,0x28,0x20,0x65,0x6d,
                         0x73,0x73,0x67,0x61,0x2d,0x65,0x69,0x64,
                         0x65,0x67,0x74,0x73,0x61,0x20,0x67,0x6c,
                         0x72,0x6f,0x74,0x69,0x6d,0x68,0x35,0x20,
                         0x20,0x29,0x61,0x68,0x68,0x73,0x61,0x20,
                         0x67,0x6c,0x72,0x6f,0x74,0x69,0x6d,0x68,
                         0x61,0x20,0x64,0x6e,0x74,0x20,0x65,0x68,
                         0x48,0x20,0x41,0x4d,0x20,0x43,0x6b,0x28,
                         0x79,0x65,0x64,0x65,0x68,0x2d,0x73,0x61,
                         0x20,0x68,0x65,0x6d,0x73,0x73,0x67,0x61,
                         0x20,0x65,0x75,0x61,0x68,0x74,0x6e,0x65,
                         0x69,0x74,0x61,0x63,0x69,0x74,0x6e,0x6f,
                         0x63,0x20,0x64,0x6f,0x29,0x65,0x61,0x20,
                         0x67,0x6c,0x72,0x6f,0x74,0x69,0x6d,0x68,
                         0x73,0x20,0x69,0x75,0x61,0x74,0x6c,0x62,
                         0x20,0x65,0x6f,0x66,0x20,0x72,0x20,0x61,
                         0x61,0x76,0x69,0x72,0x74,0x65,0x20,0x79,
                         0x66,0x6f,0x61,0x20,0x70,0x70,0x69,0x6c,
                         0x61,0x63,0x69,0x74,0x6e,0x6f,0x2e,0x73,
                         0x2a,0x2a,0x20,0x2a,0x54,0x53,0x33,0x4d,
                         0x20,0x32,0x2a,0x2a,0x00,0x2a,0x81,0x62};    
                         
                         
												 


__ALIGN_BEGIN static uint8_t aExpectSHA224Digest[SHA224_DIGEST_LENGTH] __ALIGN_END = 
                  {0x1a, 0x1d, 0x8e, 0xf1, 0xeb, 0x0a, 0x06, 0xfa, 0x64, 0x48, 
                   0xad, 0xd8, 0x88, 0xf2, 0x82, 0xa2, 0x7d, 0xdd, 0xc1, 0x46, 
                   0x12, 0xd6, 0x32, 0x0a, 0xa2, 0x50, 0xe6, 0x9b};
                        


__ALIGN_BEGIN static uint8_t aExpectSHA1Digest[SHA1_DIGEST_LENGTH] __ALIGN_END = {0xf8, 0x59, 0xc1, 0x8d, 0xec, 0x94, 0x72, 0x42, 0x79,
                              0x24, 0xfb, 0x61, 0xef, 0x7c, 0x6a, 0x6b, 0x67, 0x0b,
                              0xf9, 0xc3};                        													 

__ALIGN_BEGIN	static uint8_t aSHA1Digest[SHA1_DIGEST_LENGTH] __ALIGN_END;
__ALIGN_BEGIN	static uint8_t aSHA224Digest[SHA224_DIGEST_LENGTH] __ALIGN_END;


  uint8_t Storage_Buffer[57 * 4] = {0};   /* 57 32-bit words are saved */
                                    
                                  
                                        
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void HigherPriorityBlock_Processing(void);
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  
  HAL_Init();
  
  
  /* Configure LED1, LED3  */
  BSP_LED_Init(LD1);
  BSP_LED_Init(LD3);
  
  /* Configure the system clock  */
  SystemClock_Config();
  
  
  /****************************************************************************/
  /*                                                                          */
  /*              IT-based HASH processing suspension/resumption              */
  /*                                                                          */  
  /****************************************************************************/
  
  
  HashHandle.Instance = HASH;
  if (HAL_HASH_DeInit(&HashHandle) != HAL_OK)
  {
    Error_Handler();
  }
  
  HashHandle.Init.Algorithm = HASH_ALGOSELECTION_SHA1;
  HashHandle.Init.DataType = HASH_BYTE_SWAP;
  if (HAL_HASH_Init(&HashHandle) != HAL_OK)
  {
    Error_Handler();
  }
  
  /* For testing purposes, request suspension now */
  HAL_HASH_ProcessSuspend(&HashHandle);
  
  /* At the first call or to resume processing after suspension, the API is invoked with
  the same handle and same parameters */
  if (HAL_HASH_Start_IT(&HashHandle, aInput_LowPrio, LOW_PRIO_INPUT_TAB_SIZE, aSHA1Digest) != HAL_OK)
  {
    Error_Handler();
  }
  
  while (HAL_HASH_GetState(&HashHandle) != HAL_HASH_STATE_SUSPENDED);       
  
  /* Context saving operation */
  HAL_HASH_Suspend(&HashHandle, Storage_Buffer);
  
  /* Process high priority block (in interrupt mode) */
  HigherPriorityBlock_Processing();
  
  /* Context saving operation */
  HAL_HASH_Resume(&HashHandle, Storage_Buffer);
  
  /* At the first call or to resume processing after suspension, the API is invoked with
  the same handle and same parameters */
  if (HAL_HASH_Start_IT(&HashHandle, aInput_LowPrio, LOW_PRIO_INPUT_TAB_SIZE, aSHA1Digest) != HAL_OK)
  {
    Error_Handler();
  }
  /* Check low priority block processing result */
  if (memcmp(aSHA1Digest, aExpectSHA1Digest, SHA1_DIGEST_LENGTH) != 0)
  {
    Error_Handler();
  }  
  else
  {
    BSP_LED_On(LD1);  
  }   
  
  
  
  while (1)
  {
  }
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL1.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_PCLK7|RCC_CLOCKTYPE_HCLK5;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB7CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.AHB5_PLL1_CLKDivider = RCC_SYSCLK_PLL1_DIV1;
  RCC_ClkInitStruct.AHB5_HSEHSI_CLKDivider = RCC_SYSCLK_HSEHSI_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  BSP_LED_On(LD3);
  while (1)
  {
  } 
}


/**
  * @brief High priority block SHA-224 digest computation 
  * @note This function is executed when the low priority block processing
  *        has been suspended and its context saved (interruption mode)   
  * @note High priority block is input buffer aInput_HighPrio, digest is 
  *       saved in aSHA224Digest.             
  * @param  None
  * @retval None
  */
static void HigherPriorityBlock_Processing(void)
{
  
  /****************************************************************************/

  HashHandle.Init.DataType  = HASH_HALFWORD_SWAP; 
  HashHandle.Init.Algorithm = HASH_ALGOSELECTION_SHA224;
  if (HAL_HASH_Init(&HashHandle) != HAL_OK)
  {
    Error_Handler();
  }  
  

  /* High priority block processing */
  if (HAL_HASH_Start_IT(&HashHandle, aInput_HighPrio, HIGH_PRIO_INPUT_TAB_SIZE, aSHA224Digest) != HAL_OK)
  {
    Error_Handler();
  }
  while (HAL_HASH_GetState(&HashHandle) != HAL_HASH_STATE_READY);  
  
  /* Check high priority block processing result */
  if (memcmp(aSHA224Digest, aExpectSHA224Digest, SHA224_DIGEST_LENGTH) != 0)
  {
    Error_Handler();
  }
      
  return;
}




#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/