#!/bin/sh

make > /dev/null		\
	&& echo make ok! 	\
	|| exit 1

echo
valgrind -q ./aa
