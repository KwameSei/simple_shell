.PHONY: all
all : main

<<<<<<< HEAD
main : main.o program_loop.o prompt.o get_line.o start_program.o background.o
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 main.o program_loop.o prompt.o get_line.o start_program.o background.o -o shell
=======
main : main.o program_loop.o prompt.o line_into_args.o execute.o start_program.o background.o built_in_cmd.o
	gcc -Wall -pedantic -Werror -Wextra -std=gnu99 main.o program_loop.o prompt.o line_into_args.o execute.o start_program.o background.o built_in_cmd.o -o shell
>>>>>>> ffebb02e9e90f3cf5c9cbda853b1f6f16104e2a6

main.o : main.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu99 -c main.c -o main.o

program_loop.o : program_loop.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu99 -c program_loop.c -o program_loop.o

prompt.o : prompt.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu99 -c prompt.c -o prompt.o

line_into_args.o : line_into_args.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu99 -c line_into_args.c -o line_into_args.o

start_program.o : start_program.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu99 -c start_program.c -o start_program.o

background.o : background.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu99 -c background.c -o background.o

/*built_in_cmd.o : built_in_cmd.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c built_in_cmd.c -o built_in_cmd.o*/
/*execute.o : execute.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c execute.c -o execute.o */

.PHONY: clean 
clean: -rm -f *.o main *.swp *~
