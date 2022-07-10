/*
Aluna: Amanda Lopes Gonçalves
Matricula: 11821ETE005
*/

#ifndef APP_H_
#define APP_H_

void app_init(void);
void app_loop(void);
void app_tick1ms(void);
void app_switch_interrupt(hw_pins_t pin);
bool app_put_byte(uint8_t c);
bool app_get_byte(uint8_t *c);

#endif /* APP_H_ */
