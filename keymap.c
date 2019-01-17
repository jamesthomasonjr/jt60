/*
* @Author: jthomason
* @Date:   2019-01-15
*/

#include QMK_KEYBOARD_H

#define LEADER_TIMEOUT 250

enum layers {
  _NORMAL = 0,
  _VIM,
  _FUNCTIONS,
  _CONTROL,
};

const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
  UCIS_SYM("poop", 0x1F4A9), // 💩
  UCIS_SYM("shit", 0x1F4A9), // 💩
  UCIS_SYM("hankey", 0x1F4A9), // 💩
  UCIS_SYM("rofl", 0x1F923), // 🤣
  UCIS_SYM("cool", 0x1F60E), //😎
  UCIS_SYM("vomit", 0x1F92E), //🤮
  UCIS_SYM("vomit2", 0x1F922), //🤢
  UCIS_SYM("sleep", 0x1F62A),  //😪
  UCIS_SYM("sleep2", 0x1F634),  //😴
  UCIS_SYM(":*", 0x1F617),  //😗
  UCIS_SYM(":*2", 0x1F618), //😘
  UCIS_SYM(":p", 0x1F61D),  //😛
  UCIS_SYM("<3", 0x2764),  //❤
  UCIS_SYM("love", 0x2764),  //❤
  UCIS_SYM("ok", 0x1F44C),  //👌
  UCIS_SYM("ok2", 0x1F44D),  //👌
  UCIS_SYM("+1", 0x1F44D),  //👍
  UCIS_SYM("like", 0x1F44D),  //👍
  UCIS_SYM("dislike", 0x1F44D),  //👎
  UCIS_SYM("this", 0x1F446),  //👆
  UCIS_SYM("that", 0x1F446),  //👆
  UCIS_SYM("fu", 0x1F595),  //🖕
  UCIS_SYM("dead", 0x1F480),  //💀
  UCIS_SYM("punch", 0x1F44A),  //👊
  UCIS_SYM("fistbump", 0x1F44A),  //👊
  UCIS_SYM("clap", 0x1F44F),  //👏
  UCIS_SYM("pancakes", 0x1F95E),  //🥞
  UCIS_SYM("coffee", 0x2615),  //☕
  UCIS_SYM("beer", 0x1F37A),  //🍺
  UCIS_SYM("beers", 0x1F37B),  //🍻
  UCIS_SYM("clink", 0x1F37B),  //🍻
  UCIS_SYM("whiskey", 0x1F943),  //🥃
  UCIS_SYM("tumbler", 0x1F943),  //🥃
  UCIS_SYM("ship", 0x1F6A2),  //🚢
  UCIS_SYM("shipit", 0x1F6A2),  //🚢
  UCIS_SYM("trash", 0x1F5D1),  //🗑
  UCIS_SYM("garbage", 0x1F5D1), //🗑
  UCIS_SYM("fire", 0x1F525), //🔥
  UCIS_SYM("flaming", 0x1F525), //🔥
  UCIS_SYM("hottip", 0x1F525) //🔥
);

enum keycodes {
  UNICODE = SAFE_RANGE,
#ifdef AUDIO_ENABLE
  ALLSTAR,
#endif
};

#ifdef AUDIO_ENABLE
  // No audio support on the DZ60 :(
  float sg_impmch[][2] = SONG(IMPERIAL_MARCH);
  float sg_bsktcs[][2] = SONG(BASKET_CASE);
  float sg_rckrll[][2] = SONG(RICK_ROLL);
  float sg_allstr[][2] = SONG(ALL_STAR);
  float sg_ff7win[][2] = SONG(VICTORY_FANFARE_SHORT);
  float sg_zeldat[][2] = SONG(ZELDA_TREASURE);
  float sg_zeldap[][2] = SONG(ZELDA_PUZZLE);
#endif


#define ____ KC_TRNS
#define KC_SRCH HYPR(KC_JYEN)
#define TO_NORM TO(_NORMAL)
#define TO_VIM  TO(_VIM)
#define MO__FNCN MO(_FUNCTIONS)
#define MO__CTRL MO(_CONTROL)
#define KC_FULL LCTL(LGUI(KC_F))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0
* ,-----------------------------------------------------------------------------------------.
* |Esc~ |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  `  | Bck |
* |-----------------------------------------------------------------------------------------+
* | Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |    \    |
* |-----------------------------------------------------------------------------------------+
* | Search  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |  ShiftEnter |
* |-----------------------------------------------------------------------------------------+
* | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | RSh | Up  | Ldr |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  Alt |  Cmd |    Space    | Fncn  |     Space     | Cmd | Alt |Left |Down |Rght |
* `-----------------------------------------------------------------------------------------'
*/

  // @TODO: This should mimic vim's modes for vim goodness everywhere
  // @TODO: Look into setting space cadet timeouts, because I apparently hold the enter key too long and it's treated like a shift 50% of the time.
	[_NORMAL] = LAYOUT_directional(
		KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_GRV,   KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,   KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,
		KC_SRCH,          KC_A,    KC_S,   KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH, KC_RSFT,  KC_UP,    KC_LEAD,
		KC_LCTL, KC_LALT, KC_LGUI,         UNICODE,         MO__FNCN,         KC_SPC,  KC_RGUI, KC_RALT,  KC_LEFT,  KC_DOWN,  KC_RGHT),

  // @TODO: This should be normal so the keyboard's fake vim modes don't mess with real vim commands
	[_VIM] = LAYOUT_directional(
		____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, TO_NORM, ____, ____, ____, ____, ____, ____, ____),

  // @TODO: Maybe add checks that define MPLY/MRWD/MFFD/etc based on OS of compiling machine for OS X or Win specific keys?
	[_FUNCTIONS] = LAYOUT_directional(
		____, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, ____, ____, ____, KC_DEL,
		____, ____, ____, KC_END, ____, ____, ____, KC_PGUP, ____, ____, KC_MPLY, KC_MRWD, KC_MFFD, KC_INS,
		____, ____, ____, KC_PGDN, KC_FULL, ____, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, ____, ____, ____,
		____, ____, ____, ____, ____, KC_HOME, ____, KC__MUTE, KC__VOLDOWN, KC__VOLUP, ____, ____, ____, MO__CTRL,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____),

	[_CONTROL] = LAYOUT_directional(
		RESET, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,
		____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____),
};

void eeconfig_init_user(void) {
  set_unicode_input_mode(UC_OSX);
}

/* LEADER_EXTERNS(); */

/* void matrix_scan_user(void) { */
/*   leader_dictionary() { */
/*     leading = false; */
/*     leader_end(); */

/*     seq_one_key(kc_spc) { */
/*       qk_ucis_start(); */
/*     } */
/*   } */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case UNICODE:
      // gesc doesn't work, only esc...
      // qk_ucis_start();
      break;
#ifdef AUDIO_ENABLE
    case ALLSTAR:
      PLAY_SONG(sg_allstr);
      return false;
      break;
#endif
  }
  return true;
}
