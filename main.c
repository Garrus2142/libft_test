#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "tests.h"

int		main(int argc, char **argv)
{
	register_tests();

	if (argc == 1)
		test_all();
	else if (argc > 1)
		test(argv[1]);
	return (0);
}
