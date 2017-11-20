/* xorciph.c - simple xor cipher */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	const char *i;
	int c;

	if (argc < 2) {
		fprintf(stderr, "usage: %s key", argv[0]);
		return EXIT_FAILURE;
	}

	for (i = argv[1]; (c = getchar()) != EOF; *i ? i++ : (i = argv[1]))
		putchar(c ^ *i);

	return EXIT_SUCCESS;
}
