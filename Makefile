NAME = uls

SRCS = src/*.c

LIB = libmx/libmx.a

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic 

all: install

install: 
	@make -C libmx/
	@clang $(CFLAGS) $(SRCS) $(LIB) -o $(NAME)
	@make clean

uninstall:
	@rm -rf $(NAME)

clean:
	@rm -rf $(LIB)	

reinstall:
	@make uninstall
	@make
