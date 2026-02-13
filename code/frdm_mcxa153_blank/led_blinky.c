/*
 * Copyright 2019 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <MCXA153.h>

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
// pin to be used for stepper control:
//      P2_4
//      P2_5
//      P3_1
//      P3_15
void gpio_output_init(void);


int main(void)
{
    gpio_output_init();

    while (1) {
        GPIO2->PCOR = (1<<5);

        for(int i = 0; i < 1000000; i++) {
        }

        GPIO2->PSOR = (1<<5);

        for(int i = 0; i < 1000000; i++) {
        }
    }
}

void gpio_output_init(void)
{
    MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_GPIO2(1);
    MRCC0->MRCC_GLB_CC0 |= MRCC_MRCC_GLB_CC0_PORT2(1);


    MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_GPIO2(1);
    MRCC0->MRCC_GLB_RST0 |= MRCC_MRCC_GLB_RST0_PORT2(1);

    PORT2->PCR[5] = 0x00008000;

    GPIO2->PDOR |= (1<<5);

    GPIO2->PDDR |= (1<<5);
}