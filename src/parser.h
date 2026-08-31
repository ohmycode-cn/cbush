#ifndef PARSER_H
#define PARSER_H

#include <stdbool.h>
#include <stddef.h>

struct ParserTreeParamList {
	size_t *buf_size; // Buffer lines size of unit: bytes(FORCE)
	char *buf_line;   // Buffer lines
	bool *ret_line;   // Parser buffer line result
	char *exc_list;   // Legal buffer lines (at in parser line after)
};

void parser(struct ParserTreeParamList *ptpl);

#endif /* PARSER_H */
