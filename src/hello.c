#include "colour.h"
#include "hello.h"
#include "prompt_header.h"

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
    auto Y = colour_yellow();
    auto E = colour_reset();

    char header[64];
    prompt_header_str(PROMPT_OK, header, sizeof(header));

    for (int index = {0}; index < count; index++) { 
        printf("%s%s%s%s\n", header, Y, array[index], E);
    }
}

void hello(bool on_msg) {
    outmsg();
}
