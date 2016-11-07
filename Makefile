LIBFT_SRC = ../libft-github/*.c
TEST_SRC = main.c tests.c
NAME = libtest

GCC = gcc -o $(NAME) $(LIBFT_SRC) $(TEST_SRC)
GCCDEBUG = gcc -o $(NAME) $(LIBFT_SRC) $(TEST_SRC)

all: compile

compile:
	rm -rf $(NAME)
	$(GCC)

debug:
	rm -rf $(NAME)
	$(GCCDEBUG)
