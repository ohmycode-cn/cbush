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
    const char *prefix = {"( OK ) "};
    for (int index = {0}; index < count; index++) { 
        printf("%s%s\n", prefix, array[index]);
    }
}

void hello(bool on_msg) {
    outmsg();
}
