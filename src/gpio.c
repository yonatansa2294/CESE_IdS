#include "gpio.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#ifndef GPIO_COUNT
#define GPIO_COUNT	5
#endif

struct gpio_s
{
	uint8_t port;
	uint8_t pin;
	bool    mode;
	bool 	allocated;
	bool	inverted;
};

gpio_t gpioAllocate(void)
{	
	static struct gpio_s instances[GPIO_COUNT] = {0};
	gpio_t result = NULL;
	
	for(uint8_t index = 0; index < GPIO_COUNT; index++)
	{
		if(instances[index].allocated == false)
		{
			result = &instances[index];
			result->allocated = true;
			break;
		}
	}
	
	return result;
}

gpio_t gpioCreate(uint8_t port, uint8_t pin, bool mode, bool inverted)
{
	#ifdef STATIC
		gpio_t result = gpioAllocate();
	#else
		gpio_t result = malloc(sizeof(struct gpio_s));
	#endif
	
	if(result)
	{
		result->port = port;
		result->pin = pin;
		result->mode = mode;
		result->inverted = inverted;
	}
	return result;
}

bool gpioGetValue(gpio_t output)
{
	if(output->inverted)
	{

	}
	else
	{

	}
	return true;
}

void gpioSetValue(gpio_t output, bool value)
{
	if(output->mode)
	{ 
	
	}
}