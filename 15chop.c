/* https://gist.github.com/knowitkodekalender/4b633d146a7367b4f0270c6cc41962af */

void
chop(char *in, char *out)
{
	char min;

	for (min = 0; *in; ++out) {
		for (*out = 0; in[*out] > min; ++*out)
			in[*out] -= min;
		in[*out] = 0;
		min = in[*out - 1];
	}
}
