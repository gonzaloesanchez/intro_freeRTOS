/*
 * hw_configs.c
 *
 *  Created on: 28 oct. 2019
 *      Author: gonza
 */

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

#include "inc/hw_configs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"


/********************************************************************************
 * Funcion de configuracion de puertos GPIO
 *
 * @param NONE
 * @returns NONE
 *********************************************************************************/
void GPIO_config(void)  {
    /*
     * Configuramos el puerto F correspondientes a los leds
     */

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_ROJO | LED_AZUL | LED_VERDE);
}
