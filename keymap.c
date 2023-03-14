//https://docs.qmk.fm/#/keycodes

#include QMK_KEYBOARD_H

#define KC_CAD LCTL(LSFT(KC_ESC))

enum layers {
    //_QWERTY,
    Colmak,
    Num_Sym, 
    Fun,
    Mouse,
    Settings,
};

enum combos {
  QW_ESC,
  AR_CAPS,
  //NE_DEL,
  IO_QOT1,
  //BJ_SLP,
  ZX_UNDO,
  ZS_SAVE,
  UNDER,
  DASH,
  JLU_CAD,
  ALT_TAB,
  TAB,
  SHIFT,
  CTRL,
  TILD,
};

const uint16_t PROGMEM esc[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM caps_lock[] = {KC_F, KC_P, COMBO_END};
//const uint16_t PROGMEM delete[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM quote1[] = {KC_I, KC_O, COMBO_END};
//const uint16_t PROGMEM sleep[] = {KC_B, KC_J, COMBO_END};
const uint16_t PROGMEM undo[] = {KC_Z, KC_C, COMBO_END};
const uint16_t PROGMEM save[] = {KC_Z, KC_D, COMBO_END};
const uint16_t PROGMEM underscore[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM dash[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM cad[] = {KC_Q, KC_A, KC_Z, COMBO_END};
const uint16_t PROGMEM alt_tab[] = {KC_Q, KC_Z, COMBO_END};
const uint16_t PROGMEM tab[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM shift[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM ctrl[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM tild[] = {KC_P, KC_L, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [QW_ESC] = COMBO(esc, KC_ESC),
    [AR_CAPS] = COMBO(caps_lock, KC_CAPS),
    //[NE_DEL] = COMBO(delete, KC_DEL),
    [IO_QOT1] = COMBO(quote1, KC_QUOT),
    //[BJ_SLP] = COMBO(sleep, KC_SLEP),
    [ZX_UNDO] = COMBO(undo, LCTL(KC_Z)),
    [ZS_SAVE] = COMBO(save, LCTL(KC_S)),
    [UNDER] = COMBO(underscore, KC_UNDS),
    [DASH] = COMBO(dash, KC_MINS),
    [JLU_CAD] = COMBO(cad, KC_CAD),
    [ALT_TAB] = COMBO(alt_tab, LALT(KC_TAB)),
    [TAB] = COMBO(tab, KC_TAB),
    [SHIFT] = COMBO(shift, KC_LSFT),
    [CTRL] = COMBO(ctrl, KC_LCTL),
    [TILD] = COMBO(tild, KC_GRV),
};

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
#    ifndef NO_AUTO_SHIFT_ALPHA
        case KC_A ... KC_Z:
#    endif
#    ifndef NO_AUTO_SHIFT_NUMERIC
        //case KC_1 ... KC_8:
        //do want autoshifted
        case KC_2:
        case KC_4:
        case KC_5:
        //do not want autoshifted
        //case KC_0
        //case KC_1
        //case KC_3
        //case KC_6
        //case KC_7
        //case KC_8
        //case KC_9
        //
#    endif
#    ifndef NO_AUTO_SHIFT_SPECIAL
        //case KC_MINUS ... KC_SLASH:
        //do want autoshifted
        case KC_SCLN:
        case KC_QUOT:
        case KC_GRV:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
        //do not want autoshifted
        //case KC_LBRC:
        //case KC_RBRC:
        //case KC_BSLS:
        //case KC_EQUAL:
#    endif
            return true;
    }
    return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Colmak
 * ,---------------------------------.     ,----------------------------------.
 * |  Q  |   W  |   F  |   P  |   B  |     |   J  |   L  |   U  |   Y  | ; :  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  A  |   R  |   S  |   T  |   G  |     |   M  |   N  |   E  |   I  |   O  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  Z  |   X  |   C  |   D  |   V  |     |   K  |   H  |  , < | . >  |  / ? |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | Del  |NumSym| BSpc |     | Spc  | Fun  | Ent  |
 *              `--------------------'     `--------------------'
 */
[Colmak] = LAYOUT_split_3x5_3(
  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,
          KC_DEL,  MO(Num_Sym),   KC_BSPC,        KC_SPC,  MO(Fun), KC_ENT
),

/* 
 * Num_Sym
 * ,---------------------------------.     ,----------------------------------.
 * | CUT |   !  |  (   |   )  |  #   |     |   /  |   7  |   8  |   9  |   -  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |COPY | PSTE |  {   |   }  |  \   |     |   *  |   4  |   5  |   6  |   +  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  ^  |   &  |  [   |   ]  |  |   |     | . >  |   1  |   2  |   3  |   =  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | Fun2 | ____ | ___  |     | BSpc | Ent  | _0__ |
 *              `--------------------'     `--------------------'
 */
[Num_Sym] = LAYOUT_split_3x5_3(
  LCTL(KC_X), KC_EXLM,     KC_LPRN, KC_RPRN, KC_HASH,        KC_KP_SLASH, KC_7,    KC_8,    KC_9,    KC_KP_MINUS,
  LCTL(KC_C), LCTL(KC_V),  KC_LCBR, KC_RCBR, KC_BSLS,        KC_ASTR,     KC_4,    KC_5,    KC_6,    KC_KP_PLUS,
  KC_CIRC,    KC_AMPR,     KC_LBRC, KC_RBRC, KC_PIPE,        KC_DOT,      KC_1,    KC_2,    KC_3,    KC_EQUAL,
                      MO(Settings), _______, _______,        _______,  KC_ENT,  KC_0
),

/*
 * FUN
 * ,---------------------------------.     ,----------------------------------.
 * |Ply/P| Mute | VDn  | VUp  | PgUp |     |  ALT | F7   |  F8  |  F9  |  F12 |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * | WIN | Left |  Up  |Right | PgDn |     |Shift | F4   |  F5  |  F6  |  F11 |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |PrtSn|Insert| Down | Home |  End |     |  CTL | F1   |  F2  |  F3  |  F10 |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              |Mouse | WHUP | WHDN |     | ____ | ____ | ____ |
 *              `--------------------'     `--------------------'
 */
 [Fun] = LAYOUT_split_3x5_3(
  KC_MPLY,  KC_MUTE, KC_VOLD,  KC_VOLU,   KC_PGUP,     KC_LALT,    KC_F7,    KC_F8,    KC_F9,    KC_F12,
  KC_LWIN,  KC_LEFT, KC_UP,    KC_RIGHT,  KC_PGDN,     KC_LSFT,    KC_F4,    KC_F5,    KC_F6,    KC_F11,
  KC_PSCR,  KC_INS,  KC_DOWN,  KC_HOME,   KC_END,      KC_LCTL,    KC_F1,    KC_F2,    KC_F3,    KC_F10,
                      MO(Mouse), KC_WH_U, KC_WH_D,     _______,  _______,  _______
),

 /*
 * Mouse
 * ,---------------------------------.     ,----------------------------------.
 * |  _  |   _  |   _  |   _  |   _  |     |   _  | mwl  | mwr  |   _  |   _  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  _  | left |  up  | right|   _  |     |   _  | lclk | rclk |   _  |   _  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  _  |   _  | down |   _  |   _  |     |   _  |   _  |   _  |   _  |   _  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | ____ | ____ | ___  |     | ___  | ___  | ____ |
 *              `--------------------'     `--------------------'
 */
 [Mouse] = LAYOUT_split_3x5_3(
  _______,   _______,    _______,    _______,    _______,        _______,    KC_WH_L,    KC_WH_R,    _______,    _______,
  _______,   KC_MS_L,    KC_MS_U,    KC_MS_R,    _______,        _______,    KC_BTN1,    KC_BTN2,    KC_BTN3,    KC_BTN4,
  _______,   _______,    KC_MS_D,    _______,    _______,        _______,    _______,    _______,    _______,    _______,
                               _______, _______, _______,        _______,  _______,  _______
),

/*
 * Settings
 * ,---------------------------------.     ,----------------------------------.
 * |  _  |   _  |   _  |   _  |AS_TOG|     |   _  |   _  |   _  |   _  |   _  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  _  |   _  |   _  |   _  |AS_UP |     |  _   |   _  |   _  |   _  |   _  |
 * |-----+------+------+------+------|     |------+------+------+------+------|
 * |  _  |   _  |   _  |AS_RPT|AS_DWN|     |  _   |   _  |   _  |   _  |   _  |
 * `------------+------+------+------|     |------+------+------+-------------'
 *              | ____ | ____ | ____ |     | ____ | ____ | ____ |
 *              `--------------------'     `--------------------'
 */
 [Settings] = LAYOUT_split_3x5_3(
  _______,   _______,    _______,    _______,  AS_TOGG,        _______,    _______,    _______,    _______,    _______,
  _______,   _______,    _______,    _______,    AS_UP,        _______,    _______,    _______,    _______,    _______,
  _______,   _______,    _______,    AS_RPT,   AS_DOWN,        _______,    _______,   _______,    _______,    _______,
                             _______, _______, _______,        _______,  _______,  _______
),
};