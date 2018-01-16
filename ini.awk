#!/usr/bin/awk -f
# ini.awk - reformat an ini file to a user specified format
# command line options (using -v, see awk documentation):
# - section - default section (for settings before the first section header)
# - fmt_comment - comment output format (%1s = comment)
# - fmt_section - section header output format (%1s = section name)
# - fmt_setting - setting output format (%1s = section, %2s = key, %3s = value)
# leave out a fmt_ option to disable output of entries of that type
# example usage:
# $ ./ini.awk -v 'section="NULL"'\
# >           -v 'fmt_comment="//%s"'\
# >           -v 'fmt_section="\n#define INI_%s"'\
# >           -v 'fmt_setting="#define INI_%s_%s %s"'\
# >           config.ini > ini.h
# $ ./ini.awk -v 'section="global"'\
# >           -v 'fmt_comment="//%s"'\
# >           -v 'fmt_section="//[%s]//"'\
# >           -v 'fmt_setting="const char *setting_%s_%s = %s"'\
# >           settings.ini > settings.h

BEGIN {
	FS = "[\[\]]";
}

# emtpy line
!$0 { next; }

# comment
sub(/^;/, "") {
	if (fmt_comment) printf(fmt_comment "\n", $0);
	next;
}

# section
/^\[/ {
	section = $2;
	if (fmt_section) printf(fmt_section, $2);
	next;
}

# setting
fmt_setting && /=/ {
	sep = index($0, "=");
	printf(fmt_setting "\n", section, substr($0, 1, sep-1), substr($0, sep+1));
	next;
}
