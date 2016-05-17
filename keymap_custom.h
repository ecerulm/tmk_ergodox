//
// Ecerulm
//
// Try to mimick the TECK (my other keyboard) so the transition is easy
// EQL =+
// BSLS \ backslash and | pipe
// LSFT Left ShiFT
// LBRC: Left BRaKet [{
// RBRC: Right BRacKet ]}
// LCTL : Left ConTroL
// RCTL: Right ConTroL
// TRNS measn transparent and means that it’s the same as the lower layer
// GRV: Grave Accent and Tilde `~
// SLSH SLaSH /?
// SCLN Colon and Semicolon ;:
// RSFT: Right ShiFT
// MINS  MINuS - and underscore _
// COMM: CoMMa ,<
// DOT: .>
// NO: nothing
// LALT: Left alt
// QUOT: Quote and single quote
// RALT: Right alt , AltGr


// see tmk_keyboard/tmk_core/doc/keymap.md

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(  // layer 0 : default
        // left hand
        GRV, 1,   2,   3,   4,   5,   ESC,
        LGUI,Q,   W,   E,   R,   T,   TAB,
        LCTL,A,   S,   D,   F,   G,
        LSFT,Z,   X,   C,   V,   B,   LBRC,
        LALT,GRV, BSLS,LEFT,RGHT,
                                      LCTL,LALT,
                                           HOME,
                                 BSPC,DEL, END,
        // right hand
             EQL, 6,   7,   8,   9,   0,   MINS,
             TAB, Y,   U,   I,   O,   P,   BSLS,
                  H,   J,   K,   L,SCLN,   QUOT,
             RBRC,N,   M,COMM, DOT,SLSH,   RSFT,
                    LEFT,DOWN,UP,RGHT,RALT,
        FN0 ,RCTL,
        PGUP,
        PGDN,ENT, SPC
    ),

    KEYMAP(  // layer 1 : function and symbol keys
        // left hand
        TRNS,F1,  F2,  F3,  F4,  F5,  F11,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             F12, F6,  F7,  F8,  F9,  F10, TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 2 : keyboard functions
        // left hand
        FN0, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             FN4, TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                  TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
             TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
                       TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

    KEYMAP(  // layer 3: numpad
        // left hand
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
        TRNS,TRNS,TRNS,TRNS,TRNS,
                                      TRNS,TRNS,
                                           TRNS,
                                 TRNS,TRNS,TRNS,
        // right hand
             TRNS,NLCK,PSLS,PAST,PAST,PMNS,BSPC,
             TRNS,NO,  P7,  P8,  P9,  PMNS,BSPC,
                  NO,  P4,  P5,  P6,  PPLS,PENT,
             TRNS,NO,  P1,  P2,  P3,  PPLS,PENT,
                       P0,  PDOT,SLSH,PENT,PENT,
        TRNS,TRNS,
        TRNS,
        TRNS,TRNS,TRNS
    ),

};


/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
    ACTION_FUNCTION(KC_FN0),                           // FN0 - Teensy key
    /* ACTION_LAYER_MOMENTARY(1),                      // FN1 - switch to Layer1 */
    /* ACTION_LAYER_SET(2, ON_PRESS),                  // FN2 - set Layer2 */
    /* ACTION_LAYER_TOGGLE(3),                         // FN3 - toggle Layer3 aka Numpad layer */
    /* ACTION_LAYER_SET(0, ON_PRESS),                  // FN4 - set Layer0 */
};

void action_function(keyrecord_t *event, uint8_t id, uint8_t opt)
{
    if (id == KC_FN0) { // TEENSY_KEY
        clear_keyboard();
        print("\n\nJump to bootloader... ");
        _delay_ms(250);
        bootloader_jump(); // should not return
        print("not supported.\n");
    }
}
