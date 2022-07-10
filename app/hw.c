/*
Aluna: Amanda Lopes Gonçalves
Matricula: 11821ETE005
*/

#include <stdint.h>
#include <stdbool.h>
#include "main.h"
#include "hw.h"
#include "app.h"

#define HW_DEBOUCING_TIME_MS 100
#define HW_UART_BUFFER_MAX   16

// O objetivo foi criado no main.c, não esquecer do extern !
extern UART_HandleTypeDef huart1;

uint8_t uart_buffer[HW_UART_BUFFER_MAX];

void hw_gpio_toggle(hw_pins_t pin)
{
	switch(pin)
	{
	case HW_PIN0:
		HAL_GPIO_TogglePin(USER_LED_GPIO_Port, USER_LED_Pin);
		break;
	default:
		break;
	}
}

void hw_timer_tick1ms(void)
{
	app_tick1ms();
}

uint32_t hw_timer_get_ms(void)
{
	return HAL_GetTick();
}

void hw_cpu_sleep(void)
{
	__WFI();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	static uint32_t pin0_time_ms = 0;
	static uint32_t pin1_time_ms = 0;

	if(GPIO_Pin == USER_SW0_Pin)
	{
		// deboucing simplificado, poderia ser melhor sendo por interrupção específica
		if((hw_timer_get_ms() - pin0_time_ms) < HW_DEBOUCING_TIME_MS)
			return;

		pin0_time_ms = hw_timer_get_ms();

		app_switch_interrupt(HW_PIN0);
	}
	else if(GPIO_Pin == USER_SW1_Pin)
	{
		// deboucing simplificado, poderia ser melhor sendo por interrupção específica
		if((hw_timer_get_ms() - pin1_time_ms) < HW_DEBOUCING_TIME_MS)
			return;

		pin1_time_ms = hw_timer_get_ms();

		app_switch_interrupt(HW_PIN1);
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	app_put_byte(uart_buffer[0]);

	HAL_UART_Receive_IT(&huart1,uart_buffer,1);
}

void hw_uart_tx_byte(hw_uart_t uart, uint8_t c)
{
	if(uart == HW_UART0)
		HAL_UART_Transmit(&huart1,&c,1,2);
}

void hw_uart_tx_buffer(hw_uart_t uart, uint8_t *buffer, uint32_t size)
{
	if(uart == HW_UART0)
		HAL_UART_Transmit(&huart1,buffer,size,size*2);
}

void hw_init(void)
{
	HAL_UART_Receive_IT(&huart1,uart_buffer,1);
}
