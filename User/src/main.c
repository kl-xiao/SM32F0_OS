#include "main.h"
#include "cmsis_os.h"
#include "stdio.h"

int _write (int fd, char *pBuffer, int size)  
{  
	for (int i = 0; i < size; i++)  
	{  
		while((UART0->SR & UART_SR_TXNE)==0);//等待上一次串口数据发送完成  
		UART0->DR = (uint8_t) pBuffer[i];       //写DR,串口1将发送数据
	}  
	return size;  
}

osThreadId defaultTaskHandle;
osThreadId myTask02Handle;
osThreadId myTask03Handle;

void SystemClock_Config(void);
static void MX_USART0_UART_Init(void);
void StartDefaultTask(void const *argument);
void StartTask02(void const *argument);
void StartTask03(void const *argument);

uint16_t cnt = 0;

int main(void)
{
	
	SystemClock_Config();

	MX_USART0_UART_Init();

	osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
	defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

	/* definition and creation of myTask02 */
	osThreadDef(myTask02, StartTask02, osPriorityNormal, 0, 128);
	myTask02Handle = osThreadCreate(osThread(myTask02), NULL);

	/* definition and creation of myTask03 */
	osThreadDef(myTask03, StartTask03, osPriorityNormal, 0, 128);
	myTask03Handle = osThreadCreate(osThread(myTask03), NULL);


	osKernelStart();

	while (1)
	{

	}
	/* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
	SystemInit();
	SystemCoreClockUpdate();
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART0_UART_Init(void)
{
	GPIO_Init(PA9, GPIO_Mode_OUT, IOCFG_DEFAULT | IOCFG_PA9_FUNC_TXD0);
	GPIO_Init(PA10, GPIO_Mode_IN, IOCFG_DEFAULT | IOCFG_PA10_FUNC_RXD0);
	
	UART_DeInit(UART0);
	UART_Init(UART0, 38400, UART_Parity_No, UART_Mode_Rx | UART_Mode_Tx);	
	UART_ITConfig(UART0, 0, DISABLE);		//使能接收中断
}


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const *argument)
{
	/* USER CODE BEGIN 5 */
	/* Infinite loop */
	for (;;)
	{
		UART_Send(UART0,(uint8_t *) "3333\r\n",6);
		osDelay(500);
	}
	/* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void const *argument)
{
	/* USER CODE BEGIN StartTask02 */
	/* Infinite loop */
	for (;;)
	{
		printf("%d\r\n",cnt);
		osDelay(500);
	}
	/* USER CODE END StartTask02 */
}

/* USER CODE BEGIN Header_StartTask03 */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask03 */
void StartTask03(void const *argument)
{
	/* USER CODE BEGIN StartTask03 */
	/* Infinite loop */
	for (;;)
	{
		cnt++;
		UART_WriteFIFO(UART0,'a');
		osDelay(500);
	}
	/* USER CODE END StartTask03 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
