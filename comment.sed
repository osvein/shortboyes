#!/usr/bin/sed -f
# comment.sed - wrap standard input in a C comment block

1i\
/*
/^$/ !s/^/ /
s/^/ */
$a\
 */
