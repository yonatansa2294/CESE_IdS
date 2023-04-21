#include "gpio.h"
#include <stdbool.h>

#define PRESSED     0
#define LED_PORT    1
#define LED_PIN     4
#define KEY_PORT    1
#define KEY_PIN     9
#define INPUT       false
#define OUTPUT      true

int main(void)
{
	gpio_t led_rojo = gpioCreate(LED_PORT, LED_PIN, OUTPUT, true);
	gpio_t tecla    = gpioCreate(KEY_PORT, KEY_PIN, INPUT, true);
	
	while(true)
	{
		if(gpioGetValue(tecla) == PRESSED)
		{
			gpioSetValue(led_rojo, true);
		}
		else
		{
			gpioSetValue(led_rojo , false);
		}
	}

	return 0;
}