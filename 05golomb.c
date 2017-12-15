/* https://gist.github.com/knowitkodekalender/85aa3d2a4e19126ddb2a09f5fd269eb9 */

unsigned
golomb(void)
{
	unsigned i, n, c, sum;

	for (i = n = c = sum = 0; i < sizeof(seq) / sizeof(*seq); i++) {
		seq[i] = n;
		sum += n + 1;
		if (c < seq[n]) {
			c++;
		} else {
			c = 0;
			n++;
		}
	}
	return sum;
}
