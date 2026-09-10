#ifndef PROMPT_HEADER_H
#define PROMPT_HEADER_H

#include <stddef.h>

enum PromptLevel {
    PROMPT_OK,
    PROMPT_DONE,
    PROMPT_ERROR,
    PROMPT_FATAL,
    PROMPT_WARN,
    PROMPT_DEBUG,
};

void prompt_header(enum PromptLevel level);

void prompt_print(enum PromptLevel level, const char *fmt, ...);

char *prompt_header_str(enum PromptLevel level, char *buf, size_t size);

void p_ok(void);
void p_done(void);
void p_error(void);
void p_fatal(void);
void p_warn(void);
void p_debug(void);

#endif  /* PROMPT_HEADER_H */
