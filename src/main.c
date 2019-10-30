//*****************************************************************************
//
// freertos_demo.c - Simple FreeRTOS example.
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
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

//*************************** DEFINES ***************************************

#define LED_ROJO    GPIO_PIN_1
#define LED_AZUL    GPIO_PIN_2
#define LED_VERDE   GPIO_PIN_3

/*****************************************************************************
 *                      DEFINICION DE TAREAS
 ****************************************************************************/


//*****************************************************************************
//
// Tarea a poblar con codigo
//
//*****************************************************************************
static void Tarea_1(void *pvParameters)  {
    uint8_t ui8PinData=2;



    //
    // Loop forever.
    //
    while(1)  {

        /*
         * Se enciende el led correspondiente al indice
         */
        GPIOPinWrite(GPIO_PORTF_BASE, LED_ROJO | LED_AZUL| LED_VERDE, ui8PinData);
        vTaskDelay( 1000 / portTICK_RATE_MS);   //un segundo

        /*
         * Se apagan todos los leds
         */
        GPIOPinWrite(GPIO_PORTF_BASE, LED_ROJO | LED_AZUL| LED_VERDE, 0x00);
        vTaskDelay(1000 / portTICK_RATE_MS);   //un segundo

        /*
         * Incremento del indice en potencias de 2
         */

        if(ui8PinData == 8)
            ui8PinData = 2;
        else
            ui8PinData = ui8PinData * 2;
    }
}


//=============================================================================



//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}

#endif



//*****************************************************************************
//
// Initialize FreeRTOS and start the initial set of tasks.
//
//*****************************************************************************
int main(void)  {
    //
    // Set the clocking to run at 50 MHz from the PLL.
    //
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ |
                       SYSCTL_OSC_MAIN);

    /*
     * Configuramos el puerto F correspondientes a los leds
     */

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_ROJO | LED_AZUL | LED_VERDE);


    //
    // Crear la primer tarea.
    //

    xTaskCreate(Tarea_1, (signed portCHAR *)"Tarea_1", configMINIMAL_STACK_SIZE, NULL,
                       tskIDLE_PRIORITY + 1, NULL);



    //
    // Start the scheduler.  This should not return.
    //
    vTaskStartScheduler();

    //
    // Si hay un error y el scheduler vuelve, cae en este loop infinito
    //

    while(1)  {

    }
}
