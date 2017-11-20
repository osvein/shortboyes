/* roman.c - convert integers from Arabic numerals to Roman numerals
 * without subtractive notation
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Digit {
	char sym;
	int val;
} Digit;

Digit digits[] = {
	{ 'I', 1 },
	{ 'V', 5 },
	{ 'X', 10 },
	{ 'L', 50 },
	{ 'C', 100 },
	{ 'D', 500 },
	{ 'M', 1000 }
};

int
main(int argc, char *argv[])
{
	int in;

	while (scanf("%i", &in) >= 1) {
		Digit *i;

		if (in < 0)
			putchar('-');

		in = abs(in);
		for (i = &digits[sizeof(digits) / sizeof(*digits) - 1]; i >= digits; i--) {
			int next;

			for (next = in; (next -= i->val) >= 0; in = next)
				putchar(i->sym);
		}
		putchar('\n');
	}
	if (ferror(stdin)) {
		perror(*argv);
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
