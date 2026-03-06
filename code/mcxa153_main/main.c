#include "board.h"
#include "app.h"


// TODO: selected mode implemented in interrupts
/*******************************************************************************
 * Definitions
 ******************************************************************************/
enum box_state {
    BOX_INIT_STATE,
    BOX_SELECT_MODE,
    BOX_SHUTDOWN,
    BOX_GAME_MODE,
    BOX_ADMIN_MODE,
    BOX_DEBUG_MODE,
    BOX_GAME_SCAN,
    BOX_DISPLAY_DISTANCE,
    BOX_GAME_HINTS,
    BOX_GAME_FINAL,
    BOX_ADMIN_SETTINGS,
    BOX_ADMIN_CONNECT
};
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void box_init(void);
void box_select_mode(void);
void box_shutdown(void);
void box_game_mode(void);
void box_admin_mode(void);
void box_debug_mode(void);
void box_game_scan(void);
void box_display_distance(void);
void box_game_hints(void);
void box_game_final(void);
void box_admin_settings(void);
void box_admin_connect(void);
/*******************************************************************************
 * Variables
 ******************************************************************************/
int BOX_CURRENT_STATE = BOX_INIT_STATE;
int BOX_SELECTED_STATE = BOX_INIT_STATE;
  //flags
  bool box_mode_selected = false;
/*******************************************************************************
 * Code
 ******************************************************************************/
int main(void)
{
    box_init();
    while (1)
    {

    }
}

void box_init(void)
{
    // Initialize the box
    // init GPIO, PORT registers
    
}

void box_select_mode(void)
{
    // Write message to select mode

    if(box_mode_selected)
    {
        //  mode parsed from interrupts
        //  set state to BOX_GAME_MODE
        //  set state to BOX_ADMIN_MODE
        //  set state to BOX_DEBUG_MODE
    }
}


void GPIO1_IRQHandler(void) {}
void GPIO2_IRQHandler(void) {}
void GPIO3_IRQHandler(void) {}
