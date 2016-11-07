#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tests.h"
#include "constants.h"
#include "../libft-github/libft.h"

static tests g_tests[100];

static int	test_ft_memset(void)
{
	char	str1[] = "";
	char	str2[] = "Voici une phrase.";
	char	str3[] = "\n";
	char	*strd1;
	char	*strd2;
	int id1;
	int id2;

	// Test 1
	strd1 = strdup(str1);
	strd2 = strdup(str1);
	if (strcmp(ft_memset(str1, '$', 0), memset(str1, '$', 0)) != 0)
		return (1);
	free(strd1);
	free(strd2);

	// Test 2
	strd1 = strdup(str2);
	strd2 = strdup(str2);
	if (strcmp(ft_memset(str2, '$', 6), memset(str2, '$', 6)) != 0)
		return (2);
	free(strd1);
	free(strd2);

	// Test 3
	strd1 = strdup(str3);
	strd2 = strdup(str3);
	if (strcmp(ft_memset(str3, '$', 1), memset(str3, '$', 1)) != 0)
		return (3);
	free(strd1);
	free(strd2);

	// Test 4
	id1 = 5984;
	id2 = id1;
	ft_memset(&id1, 5, 2);
	memset(&id2, 5, 2);
	if (id1 != id2)
		return (4);	

	return (0);
}

static int		test_ft_bzero(void)
{
	char	*strd1;
	char	*strd2;
	int		id1;
	int		id2;
	int		len;
	int		i;

	// Test 1
	strd1 = strdup("Voici une chaine");
	strd2 = strdup("Voici une chaine");
	len = strlen(strd1);
	i = 0;
	ft_bzero(strd1, 5);
	bzero(strd2, 5);
	while (i < len)
	{
		if (strd1[i] != strd2[i])
			return (1);
		i++;
	}
	free(strd1);
	free(strd2);

	// Test 2
	strd1 = strdup("Voici une chaine");
	strd2 = strdup("Voici une chaine");
	len = strlen(strd1);
	i = 0;
	ft_bzero(strd1, 0);
	bzero(strd2, 0);
	while (i < len)
	{
		if (strd1[i] != strd2[i])
			return (2);
		i++;
	}
	free(strd1);
	free(strd2);

	// Test 2
	id1 = 2924056;
	id2 = id1;
	strd1 = (char *)&id1;
	strd2 = (char *)&id2;
	len = sizeof(id1);
	i = 0;
	ft_bzero(&id1, 4);
	ft_bzero(&id2, 4);
	while (i < len)
	{
		if (strd1[i] != strd2[i])
			return (3);
		i++;
	}

	ft_bzero(NULL, 0);
	bzero(NULL, 0);
	return (0);
}

static int		test_ft_memcpy(void)
{
	char	*strsrc;
	char	*strd1;
	char	*strd2;
	int		isrc;
	int		id1;
	int		id2;

	// Test 1
	strsrc = strdup("Coucou");
	strd1 = malloc(sizeof(char) * strlen(strsrc) + 1);
	strd2 = malloc(sizeof(char) * strlen(strsrc) + 1);
	ft_memcpy(strd1, strsrc, 4);
	memcpy(strd2, strsrc, 4);
	strd1[strlen(strsrc)] = '\0';
	strd2[strlen(strsrc)] = '\0';
	if (strcmp(strd1, strd2) != 0)
		return (1);
	free(strd1);
	free(strd2);

	// Test 2
	isrc = 42294;
	ft_memcpy(&id1, &isrc, sizeof(id1));
	memcpy(&id2, &isrc, sizeof(id2));
	if (id1 != id2)
		return (2);

	return (0);
}

static int		test_ft_memccpy(void)
{
	char	*strsrc;
	char	*strd1;
	char	*strd2;
	char	*res1;
	char	*res2;

	// Test 1
	strsrc = strdup("Voici une chaine");
	strd1 = (char *)malloc(sizeof(char) * strlen(strsrc) + 1);
	strd2 = (char *)malloc(sizeof(char) * strlen(strsrc) + 1);
	strd1[strlen(strsrc)] = '\0';
	strd2[strlen(strsrc)] = '\0';
	res1 = (char *)ft_memccpy(strd1, strsrc, 'x', 11);
	res2 = (char *)memccpy(strd2, strsrc, 'x', 11);
	if (strcmp(strd1, strd2) != 0)
		return (101);
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
		return (102);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (103);
	free(strd1);
	free(strd2);

	// Test 2
	strsrc = strdup("Voici une chaine");
	strd1 = malloc(sizeof(char) * strlen(strsrc) + 1);
	strd2 = malloc(sizeof(char) * strlen(strsrc) + 1);
	strd1[strlen(strsrc)] = '\0';
	strd2[strlen(strsrc)] = '\0';
	res1 = (char *)ft_memccpy(strd1, strsrc, 'a', 2);
	res2 = (char *)memccpy(strd2, strsrc, 'a', 2);
	if (strcmp(strd1, strd2) != 0)
		return (201);
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
		return (202);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (203);
	free(strd1);
	free(strd2);

	// Test 3
	strsrc = strdup("Voici une chaine");
	strd1 = malloc(sizeof(char) * strlen(strsrc) + 1);
	strd2 = malloc(sizeof(char) * strlen(strsrc) + 1);
	strd1[13] = '\0';
	strd2[13] = '\0';
	res1 = (char *)ft_memccpy(strd1, strsrc, 'a', 99);
	res2 = (char *)memccpy(strd2, strsrc, 'a', 99);
	if (strcmp(strd1, strd2) != 0)
		return (301);
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
		return (302);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (303);
	free(strd1);
	free(strd2);

	// Test 4
	strsrc = strdup("Voici une chaine");
	strd1 = malloc(sizeof(char) * strlen(strsrc) + 1);
	strd2 = malloc(sizeof(char) * strlen(strsrc) + 1);
	strd1[strlen(strsrc)] = '\0';
	strd2[strlen(strsrc)] = '\0';
	res1 = (char *)ft_memccpy(strd1, strsrc, 'p', 0);
	res2 = (char *)memccpy(strd2, strsrc, 'p', 0);
	if (strcmp(strd1, strd2) != 0)
		return (401);
	if (res1 == NULL && res2 != NULL)
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
		return (402);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (403);
	free(strd1);
	free(strd2);

	// Test 5
	strsrc = strdup("");
	strd1 = malloc(sizeof(char) * strlen(strsrc) + 1);
	strd2 = malloc(sizeof(char) * strlen(strsrc) + 1);
	strd1[strlen(strsrc)] = '\0';
	strd2[strlen(strsrc)] = '\0';
	res1 = (char *)ft_memccpy(strd1, strsrc, 'p', 0);
	res2 = (char *)memccpy(strd2, strsrc, 'p', 0);
	if (strcmp(strd1, strd2) != 0)
		return (501);
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
		return (502);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (503);
	free(strd1);
	free(strd2);

	return (0);
}

static int		test_ft_memmove(void)
{
	char	*strd1;
	char	*strd2;
	char	*res1;
	char	*res2;

	// Test 1
	strd1 = strdup("foo-bar");
	strd2 = strdup(strd1);
	res1 = (char *)ft_memmove(&strd1[3], &strd1[4], 4);
	res2 = (char *)memmove(&strd2[3], &strd2[4], 4);
	if (strcmp(strd1, strd2) != 0)
		return (101);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (102);
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
	   return (103);
	free(strd1);
	free(strd2);

	// Test 2
	strd1 = strdup("coucou voici une chaine");
	strd2 = strdup(strd1);
	res1 = (char *)ft_memmove(&strd1[0], &strd1[7], 5);
	res2 = (char *)memmove(&strd2[0], &strd2[7], 5);
	if (strcmp(strd1, strd2) != 0)
		return (201);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (202);
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
	   return (203);
	free(strd1);
	free(strd2);

	// Test 3
	strd1 = strdup("0123456789");
	strd2 = strdup(strd1);
	res1 = (char *)ft_memmove(strd1 + 3, strd1, 5);
	res2 = (char *)memmove(strd2 + 3, strd2, 5);
	if (strcmp(strd1, strd2) != 0)
		return (301);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (302);
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
	   return (303);
	free(strd1);
	free(strd2);

	// Test 4
	strd1 = strdup("0123456789");
	strd2 = strdup(strd1);
	res1 = (char *)ft_memmove(strd1, strd1 + 3, 5);
	res2 = (char *)memmove(strd2, strd2 + 3, 5);
	if (strcmp(strd1, strd2) != 0)
		return (401);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (402);
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
	   return (403);
	free(strd1);
	free(strd2);

	// Test 5
	strd1 = strdup("0123456789");
	strd2 = strdup(strd1);
	res1 = (char *)ft_memmove(strd1 + 3, strd1 + 3, 5);
	res2 = (char *)memmove(strd2 + 3, strd2 + 3, 5);
	if (strcmp(strd1, strd2) != 0)
		return (501);
	if ((res1 == NULL && res2 != NULL) || (res1 != NULL && res2 == NULL))
		return (502);
	if (res1 != NULL && res2 != NULL && res1[0] != res2[0])
	   return (503);
	free(strd1);
	free(strd2);

	return (0);
}

static int		test_ft_memchr(void)
{
	char	*strsrc;
	void	*res1;
	void	*res2;

	// Test 1
	strsrc = strdup("caractere a rechercher");
	res1 = ft_memchr(strsrc, 'h', strlen(strsrc));
	res2 = memchr(strsrc, 'h', strlen(strsrc));
	if (res1 != res2)
		return (1);
	free(strsrc);

	// Test 2
	strsrc = strdup("caractere a rechercher");
	res1 = ft_memchr(strsrc, 'x', strlen(strsrc));
	res2 = memchr(strsrc, 'x', strlen(strsrc));
	if (res1 != res2)
		return (2);
	free(strsrc);

	// Test 3
	strsrc = strdup("caractere a rechercher");
	res1 = ft_memchr(strsrc, 'h', 5);
	res2 = memchr(strsrc, 'h', 5);
	if (res1 != res2)
		return (3);
	free(strsrc);

	return (0);
}

void	register_tests(void)
{
	int i;

	i = 0;

	g_tests[i].name = strdup("ft_memset");
	g_tests[i].f = &test_ft_memset;
	i++;

	g_tests[i].name = strdup("ft_bzero");
	g_tests[i].f = &test_ft_bzero;
	i++;

	g_tests[i].name = strdup("ft_memcpy");
	g_tests[i].f = &test_ft_memcpy;
	i++;

	g_tests[i].name = strdup("ft_memccpy");
	g_tests[i].f = &test_ft_memccpy;
	i++;

	g_tests[i].name = strdup("ft_memmove");
	g_tests[i].f = &test_ft_memmove;
	i++;

	g_tests[i].name = strdup("ft_memchr");
	g_tests[i].f = &test_ft_memchr;
	i++;

	g_tests[i].name = NULL;
}

void	exec_test(int index)
{
	int 	res;
	char	*name;

	name = g_tests[index].name;
	
	printf("%s - ", name);

	res = g_tests[index].f();
	if (res == 0)
		printf("%sOK%s\n", C_GRN, C_NRM);
	else
		printf("%sBAD (test %i)%s\n", C_RED, res, C_NRM);
}

void	test(char *fn)
{
	int i;

	i = 0;
	while (g_tests[i].name != NULL)
	{
		if (strcmp(g_tests[i].name, fn) == 0)
		{
			exec_test(i);
			break;
		}
		i++;
	}
}

void	test_all(void)
{
	int	i;
	i = 0;
	while (g_tests[i].name != NULL)
	{
		exec_test(i);
		i++;
	}
}


