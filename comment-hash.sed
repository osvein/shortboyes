#!/usr/bin/sed -f
# comment-hash.sed - wrap standard input in a number sign line comment block

/^$/ !s/^/ /
s/^/#/
