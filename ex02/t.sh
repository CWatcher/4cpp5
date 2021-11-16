#!/bin/sh

make > /dev/null		\
	&& echo make ok! 	\
	|| exit 1

echo
valgrind -q ./aa
echo "SCTarget_shrubbery file:"
cat SCTarget_shrubbery
rm SCTarget_shrubbery
