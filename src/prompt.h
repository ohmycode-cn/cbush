#ifndef PROMPT_H
#define PROMPT_H

#include <stddef.h>
#include <sys/types.h>

struct Prompt {
    char *user;
    char *host;
    char *cwd;
    size_t cwd_cap;
};

void prompt_init(struct Prompt *p);
void prompt_destroy(struct Prompt *p);

int prompt_refresh(struct Prompt *p);

char *prompt_render(const struct Prompt *p, char *buf, size_t size);

ssize_t prompt_readline(struct Prompt *p, char **line, size_t *cap);

#endif  /* PROMPT_H */
