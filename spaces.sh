#!/bin/bash
sed 's/[[:space:]][[:space:]]*//g' | while read -n1 c
	do echo -n "$c$(perl -E 'say " " x '"$(($RANDOM % 3))")"
done
 
