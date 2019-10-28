//*****************************************************************************
//
// led_task.c - A simple flashing LED task.
//
// Copyright (c) 2012-2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.0.12573 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"


#include "inc/hw_configs.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"


//*****************************************************************************
//
// Tarea a poblar con codigo
//
//*****************************************************************************
static void tarea_1(void *pvParameters)  {
    uint8_t ui8PinData=2;



    //
    // Loop forever.
    //
    while(1)  {

        /*
         * Se enciende el led correspondiente al indice
         */
        GPIOPinWrite(GPIO_PORTF_BASE, LED_ROJO | LED_AZUL| LED_VERDE, ui8PinData);
        SysCtlDelay(2000000);

        /*
         * Se apagan todos los leds
         */
        GPIOPinWrite(GPIO_PORTF_BASE, LED_ROJO | LED_AZUL| LED_VERDE, 0x00);
        SysCtlDelay(2000000);

        /*
         * Incremento del indice en potencias de 2
         */

        if(ui8PinData == 8)
            ui8PinData = 2;
        else
            ui8PinData = ui8PinData * 2;
    }
}

//*****************************************************************************
//
// Initializes the LED task.
//
//*****************************************************************************
int32_t  tarea_1_Init(void)  {

    /*
     * Crear la  tarea_1.
     */
    if( xTaskCreate(tarea_1, (signed portCHAR *)"Tarea_1", configMINIMAL_STACK_SIZE, NULL,
                       tskIDLE_PRIORITY + 1, NULL) != pdTRUE)
    {
        return(-1);
    }

    //
    // Success.
    //
    return(0);
}
