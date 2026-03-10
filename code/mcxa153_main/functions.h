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

enum box_event {
    E_INIT_DONE,
    E_SHUTDOWN,
    E_ENTER_GAME,
    E_ENTER_ADMIN,
    E_START_SCAN,
    E_ADMIN_LOCAL,
    E_ADMIN_PC,
    E_NEXT_IBEACON,
    E_IBEACON_FOUND,
    E_ALL_IBEACONS_FOUND,
    E_DRAW_DISTANCE
};

enum box_mode {
    NONE,
    GAME,
    ADMIN
};

//debug functions
void led_init(void);
void led_red_on(void);

//state functions
void box_init(void);
void box_select_mode(int *mode);
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

//event functions
void e_init_done(void);
void e_shutdown(void);
void e_enter_game(void);
void e_enter_admin(void);
void e_start_scan(void);
void e_admin_local(void);
void e_admin_pc(void);
void e_next_ibeacon(void);
void e_ibeacon_found(void);
void e_all_ibeacons_found(void);
void e_draw_distance(void);

extern int BOX_CURRENT_STATE;