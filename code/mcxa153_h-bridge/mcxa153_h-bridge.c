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
void moveForward(void);
void moveBackward(void);
void initMotorPins(void);
void stopMotor(void);

void initButton(void);
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Main function
 */
int main(void)
{
    initMotorPins();
    initButton();

    while (1) {
      if((GPIO1->PDIR & (1<<7)) == 0)
        stopMotor();
      else
        moveForward();
    }
}

void moveForward(void) {
  GPIO2->PSOR |= (1<<4);
  GPIO3->PCOR |= (1<<0);
}

void moveBackward(void) {
  GPIO2->PCOR |= (1<<4);
  GPIO3->PSOR |= (1<<0);
}

void stopMotor(void) {
  GPIO2->PCOR |= (1<<4);
  GPIO3->PCOR |= (1<<0);
}


void initMotorPins(void) {
    MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_GPIO2(1);
    MRCC0->MRCC_GLB_CC0 |= MRCC_MRCC_GLB_CC0_PORT2(1);

    MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_GPIO3(1);
    MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_PORT3(1);
    

    MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_GPIO2(1);
    MRCC0->MRCC_GLB_RST0 |= MRCC_MRCC_GLB_RST0_PORT2(1);

    MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_GPIO3(1);
    MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_PORT3(1);

    PORT2->PCR[4] = PORT_PCR_MUX(0);
    PORT2->PCR[0] = PORT_PCR_MUX(0);

    //set outputs to logic 0
    GPIO2->PCOR |= (1<<4);
    GPIO3->PCOR |= (1<<0);

    //configure data direction to output
    GPIO2->PDDR |= (1<<4);
    GPIO3->PDDR |= (1<<0);
}

void initButton(void) {
    MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_GPIO1(1);
    MRCC0->MRCC_GLB_CC0 |= MRCC_MRCC_GLB_CC0_PORT1(1);

    MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_GPIO1(1);
    MRCC0->MRCC_GLB_RST0 |= MRCC_MRCC_GLB_RST0_PORT1(1);

    PORT1->PCR[7] = PORT_PCR_MUX(0) | PORT_PCR_IBE(1);
}

