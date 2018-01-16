#!/bin/bash
while true
	do for i in 41 43 42 46 44 45 #{40..47}
#		do echo -e "\033[${i}m"
		do printf "\033[%dm" "$i"
		sleep 0.1
	done
done
