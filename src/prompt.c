#define _POSIX_C_SOURCE 200809L

#include "prompt.h"
#include "colour.h"

#include <errno.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void prompt_init(struct Prompt *p) {
    p->user = NULL;
    p->host = NULL;
    p->cwd = NULL;
    p->cwd_cap = 0;

    struct passwd *pw = getpwuid(getuid());
    p->user = strdup(pw && pw->pw_name ? pw->pw_name : "user");

    char hostbuf[256] = {0};
    if (gethostname(hostbuf, sizeof(hostbuf)) != 0) {
        strcpy(hostbuf, "host");
    }
    hostbuf[sizeof(hostbuf) - 1] = '\0';
    char *dot = strchr(hostbuf, '.');
    if (dot != NULL) {
        *dot = '\0';
    }
    p->host = strdup(hostbuf);
}

void prompt_destroy(struct Prompt *p) {
    free(p->user);
    free(p->host);
    free(p->cwd);
    p->user = NULL;
    p->host = NULL;
    p->cwd = NULL;
    p->cwd_cap = 0;
}

int prompt_refresh(struct Prompt *p) {
    if (p->cwd_cap == 0) {
        p->cwd_cap = 256;
        p->cwd = malloc(p->cwd_cap);
        if (p->cwd == NULL) {
            return -1;
        }
    }
    for (;;) {
        if (getcwd(p->cwd, p->cwd_cap) != NULL) {
            return 0;
        }
        if (errno != ERANGE) {
            p->cwd[0] = '?';
            p->cwd[1] = '\0';
            return 0;
        }
        p->cwd_cap *= 2;
        char *grown = realloc(p->cwd, p->cwd_cap);
        if (grown == NULL) {
            return -1;
        }
        p->cwd = grown;
    }
}

char *prompt_render(const struct Prompt *p, char *buf, size_t size) {
    int root = (geteuid() == 0);
    const char *sym = root ? "#" : "$";
    const char *sym_colour = root ? colour_red() : colour_green();

    snprintf(buf, size, "%s%s%s@%s%s%s:%s%s%s %s%s%s ",
             colour_green(), p->user,
             colour_reset(), colour_blue(), p->host,
             colour_reset(), colour_cyan(), p->cwd,
             colour_reset(), sym_colour, sym, colour_reset());
    return buf;
}

ssize_t prompt_readline(struct Prompt *p, char **line, size_t *cap) {
    prompt_refresh(p);

    char header[512];
    prompt_render(p, header, sizeof(header));
    fputs(header, stdout);
    fflush(stdout);

    ssize_t n = getline(line, cap, stdin);
    if (n < 0) {
        return n;
    }
    while (n > 0 && ((*line)[n - 1] == '\n' || (*line)[n - 1] == '\r')) {
        (*line)[--n] = '\0';
    }
    return n;
}
