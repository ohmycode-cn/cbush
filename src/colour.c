#include "colour.h"

#include <string.h>

#define COLOUR(name, code) \
    const char *name(void) { return "\033[" code "m"; }

COLOUR(colour_black,   "30")
COLOUR(colour_red,     "31")
COLOUR(colour_green,   "32")
COLOUR(colour_yellow,  "33")
COLOUR(colour_blue,    "34")
COLOUR(colour_magenta, "35")
COLOUR(colour_cyan,    "36")
COLOUR(colour_white,   "37")

COLOUR(colour_bright_black,   "90")
COLOUR(colour_bright_red,     "91")
COLOUR(colour_bright_green,   "92")
COLOUR(colour_bright_yellow,  "93")
COLOUR(colour_bright_blue,    "94")
COLOUR(colour_bright_magenta, "95")
COLOUR(colour_bright_cyan,    "96")
COLOUR(colour_bright_white,   "97")

COLOUR(colour_bg_black,   "40")
COLOUR(colour_bg_red,     "41")
COLOUR(colour_bg_green,   "42")
COLOUR(colour_bg_yellow,  "43")
COLOUR(colour_bg_blue,    "44")
COLOUR(colour_bg_magenta, "45")
COLOUR(colour_bg_cyan,    "46")
COLOUR(colour_bg_white,   "47")

COLOUR(colour_bg_bright_black,   "100")
COLOUR(colour_bg_bright_red,     "101")
COLOUR(colour_bg_bright_green,   "102")
COLOUR(colour_bg_bright_yellow,  "103")
COLOUR(colour_bg_bright_blue,    "104")
COLOUR(colour_bg_bright_magenta, "105")
COLOUR(colour_bg_bright_cyan,    "106")
COLOUR(colour_bg_bright_white,   "107")

COLOUR(colour_reset,         "0")
COLOUR(colour_bold,          "1")
COLOUR(colour_dim,           "2")
COLOUR(colour_italic,        "3")
COLOUR(colour_underline,     "4")
COLOUR(colour_blink,         "5")
COLOUR(colour_reverse,       "7")
COLOUR(colour_hidden,        "8")
COLOUR(colour_strikethrough, "9")

#undef COLOUR

size_t colour_width(const char *code) {
    return strlen(code);
}
