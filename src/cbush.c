#include "cbush.h"
#include "hello.h"
#include "parser.h"
#include "prompt.h"
#include "prompt_header.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static bool should_exit(const char *line) {
    return strcmp(line, "exit") == 0 || strcmp(line, "quit") == 0;
}

void cbush() {
	char header[64];
	prompt_header_str(PROMPT_OK, header, sizeof(header));
	printf("%s%s\n", header, "entry master execute functional");
	hello(true);

	prompt_print(PROMPT_DEBUG, "parser loaded");

	struct Prompt prompt;
	prompt_init(&prompt);

	char *line = NULL;
	size_t cap = 0;

	for (;;) {
		ssize_t n = prompt_readline(&prompt, &line, &cap);
		if (n < 0) {
			printf("\n");
			break;
		}
		if (n == 0) {
			continue;
		}
		if (should_exit(line)) {
			break;
		}

		size_t buf_size = (size_t)n + 1;
		bool ret_line = true;
		char exc_list[1] = "";
		struct ParserTreeParamList ptpl = {
			.buf_size = &buf_size,
			.buf_line = line,
			.ret_line = &ret_line,
			.exc_list = exc_list,
		};
		parser(&ptpl);
	}

	free(line);
	prompt_destroy(&prompt);
}
