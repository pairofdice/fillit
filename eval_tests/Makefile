all: 
	@mv test_main.c.test test_main.c ;	
	@rm -f test_exe
	@gcc -o test_exe  -Wall -Wextra -Werror -Wconversion test_main.c ../src/parse.c ../libft/*.c
	@./test_exe
	@mv test_main.c test_main.c.test