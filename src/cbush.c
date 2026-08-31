#include "cbush.h"
#include "hello.h"
#include "parser.h"

#include <stdio.h>
#include <stdbool.h>

void cbush() {
	printf("( OK ) entry master execute functional\n");
	hello(true);
	struct ParserTreeParamList ptpl;
	parser(&ptpl);
}
