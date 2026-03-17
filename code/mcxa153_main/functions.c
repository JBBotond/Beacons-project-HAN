#include "board.h"
#include "app.h"
#include "functions.h"

void init_motors(void);
void init_button(void);
bool buttonA_pressed(void);
bool buttonB_pressed(void);

volatile int buttonA_count = 0;
volatile int buttonB_count = 0;

//debug functions
void led_init(void) {
    MRCC0->MRCC_GLB_CC1_SET = MRCC_MRCC_GLB_CC1_PORT3(1);
    MRCC0->MRCC_GLB_CC1_SET = MRCC_MRCC_GLB_CC1_GPIO3(1);

    MRCC0->MRCC_GLB_RST1_SET = MRCC_MRCC_GLB_RST1_PORT3(1);
    MRCC0->MRCC_GLB_RST1_SET = MRCC_MRCC_GLB_RST1_GPIO3(1);

    PORT3->PCR[12] = PORT_PCR_LK(1);
    PORT3->PCR[12] = PORT_PCR_LK(1);
    
    GPIO3->PSOR |= (1<<12);
    GPIO3->PSOR |= (1<<13);

    GPIO3->PDDR |= (1<<12);
    GPIO3->PDDR |= (1<<13);

}
void led_green_on(void) {
    GPIO3->PCOR = (1<<13);
}
void led_red_on(void)
{
    GPIO3->PCOR = (1<<12);
}


void box_init(void) {
    //initialize gpio
    init_motors();
    init_button();
}

//state functions
void box_select_mode(int *mode) {
    if(buttonA_pressed()) {
        *mode = GAME;
    }
    if(buttonB_pressed()) {
        *mode = ADMIN;
    }
}
void box_shutdown(void) {}
void box_game_mode(void) {}
void box_admin_mode(void) {}
void box_debug_mode(void) {}
void box_game_scan(void) {}
void box_display_distance(void) {}
void box_game_hints(void) {}
void box_game_final(void) {}
void box_admin_settings(void) {}
void box_admin_connect(void) {}

//event functions
void e_init_done(void) {
    BOX_CURRENT_STATE = BOX_SELECT_MODE;
}
void e_shutdown(void) {}
void e_enter_game(void) {}
void e_enter_admin(void) {}
void e_start_scan(void) {}
void e_admin_local(void) {}
void e_admin_pc(void) {}
void e_next_ibeacon(void) {}
void e_ibeacon_found(void) {}
void e_all_ibeacons_found(void) {}
void e_draw_distance(void) {}

void init_motors(void) {
    //initialize motors pins:
    //  IN1: P2_4
    //  IN2: P3_0

    MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_GPIO2(1);
    MRCC0->MRCC_GLB_CC0 |= MRCC_MRCC_GLB_CC0_PORT2(1);

    MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_GPIO3(1);
    MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_PORT3(1);
    

    MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_GPIO2(1);
    MRCC0->MRCC_GLB_RST0 |= MRCC_MRCC_GLB_RST0_PORT2(1);

    MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_GPIO3(1);
    MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_PORT3(1);

    PORT2->PCR[4] = PORT_PCR_MUX(0) || PORT_PCR_LK(1);
    PORT2->PCR[0] = PORT_PCR_MUX(0) || PORT_PCR_LK(1);

    //set outputs to logic 0
    GPIO2->PCOR |= (1<<4);
    GPIO3->PCOR |= (1<<0);

    //configure data direction to output
    GPIO2->PDDR |= (1<<4);
    GPIO3->PDDR |= (1<<0);
}

void init_button(void) {
    //initialize built-in switch for debugging purposes

    MRCC0->MRCC_GLB_CC1 |= MRCC_MRCC_GLB_CC1_GPIO1(1);
    MRCC0->MRCC_GLB_CC0 |= MRCC_MRCC_GLB_CC0_PORT1(1);

    MRCC0->MRCC_GLB_RST1 |= MRCC_MRCC_GLB_RST1_GPIO1(1);
    MRCC0->MRCC_GLB_RST0 |= MRCC_MRCC_GLB_RST0_PORT1(1);

    PORT1->PCR[7] = PORT_PCR_MUX(0) | PORT_PCR_IBE(1);
    GPIO1->ICR[7] = GPIO_ICR_ISF(1) | GPIO_ICR_IRQC(0b1010);

    PORT3->PCR[29] = PORT_PCR_MUX(0) | PORT_PCR_IBE(1);
    GPIO3->ICR[29] = GPIO_ICR_ISF(1) | GPIO_ICR_IRQC(0b1010);

    NVIC_SetPriority(GPIO1_IRQn, 3);
    NVIC_ClearPendingIRQ(GPIO1_IRQn);
    NVIC_EnableIRQ(GPIO1_IRQn);

    NVIC_SetPriority(GPIO3_IRQn, 3);
    NVIC_ClearPendingIRQ(GPIO3_IRQn);
    NVIC_EnableIRQ(GPIO3_IRQn);

    __enable_irq();
}

bool buttonA_pressed(void) {
    if(buttonA_count > 0) {

        buttonA_count --;
        
        return true;
    }
    
    return false;
}

bool buttonB_pressed(void) {
    if(buttonB_count > 0) {

        buttonB_count --;
        
        return true;
    }
    
    return false;
}

void GPIO1_IRQHandler(void) {
    NVIC_ClearPendingIRQ(GPIO1_IRQn);

    if((GPIO1->ISFR[0] & GPIO_ISFR_ISF7(1)) != 0) {

        GPIO1->ISFR[0] = GPIO_ISFR_ISF7(1);

        buttonA_count++;
    }
}
void GPIO2_IRQHandler(void) {}
void GPIO3_IRQHandler(void) {
    NVIC_ClearPendingIRQ(GPIO3_IRQn);

    if((GPIO3->ISFR[0] & GPIO_ISFR_ISF29(1)) != 0) {

        GPIO3->ISFR[0] = GPIO_ISFR_ISF29(1);

        buttonB_count++;
    }
}