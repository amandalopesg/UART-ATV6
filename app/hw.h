/*
Aluna: Amanda Lopes Gonçalves
Matricula: 11821ETE005
*/

#ifndef HW_H_
#define HW_H_

typedef enum hw_pins_e
{
	HW_PIN0 = 0,
	HW_PIN1,
} hw_pins_t;

typedef enum hw_uart_e
{
	HW_UART0 = 0,
	HW_UART1,
} hw_uart_t;

void hw_timer_tick1ms(void);
void hw_cpu_sleep(void);
void hw_gpio_toggle(hw_pins_t pin);
uint32_t hw_timer_get_ms(void);
void hw_init(void);
void hw_uart_tx_byte(hw_uart_t uart, uint8_t c);
void hw_uart_tx_buffer(hw_uart_t uart, uint8_t *buffer, uint32_t size);

#endif /* HW_H_ */
