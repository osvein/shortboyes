#!/usr/bin/sed -f
# ini.sed - convert ini files to c preprocessor macro directives

# comments
s_^;_//_
t

# sections
/^\[/ {
	s/^\[//
	s/]$//
	h
	s/^.*$/#define CONFIG_DEFAULT_&/
	b
}

# settings
/=/ {
	# strings
	/=[^[:digit:]][^[:digit:]]*$/ {
		# escape quotes
		s/"/\\"/g
		# quote string
		s/=/="/
		s/$/"/
	}
	G
	s/^\(.*\)=\(.*\)\n\(.*\)$/#define CONFIG_DEFAULT_\3_\1 \2/
}
