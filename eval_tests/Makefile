all:
	@#if [ -a test_main.c.test ]; then mv test_main.c.test test_main.c; fi;
	@# @-mv test_main.c.test test_main.c
	@rm -f test_exe
	@gcc -o test_exe  -Wall -Wextra -Werror -Wconversion -g -fsanitize=address test_main.c ../src/parse.c ../libft/*.c
	@./test_exe
	@# @mv test_main.c test_main.c.test
