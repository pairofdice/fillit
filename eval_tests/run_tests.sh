#!/bin/sh

CFLAGS="-Wall -Wextra -Werror -g" #-fsanitize=address"
INCLUDES="-I . -I ../src/" 
#LDFLAGS="-L . -l ftprintf" #-fsanitize=address" #static library and its location

printf "\nRunning norminette...\n\n"
norminette ../ > norm_output
grep -B 1 "Error" norm_output > norm_errors
if [ -s norm_errors ]
then
	printf "Norme errors:\n"
	cat norm_errors
	exit 1
else
	printf "Norme OK\n"
fi

for f in *.test
do
	mv "$f" "${f%.test}"
done

rm norm_output norm_errors

rm -f test_exe
test_srcs="test*.c"
gcc -o test_exe $CFLAGS ../src/main.c $test_srcs $INCLUDES $LDFLAGS