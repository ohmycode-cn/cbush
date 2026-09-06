#include "prompt_header.h"
#include "parser.h"
#include "next.h"

#include <stdio.h>
#include <stdbool.h>

static bool is_nullptr(struct ParserTreeParamList *ptpl) {

	if (nullptr == ptpl) {
		printf("( FL ) We are unsupported null pointer"); 
		next();
		return true;
	}
	if (nullptr == ptpl -> buf_size) {
        p_fatal();
		printf(" Null pointer for the struct ParserTreeParamList -> buf_size");
		next();
		return true;
	}
	if (0 <= *ptpl -> buf_size) {
		printf("( FL ) Buffer size less than for the zero");
		next();
		return true;
	}
	if (nullptr == ptpl -> buf_line) {
		printf("( FL ) Null pointer for the struct ParserTreeParamList -> buf_line");
		next();
		return true;
	}
	if (nullptr == ptpl -> ret_line) {
		printf("( FL ) Null pointer for the struct ParserTreeParamList -> ret_line");
		next();
		return true;
	}
    if (!*ptpl -> ret_line) {
		printf("( FL ) The struct ParserTreeParamList -> ret_line is false");
        next();
        return true;
    }
	if (nullptr == ptpl -> exc_list) {
        p_fatal();
		printf(" Null pointer for the struct ParserTreeParamList -> exc_list");
		next();
		return true;
	}
	return false;
}

void parser(struct ParserTreeParamList *ptpl) {
	printf("( DG ) Loaded functional 'parser(...)' done");
	next();
	if (is_nullptr(ptpl)) {
		return;
	}
}
