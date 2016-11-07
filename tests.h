#ifndef TESTS_H
# define TESTS_H

void	register_tests(void);
void	test(char *fn);
void	test_all(void);

typedef	struct tests	tests;
struct	tests
{
	char *name;
	int (*f)(void);
};

#endif
