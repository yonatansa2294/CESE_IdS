#include <stdint.h>
#include <stdbool.h>

/*-------------------------- Macros y Typedef ------------------------------*/
typedef struct gpio_s* gpio_t;
gpio_t gpioCreate(uint8_t port, uint8_t pin, bool mode, bool inverted);

/*----------- Funciones publicas -------------*/
bool gpioGetValue(gpio_t output);
void gpioSetValue(gpio_t output, bool value);