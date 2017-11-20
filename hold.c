#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char **argv)
{
	int c;
	char hold, countdown;

	countdown = hold = 0;
	while ((c = getchar()) != EOF) {
		if (!countdown) {
			if (hold)
				putchar(hold);
			countdown = (hold = c) - 'a';
		} else {
			putchar(c);
			countdown--;
		}
	}
	putchar(hold);
	if (ferror(stdin)) {
		perror(*argv);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
