.PHONY: all
all : main

main : main.o program_loop.o prompt.o get_line.o start_program.o background.o
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 main.o program_loop.o prompt.o get_line.o start_program.o background.o -o shell

main.o : main.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c main.c -o main.o

program_loop.o : program_loop.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c program_loop.c -o program_loop.o

prompt.o : prompt.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c prompt.c -o prompt.o

line_into_args.o : line_into_args.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c line_into_args.c -o line_into_args.o

start_program.o : start_program.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c start_program.c -o start_program.o

background.o : background.c main.h
	gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c background.c -o background.o

.PHONY: clean
clean: rm -f *.o main *.swp *~
