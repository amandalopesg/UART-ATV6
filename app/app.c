/*
Aluna: Amanda Lopes Gonçalves
Matricula: 11821ETE005
*/

#include <stdint.h>
#include <stdbool.h>
#include "hw.h"
#include "app.h"
#include "cbf.h"

#define CBF_MAX_SIZE 32

uint8_t area[CBF_MAX_SIZE];
cbf_t cb;

bool app_started = false;

void app_init(void)
{
	// all init stuff
	hw_init();
	cbf_init(&cb,area,CBF_MAX_SIZE);
	app_started = true;
}

void app_tick1ms(void)
{
	if(app_started == false)
		return;
}

void app_switch_interrupt(hw_pins_t pin)
{
	if(app_started == false)
		return;

	if(pin == HW_PIN0)
	{
	}
	else if(pin == HW_PIN1)
	{
	}
}

bool app_put_byte(uint8_t c)
{
	if(app_started == false)
		return false;

	if(cbf_put(&cb,c) == CBF_FULL)
		return false;
	else
		return true;
}

bool app_get_byte(uint8_t *c)
{
	bool ret = false;

	if(app_started == false)
		return false;

	if(cbf_get(&cb,c) == CBF_OK)
		ret = true;

	return ret;
}

void app_loop(void)
{
	uint8_t c;

	if(app_get_byte(&c))
	{
		hw_uart_tx_byte(HW_UART0,c);
	}
}
