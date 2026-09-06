#include "prompt_header.h"
#include "colour.h"

#include <stdio.h>

char bracket_l() {
    char lb = '(';
    return lb;
}

char bracket_r() {
    char rb = ')';
    return rb;
}

char space() {
    char se = ' ';
    return se;
}

void p_fatal() {
    char *fatal_string = "FL";
    printf("%s%c%c%s%s%s%c%s%c%s", colour.Y, bracket_l(), space(), colour.R, fatal_string, colour.E, space(), colour.Y, bracket_r(), colour.E);
}

void p_error() {}
void p_debug() {}
