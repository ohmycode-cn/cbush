#include "prompt_header.h"
#include "colour.h"

#include <stdarg.h>
#include <stdio.h>

#define PROMPT_LABEL_WIDTH 5
#define PROMPT_FMT "%s[ %s%-*s%s ]%s "

struct PromptStyle {
    const char *text;
    const char *bracket;
    const char *label;
};

static void prompt_style(enum PromptLevel level, struct PromptStyle *style) {
    switch (level) {
    case PROMPT_OK:
        *style = (struct PromptStyle){ colour_bright_green(), colour_green(), "OK" };
        break;
    case PROMPT_DONE:
        *style = (struct PromptStyle){ colour_green(), colour_bright_green(), "DONE" };
        break;
    case PROMPT_ERROR:
        *style = (struct PromptStyle){ colour_red(), colour_bright_red(), "ERROR" };
        break;
    case PROMPT_FATAL:
        *style = (struct PromptStyle){ colour_bright_red(), colour_magenta(), "FATAL" };
        break;
    case PROMPT_WARN:
        *style = (struct PromptStyle){ colour_yellow(), colour_bright_yellow(), "WARN" };
        break;
    case PROMPT_DEBUG:
        *style = (struct PromptStyle){ colour_cyan(), colour_bright_cyan(), "DEBUG" };
        break;
    default:
        *style = (struct PromptStyle){ colour_reset(), colour_reset(), "????" };
        break;
    }
}

char *prompt_header_str(enum PromptLevel level, char *buf, size_t size) {
    if (buf == NULL || size == 0) {
        return NULL;
    }
    struct PromptStyle style;
    prompt_style(level, &style);
    snprintf(buf, size, PROMPT_FMT,
             style.bracket, style.text, PROMPT_LABEL_WIDTH, style.label,
             style.bracket, colour_reset());
    return buf;
}

void prompt_header(enum PromptLevel level) {
    struct PromptStyle style;
    prompt_style(level, &style);
    printf(PROMPT_FMT,
           style.bracket, style.text, PROMPT_LABEL_WIDTH, style.label,
           style.bracket, colour_reset());
}

void prompt_print(enum PromptLevel level, const char *fmt, ...) {
    struct PromptStyle style;
    prompt_style(level, &style);

    va_list ap;
    va_start(ap, fmt);
    int len = vsnprintf(NULL, 0, fmt, ap);
    va_end(ap);
    if (len < 0) {
        len = 0;
    }

    char msg[len + 1];
    va_start(ap, fmt);
    vsnprintf(msg, sizeof(msg), fmt, ap);
    va_end(ap);

    printf(PROMPT_FMT "%s\n",
           style.bracket, style.text, PROMPT_LABEL_WIDTH, style.label,
           style.bracket, colour_reset(), msg);
}

void p_ok(void)    { prompt_header(PROMPT_OK); }
void p_done(void)  { prompt_header(PROMPT_DONE); }
void p_error(void) { prompt_header(PROMPT_ERROR); }
void p_fatal(void) { prompt_header(PROMPT_FATAL); }
void p_warn(void)  { prompt_header(PROMPT_WARN); }
void p_debug(void) { prompt_header(PROMPT_DEBUG); }
