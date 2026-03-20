#include "board.h"
#include "app.h"

#include "functions.h"
#include <stdio.h>

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
//  use events to handle box current state
int BOX_CURRENT_STATE = BOX_INIT_STATE;
int BOX_MODE = NONE;
/*******************************************************************************
 * Code
 ******************************************************************************/
int main(void)
{
    
    // TODO: init outside
    box_init();
    led_init();
    e_init_done();
    BOX_CURRENT_STATE = BOX_SELECT_MODE;
    
    printf("Fuck this fucking shit\r\n");
    
    while (1)
    {
        if(BOX_CURRENT_STATE == BOX_SELECT_MODE) {
            box_select_mode(&BOX_MODE);

            switch(BOX_MODE) {
                case GAME: {
                    led_red_on();
                    //e_enter_game();
                    //BOX_CURRENT_STATE = BOX_GAME_MODE_INIT;
                }
                break;
                case ADMIN: {
                    led_green_on();
                    //e_enter_admin();
                    //BOX_CURRENT_STATE = BOX_ADMIN_MODE_INIT;
                }
                break;
                default:
                break;
            }
        }
        if(BOX_CURRENT_STATE == BOX_GAME_MODE_INIT) {
            box_game_mode_init();

            e_start_scan();
            BOX_CURRENT_STATE = BOX_GAME_SCAN;
        }

        if(BOX_CURRENT_STATE == BOX_GAME_SCAN) {
            //  time to start scanning for ibeacons

            box_game_scan();

            e_draw_distance();
            BOX_CURRENT_STATE = BOX_DISPLAY_DISTANCE;
        }

        if(BOX_CURRENT_STATE == BOX_DISPLAY_DISTANCE) {
            printf("it's distance time \r\n");
        }
    }
}
