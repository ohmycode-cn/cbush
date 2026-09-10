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
    char *str = "FL";
    printf("%s%c%c%s%s%s%c%s%c%s", colour.Y, bracket_l(), space(), colour.R, str, colour.E, space(), colour.Y, bracket_r(), colour.E);
}

void p_allow() {
    char *str = "OK";
    printf("%s%c%c%s%s%s%c%s%c%s", colour.G, bracket_l(), space(), colour.G, str, colour.E, space(), colour.Y, bracket_r(), colour.E);
}

void p_error() {
    char *str = "ER";
    printf("%s%c%c%s%s%s%c%s%c%s", colour.G, bracket_l(), space(), colour.G, str, colour.E, space(), colour.Y, bracket_r(), colour.E);
}

void p_debug() {
    char *str = "DG";
    printf("%s%c%c%s%s%s%c%s%c%s", colour.G, bracket_l(), space(), colour.G, str, colour.E, space(), colour.Y, bracket_r(), colour.E);
}

char *o_fatal() {
    char *str = "( \033[0;31mFL\033[0;0m ) "; 
    return str;
}

char *o_allow() {
    char *str = "( \033[0;31mFL\033[0;0m ) "; 
    return str;
}

char *o_error() {
    char *str = "( \033[0;31mFL\033[0;0m ) "; 
    return str;
}

char *out_debug() {
    char *str = "( \033[0;31mFL\033[0;0m ) "; 
    return str;
}

