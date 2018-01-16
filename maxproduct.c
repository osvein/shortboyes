/* maxproduct.c - brute force https://julekalender.knowit.no/luker/u7wLW5PdfBjAKDs4S */

#include <stdio.h>
#include <stdlib.h>

#define VERBOSITY 1

// 9 (because one buf can't have all 10 digits) + 1 for null terminator
#define BUFLEN 10

/* 9 is going into one of the buffers anyway, and since we're dealing with
 * multiplication, which buffer starts off with 9 doesn't matter. If both
 * buffers had started off empty, we'd have seperate recursions for swapped
 * buffers, e.g. one for 12345 * 67890 and another one 67890 * 12345. This tiny
 * detail lets us double the efficiency!
 */
char buffer1[BUFLEN], buffer2[BUFLEN] = { '9' };

unsigned long max_factor1, max_factor2, max_product; // highscore
unsigned long long iterations; // number of times function recurse was called

void recurse(char *buf1, unsigned int pos1, char *buf2, unsigned int pos2, unsigned int level) {
	/* We know that when a set of digits is sorted in descending order, it
	 * makes the highest number we can get from that set of digits.
	 * Exploting this fact, we won't need seperate recursions for different
	 * orders of the same bufs. level decreases as we recurse, so that the
	 * bufs are sorted in descending order. Note that the level parameter
	 * indicates the level that was added to one of the bufs by the previous
	 * recursion, so we're decrementing it here before we add it to the bufs
	 */
	if (!--level) {
		// end of the line
		unsigned long factor1, factor2, product;
		factor1 = strtoul(buf1, NULL, 10);
		factor2 = strtoul(buf2, NULL, 10);
		// times 10 because we're optimizing away level 0
		product = factor1 * factor2 * 10;

		// new highscore!
		if (product > max_product) {
			max_factor1 = factor1;
			max_factor2 = factor2;
			max_product = product;

#if VERBOSITY > 0
			/* we append a 0 to the one of the factors because we're optimizing
			 * away level 0
			 */
			printf("%s * %s0 = %lu\t[New highscore!]\n", buf1, buf2, product);
#endif
		}
#if VERBOSITY > 1
		else {
			printf("%s * %s0 = %lu\n", buf1, buf2, product);
		}
#endif
	}
	else {
		/* The if expressions are put in place to make sure none of the bufs are
		 * empty or zero when we are done. If we are down on level 1 and one of
		 * the bufs are empty, we only go on with the recursion with which the
		 * level number (1) is added to the empty buf.
		 */

		if (level > 2 || pos2 != 0) {
			// recurse with level added to buf1
			buf1[pos1++] = '0' + level;
			recurse(buf1, pos1, buf2, pos2, level);
			buf1[--pos1] = '\0';
		}

		if (level > 2 || pos1 != 0) {
			// recurse with level added to buf2
			buf2[pos2++] = '0' + level;
			recurse(buf1, pos1, buf2, pos2, level);
			buf2[--pos2] = '\0';
		}
	}
	iterations++;
}

int main(void) {
	// level is 9 and pos2 is 1 because buf2 gets a head start
	recurse(buffer1, 0, buffer2, 1, 9);
#if VERBOSITY > 0
	fputs("Highscore: ", stdout);
#endif
	printf("%lu * %lu = %lu\n", max_factor1, max_factor2, max_product);
	fprintf(stderr, "Iterations: %llu\n", iterations);
}
