#include "board.h"
#include "app.h"

#include "functions.h"

// TODO: selected mode implemented in interrupts
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*******************************************************************************
 * Variables
 ******************************************************************************/
int BOX_CURRENT_STATE = BOX_INIT_STATE;
int BOX_MODE = NONE;
/*******************************************************************************
 * Code
 ******************************************************************************/
int main(void)
{
    while (1)
    {
        // TODO: init outside
        box_init();
        e_init_done();

        led_init();

        if(BOX_CURRENT_STATE == BOX_SELECT_MODE) {
            box_select_mode(&BOX_MODE);

            switch(BOX_MODE) {
                case GAME:
                    led_red_on();
                break;
                case ADMIN:
                    led_green_on();
                break;
            }
        }
    }
}
