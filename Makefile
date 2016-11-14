LIBFT_SRC = ../libft/*.c
TEST_SRC = main.c tests.c
NAME = libtest

GCC = gcc -o $(NAME) $(LIBFT_SRC) $(TEST_SRC)

all: compile

compile:
	rm -rf $(NAME)
	$(GCC)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean compile
