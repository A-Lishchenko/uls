NAME = libmx.a

SRCS = src/*.c


CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -c

all: install clean

install:
	@clang $(CFLAGS) $(SRCS)
	@mkdir -p obj
	@mv *.o obj/
	@ar -rcs $(NAME) obj/*.o

uninstall:
	@rm -rf $(NAME)

clean:
	@rm -rfd obj
	
reinstall:
	@make uninstall
	@make
