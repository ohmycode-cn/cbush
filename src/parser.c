#include "prompt_header.h"
#include "parser.h"

#include <stdbool.h>

static bool is_nullptr(struct ParserTreeParamList *ptpl) {

	if (nullptr == ptpl) {
		prompt_print(PROMPT_FATAL, "We are unsupported null pointer");
		return true;
	}
	if (nullptr == ptpl -> buf_size) {
		prompt_print(PROMPT_FATAL, "Null pointer for the struct ParserTreeParamList -> buf_size");
		return true;
	}
	if (*ptpl -> buf_size <= 0) {
		prompt_print(PROMPT_FATAL, "Buffer size less than for the zero");
		return true;
	}
	if (nullptr == ptpl -> buf_line) {
		prompt_print(PROMPT_FATAL, "Null pointer for the struct ParserTreeParamList -> buf_line");
		return true;
	}
	if (nullptr == ptpl -> ret_line) {
		prompt_print(PROMPT_FATAL, "Null pointer for the struct ParserTreeParamList -> ret_line");
		return true;
	}
	if (!*ptpl -> ret_line) {
		prompt_print(PROMPT_FATAL, "The struct ParserTreeParamList -> ret_line is false");
		return true;
	}
	if (nullptr == ptpl -> exc_list) {
		prompt_print(PROMPT_FATAL, "Null pointer for the struct ParserTreeParamList -> exc_list");
		return true;
	}
	return false;
}

void parser(struct ParserTreeParamList *ptpl) {
	if (is_nullptr(ptpl)) {
		return;
	}
}
