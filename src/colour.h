#ifndef COLOUR_H
#define COLOUR_H

#include <stddef.h>

/* foreground */
const char *colour_black(void);
const char *colour_red(void);
const char *colour_green(void);
const char *colour_yellow(void);
const char *colour_blue(void);
const char *colour_magenta(void);
const char *colour_cyan(void);
const char *colour_white(void);

/* bright foreground */
const char *colour_bright_black(void);
const char *colour_bright_red(void);
const char *colour_bright_green(void);
const char *colour_bright_yellow(void);
const char *colour_bright_blue(void);
const char *colour_bright_magenta(void);
const char *colour_bright_cyan(void);
const char *colour_bright_white(void);

/* background */
const char *colour_bg_black(void);
const char *colour_bg_red(void);
const char *colour_bg_green(void);
const char *colour_bg_yellow(void);
const char *colour_bg_blue(void);
const char *colour_bg_magenta(void);
const char *colour_bg_cyan(void);
const char *colour_bg_white(void);

/* bright background */
const char *colour_bg_bright_black(void);
const char *colour_bg_bright_red(void);
const char *colour_bg_bright_green(void);
const char *colour_bg_bright_yellow(void);
const char *colour_bg_bright_blue(void);
const char *colour_bg_bright_magenta(void);
const char *colour_bg_bright_cyan(void);
const char *colour_bg_bright_white(void);

/* styles */
const char *colour_reset(void);
const char *colour_bold(void);
const char *colour_dim(void);
const char *colour_italic(void);
const char *colour_underline(void);
const char *colour_blink(void);
const char *colour_reverse(void);
const char *colour_hidden(void);
const char *colour_strikethrough(void);

size_t colour_width(const char *code);

#endif  /* COLOUR_H */
