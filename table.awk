#!/usr/bin/awk -f

# table.awk - render [delimiter-separated values](https://en.wikipedia.org/wiki/Delimiter-separated_values)
# Example usage:
#	awk -F , table.awk input.csv
#	awk -F "\t" table.awk input.tsv
#	./table.awk FS=, input.csv
#	./table.awk FS="\t" input.tsv

NR == 1 && ARGV[ARGC - 1] == FILENAME { ARGV[ARGC++] = FILENAME; }

NR == FNR {
	for (col = 1; col <= NF; col++) {
		len = length($col);
		if (len > cols[col])
			cols[col] = len;
	}
	if (NF > colcount) colcount = NF;
	next;
}

!NF || FNR == 1 { sep(); }

NF {
	for (col = 1; col <= colcount; col++)
		printf "| %-" cols[col] "s ", $col;
	print "|";
}

END { sep(); }

function sep() {
	for (col = 1; col <= colcount; col++) {
		printf "+--";
		i = cols[col];
		while (i--)
			printf "-";
	}
	print "+";
}
