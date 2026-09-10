#include "cbush.h"
#include "prompt_header.h"

#include <stdio.h>

int main() {
	char header[64];
	prompt_header_str(PROMPT_OK, header, sizeof(header));
	printf("%s%s\n", header, "c bush release version 0.0.1");
	cbush();
	return 0;
}
