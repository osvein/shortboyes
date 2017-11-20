/* shiftciph.c - Caesar's shift cipher */

#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	int c, shift;

	if (argc >= 2) {
		if (sscanf(argv[1], "%i", &shift) < 1) {
			fprintf(stderr, "usage: %s [right-shift]", argv[0]);
			return EXIT_FAILURE;
		}
	} else {
		shift = 128;
	}

	while ((c = getchar()) != EOF)
		putchar(c + shift);

	return EXIT_SUCCESS;
}
