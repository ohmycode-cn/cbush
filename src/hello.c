#include "colour.h"
#include "hello.h"

#include <stdio.h>
#include <stdbool.h>

static void outmsg() {
    constexpr int count = {4};
    const char *array[count] = {
        "github url: https://github.com/ohmycode-cn/cbush",
        "gitee  url: https://gitee.com/freecode-cn/cbush",
        "office web: null",
        "release version: 0.0.1 beta"
    };
    auto G = colour.G;
    auto Y = colour.Y;
    auto E = colour.E;
    int  pfsize = outsize() * 2 + 7;
    char prefix[pfsize];
    snprintf(prefix, sizeof(prefix), "( %sOK%s ) ", G, E);


    for (int index = {0}; index < count; index++) { 
        printf("%s%s%s%s\n", prefix, Y, array[index], E);
    }
}

void hello(bool on_msg) {
    outmsg();
}
