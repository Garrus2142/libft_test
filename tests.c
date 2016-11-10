#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
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

static int	test_ft_memcmp(void)
{
	char	*strd1;
	char	*strd2;
	int		id1;
	int		id2;
	int		res1;
	int		res2;

	// Test 1
	strd1 = strdup("");
	strd2 = strdup("");
	res1 = ft_memcmp(strd1, strd2, 0);
	res2 = memcmp(strd1, strd2, 0);
	if (res1 != res2)
		return (1);
	free(strd1);
	free(strd2);

	// Test 2
	strd1 = strdup("Chaine identique");
	strd2 = strdup(strd1);
	res1 = ft_memcmp(strd1, strd2, strlen(strd1));
	res2 = memcmp(strd1, strd2, strlen(strd1));
	if (res1 != res2)
		return (2);
	free(strd1);
	free(strd2);

	// Test 3
	strd1 = strdup("Chaine differente");
	strd2 = strdup("Chaine pas identique");
	res1 = ft_memcmp(strd1, strd2, strlen(strd1));
	res2 = memcmp(strd1, strd2, strlen(strd1));
	if (res1 != res2)
		return (3);
	free(strd1);
	free(strd2);

	// Test 4
	strd1 = strdup("Chaine pas identique");
	strd2 = strdup("Chaine differente");
	res1 = ft_memcmp(strd1, strd2, strlen(strd2));
	res2 = memcmp(strd1, strd2, strlen(strd2));
	if (res1 != res2)
		return (4);
	free(strd1);
	free(strd2);

	// Test 5
	id1 = 84025;
	id2 = 84025;
	res1 = ft_memcmp(&id1, &id2, sizeof(id1));
	res2 = memcmp(&id1, &id2, sizeof(id1));
	if (res1 != res2)
		return (5);

	// Test 6
	id1 = 84025;
	id2 = 84024264;
	res1 = ft_memcmp(&id1, &id2, sizeof(id1));
	res2 = memcmp(&id1, &id2, sizeof(id1));
	if (res1 != res2)
		return (6);

	return (0);
}

static int	test_ft_strlen(void)
{
	char	*str;
	int		res1;
	int		res2;

	// Test 1
	str = strdup("taille de la chaine");
	res1 = ft_strlen(str);
	res2 = strlen(str);
	if (res1 != res2)
		return (1);
	free(str);

	// Test 2
	str = strdup("");
	res1 = ft_strlen(str);
	res2 = strlen(str);
	if (res1 != res2)
		return (2);
	free(str);

	return (0);
}

static int	test_ft_strdup(void)
{
	char	*strsrc;
	char	*strd1;
	char	*strd2;

	// Test 1
	strsrc = strdup("Voici une chaine");
	strd1 = ft_strdup(strsrc);
	strd2 = strdup(strsrc);
	if (strcmp(strd1, strd2) != 0)
		return (1);
	free(strsrc);
	free(strd1);
	free(strd2);

	// Test 2
	strsrc = strdup("");
	strd1 = ft_strdup(strsrc);
	strd2 = strdup(strsrc);
	if (strcmp(strd1, strd2))
		return (2);
	free(strsrc);
	free(strd1);
	free(strd2);

	return (0);
}

static int	test_ft_strcpy(void)
{
	char	*strsrc;
	char	*strd1;
	char	*strd2;
	char	*res1;
	char	*res2;

	// Test 1
	strsrc = strdup("Coucou");
	strd1 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 1);
	strd2 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 1);
	res1 = ft_strcpy(strd1, strsrc);
	res2 = strcpy(strd2, strsrc);
	if (strcmp(strd1, strd2) != 0)
		return (101);
	if (memcmp(strd1, strd2, strlen(strsrc) + 1) != 0)
		return (102);
	free(strsrc);
	free(strd1);
	free(strd2);

	// Test 2
	strsrc = strdup("");
	strd1 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 1);
	strd2 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 1);
	res1 = ft_strcpy(strd1, strsrc);
	res2 = strcpy(strd2, strsrc);
	if (strcmp(strd1, strd2) != 0)
		return (201);
	if (memcmp(strd1, strd2, strlen(strsrc) + 1) != 0)
		return (202);
	free(strsrc);
	free(strd1);
	free(strd2);

	return (0);
}

static int	test_ft_strncpy(void)
{
	char	*strsrc;
	char	*strd1;
	char	*strd2;
	char	*res1;
	char	*res2;

	// Test 1
	strsrc = strdup("Coucou");
	strd1 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 1);
	strd2 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 1);
	res1 = ft_strncpy(strd1, strsrc, strlen(strsrc) + 1);
	res2 = strncpy(strd2, strsrc, strlen(strsrc) + 1);
	if (strcmp(strd1, strd2) != 0)
		return (101);
	if (memcmp(strd1, strd2, strlen(strsrc) + 1) != 0)
		return (102);
	free(strsrc);
	free(strd1);
	free(strd2);

	// Test 2
	strsrc = strdup("Coucou");
	strd1 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 10);
	strd2 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 10);
	res1 = ft_strncpy(strd1, strsrc, strlen(strsrc) + 10);
	res2 = strncpy(strd2, strsrc, strlen(strsrc) + 10);
	if (strcmp(strd1, strd2) != 0)
		return (201);
	if (memcmp(strd1, strd2, strlen(strsrc) + 10) != 0)
		return (202);
	free(strsrc);
	free(strd1);
	free(strd2);

	// Test 3
	strsrc = strdup("Coucou");
	strd1 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 1);
	strd2 = (char *)malloc(sizeof(strsrc) * strlen(strsrc) + 1);
	memset(strd1, '$', strlen(strsrc) + 1);
	memset(strd2, '$', strlen(strsrc) + 1);
	res1 = ft_strncpy(strd1, strsrc, 3);
	res2 = strncpy(strd2, strsrc, 3);
	if (memcmp(strd1, strd2, 4) != 0)
		return (301);
	free(strsrc);
	free(strd1);
	free(strd2);


	return (0);
}

static int	test_ft_strcat(void)
{
	char	*stradd;
	char	strd1[150];
	char	strd2[150];
	char	*res1;
	char	*res2;

	// Test 1
	stradd = strdup(" 2eme chaine");
	strcpy(strd1, "Debut de la chaine");
	strcpy(strd2, strd1);
	res1 = ft_strcat(strd1, stradd);
	res2 = strcat(strd2, stradd);
	if (strcmp(strd1, strd2) != 0)
		return (101);
	if (res1[0] != res2[0])
		return (102);
	free(stradd);

	// Test 2
	stradd = strdup(" 2eme chaine");
	strcpy(strd1, "");
	strcpy(strd2, strd1);
	res1 = ft_strcat(strd1, stradd);
	res2 = strcat(strd2, stradd);
	if (strcmp(strd1, strd2) != 0)
		return (201);
	if (res1[0] != res2[0])
		return (202);
	free(stradd);

	// Test 3
	stradd = strdup("");
	strcpy(strd1, "Debut de la chaine");
	strcpy(strd2, strd1);
	res1 = ft_strcat(strd1, stradd);
	res2 = strcat(strd2, stradd);
	if (strcmp(strd1, strd2) != 0)
		return (301);
	if (res1[0] != res2[0])
		return (302);
	free(stradd);

	return (0);
}

static int	test_ft_strncat(void)
{
	char	*stradd;
	char	strd1[150];
	char	strd2[150];
	char	*res1;
	char	*res2;

	// Test 1
	stradd = strdup(" 2eme chaine");
	strcpy(strd1, "Debut de la chaine");
	strcpy(strd2, strd1);
	res1 = ft_strncat(strd1, stradd, 5);
	res2 = strncat(strd2, stradd, 5);
	if (strcmp(strd1, strd2) != 0)
		return (101);
	if (res1[0] != res2[0])
		return (102);
	free(stradd);

	// Test 2
	stradd = strdup(" 2eme chaine");
	strcpy(strd1, "");
	strcpy(strd2, strd1);
	res1 = ft_strncat(strd1, stradd, 5);
	res2 = strncat(strd2, stradd, 5);
	if (strcmp(strd1, strd2) != 0)
		return (201);
	if (res1[0] != res2[0])
		return (202);
	free(stradd);

	// Test 3
	stradd = strdup("");
	strcpy(strd1, "Debut de la chaine");
	strcpy(strd2, strd1);
	res1 = ft_strncat(strd1, stradd, 5);
	res2 = strncat(strd2, stradd, 5);
	if (strcmp(strd1, strd2) != 0)
		return (301);
	if (res1[0] != res2[0])
		return (302);
	free(stradd);

	// Test 4
	stradd = strdup("Coucou");
	strcpy(strd1, "Debut de la chaine");
	strcpy(strd2, strd1);
	res1 = ft_strncat(strd1, stradd, 99);
	res2 = strncat(strd2, stradd, 99);
	if (strcmp(strd1, strd2) != 0)
		return (401);
	if (res1[0] != res2[0])
		return (402);
	free(stradd);

	// Test 5
	stradd = strdup("Coucou");
	strcpy(strd1, "Debut de la chaine");
	strcpy(strd2, strd1);
	res1 = ft_strncat(strd1, stradd, 0);
	res2 = strncat(strd2, stradd, 0);
	if (strcmp(strd1, strd2) != 0)
		return (501);
	if (res1[0] != res2[0])
		return (502);
	free(stradd);

	return (0);
}

static int	test_ft_strlcat(void)
{
	char	*strsrc;
	char	*strd1;
	char	*strd2;
	size_t	res1;
	size_t	res2;

	// Test 1
	strsrc = strdup("6789");
	strd1 = (char *)malloc(sizeof(char) * 10);
	strd2 = (char *)malloc(sizeof(char) * 10);
	strcpy(strd1, "12345");
	strcpy(strd2, strd1);
	res1 = ft_strlcat(strd1, strsrc, 10);
	res2 = strlcat(strd2, strsrc, 10);
	if (strcmp(strd1, strd2) != 0)
		return (101);
	if (res1 != res2)
		return (102);
	free(strsrc);
	free(strd1);
	free(strd2);

	// Test 2
	strsrc = strdup("");
	strd1 = (char *)malloc(sizeof(char) * 10);
	strd2 = (char *)malloc(sizeof(char) * 10);
	strcpy(strd1, "12345");
	strcpy(strd2, strd1);
	res1 = ft_strlcat(strd1, strsrc, 10);
	res2 = strlcat(strd2, strsrc, 10);
	if (strcmp(strd1, strd2) != 0)
		return (201);
	if (res1 != res2)
		return (202);
	free(strsrc);
	free(strd1);
	free(strd2);

	// Test 3
	strsrc = strdup("6789");
	strd1 = (char *)malloc(sizeof(char) * 10);
	strd2 = (char *)malloc(sizeof(char) * 10);
	strcpy(strd1, "12345");
	strcpy(strd2, strd1);
	res1 = ft_strlcat(strd1, strsrc, 3);
	res2 = strlcat(strd2, strsrc, 3);
	if (strcmp(strd1, strd2) != 0)
		return (301);
	if (res1 != res2)
		return (302);
	free(strsrc);
	free(strd1);
	free(strd2);

	// Test 4
	strsrc = strdup("6789");
	strd1 = (char *)malloc(sizeof(char) * 10);
	strd2 = (char *)malloc(sizeof(char) * 10);
	strcpy(strd1, "123");
	strcpy(strd2, strd1);
	res1 = ft_strlcat(strd1, strsrc, 4);
	res2 = strlcat(strd2, strsrc, 4);
	if (strcmp(strd1, strd2) != 0)
		return (401);
	if (res1 != res2)
		return (402);
	free(strsrc);
	free(strd1);
	free(strd2);

	return (0);
}

static int	test_ft_strchr(void)
{
	char	*strsrc;
	char	*res1;
	char	*res2;

	// Test 1
	strsrc = strdup("12345");
	res1 = ft_strchr(strsrc, '3');
	res2 = strchr(strsrc, '3');
	if (res1 != res2)
		return (1);
	free(strsrc);

	// Test 2
	strsrc = strdup("12345");
	res1 = ft_strchr(strsrc, '\0');
	res2 = strchr(strsrc, '\0');
	if (res1 != res2)
		return (2);
	free(strsrc);

	// Test 3
	strsrc = strdup("12345");
	res1 = ft_strchr(strsrc, 'x');
	res2 = strchr(strsrc, 'x');
	if (res1 != res2)
		return (3);
	free(strsrc);

	// Test 4
	strsrc = strdup("aaaaa");
	res1 = ft_strchr(strsrc, 'a');
	res2 = strchr(strsrc, 'a');
	if (res1 != res2)
		return (4);
	free(strsrc);

	return (0);
}

static int	test_ft_strrchr(void)
{
	char	*strsrc;
	char	*res1;
	char	*res2;

	// Test 1
	strsrc = strdup("12345");
	res1 = ft_strrchr(strsrc, '3');
	res2 = strrchr(strsrc, '3');
	if (res1 != res2)
		return (1);
	free(strsrc);

	// Test 2
	strsrc = strdup("12345");
	res1 = ft_strrchr(strsrc, '\0');
	res2 = strrchr(strsrc, '\0');
	if (res1 != res2)
		return (2);
	free(strsrc);

	// Test 3
	strsrc = strdup("12345");
	res1 = ft_strrchr(strsrc, 'x');
	res2 = strrchr(strsrc, 'x');
	if (res1 != res2)
		return (3);
	free(strsrc);

	// Test 4
	strsrc = strdup("aaaaa");
	res1 = ft_strrchr(strsrc, 'a');
	res2 = strrchr(strsrc, 'a');
	if (res1 != res2)
		return (4);
	free(strsrc);

	return (0);
}

static int	test_ft_strstr(void)
{
	char	*strsrc;
	char	*res1;
	char	*res2;

	// Test 1
	strsrc = strdup("Voici une chaine");
	res1 = ft_strstr(strsrc, "une");
	res2 = strstr(strsrc, "une");
	if (res1 != res2)
		return (1);
	free(strsrc);

	// Test 2
	strsrc = strdup("Voici une chaine");
	res1 = ft_strstr(strsrc, "");
	res2 = strstr(strsrc, "");
	if (res1 != res2)
		return (2);
	free(strsrc);

	// Test 3
	strsrc = strdup("Voici une chaine");
	res1 = ft_strstr(strsrc, "unec");
	res2 = strstr(strsrc, "unec");
	if (res1 != res2)
		return (3);
	free(strsrc);

	// Test 4
	strsrc = strdup("");
	res1 = ft_strstr(strsrc, "unec");
	res2 = strstr(strsrc, "unec");
	if (res1 != res2)
		return (4);
	free(strsrc);

	// Test 5
	strsrc = strdup("UNECNUNECNE");
	res1 = ft_strstr(strsrc, "UNECNE");
	res2 = strstr(strsrc, "UNECNE");
	if (res1 != res2)
		return (5);
	free(strsrc);

	// Test 6
	strsrc = strdup("unec");
	res1 = ft_strstr(strsrc, "unec");
	res2 = strstr(strsrc, "unec");
	if (res1 != res2)
		return (6);
	free(strsrc);

	return (0);
}

static int	test_ft_strnstr(void)
{
	char	*strsrc;
	char	*res1;
	char	*res2;

	// Test 1
	strsrc = strdup("Voici une chaine");
	res1 = ft_strnstr(strsrc, "une", 99);
	res2 = strnstr(strsrc, "une", 99);
	if (res1 != res2)
		return (1);
	free(strsrc);

	// Test 2
	strsrc = strdup("Voici une chaine");
	res1 = ft_strnstr(strsrc, "une", 8);
	res2 = strnstr(strsrc, "une", 8);
	if (res1 != res2)
		return (2);
	free(strsrc);

	// Test 3
	strsrc = strdup("voici");
	res1 = ft_strnstr(strsrc, "voici", 5);
	res2 = strnstr(strsrc, "voici", 5);
	if (res1 != res2)
		return (3);
	free(strsrc);

	// Test 4
	strsrc = strdup("");
	res1 = ft_strnstr(strsrc, "une", 3);
	res2 = strnstr(strsrc, "une", 3);
	if (res1 != res2)
		return (4);
	free(strsrc);

	// Test 5
	strsrc = strdup("Voici unxe chaine");
	res1 = ft_strnstr(strsrc, "une", 99);
	res2 = strnstr(strsrc, "une", 99);
	if (res1 != res2)
		return (5);
	free(strsrc);

	return (0);
}

static int	test_ft_strcmp(void)
{
	char	*str1;
	char	*str2;
	int		res1;
	int		res2;

	// Test 1
	str1 = strdup("Chaine identique");
	str2 = strdup(str1);
	res1 = ft_strcmp(str1, str2);
	res2 = strcmp(str1, str2);
	if (res1 != res2)
		return (1);
	free(str1);
	free(str2);

	// Test 2
	str1 = strdup("Chaine differente");
	str2 = strdup("Chaine diferrente");
	res1 = ft_strcmp(str1, str2);
	res2 = strcmp(str1, str2);
	if (res1 != res2)
		return (2);
	free(str1);
	free(str2);

	// Test 3
	str1 = strdup("");
	str2 = strdup("");
	res1 = ft_strcmp(str1, str2);
	res2 = strcmp(str1, str2);
	if (res1 != res2)
		return (3);
	free(str1);
	free(str2);

	return (0);
}

static int	test_ft_strncmp(void)
{
	char	*str1;
	char	*str2;
	int		res1;
	int		res2;

	// Test 1
	str1 = strdup("Chaine identique");
	str2 = strdup(str1);
	res1 = ft_strncmp(str1, str2, 5);
	res2 = strncmp(str1, str2, 5);
	if (res1 != res2)
		return (1);
	free(str1);
	free(str2);

	// Test 2
	str1 = strdup("Chaine identique");
	str2 = strdup(str1);
	res1 = ft_strncmp(str1, str2, 99);
	res2 = strncmp(str1, str2, 99);
	if (res1 != res2)
		return (2);
	free(str1);
	free(str2);

	// Test 3
	str1 = strdup("Chaine differente");
	str2 = strdup("Chaine differrente");
	res1 = ft_strncmp(str1, str2, 5);
	res2 = strncmp(str1, str2, 5);
	if (res1 != res2)
		return (3);
	free(str1);
	free(str2);

	// Test 4
	str1 = strdup("Chaine differente");
	str2 = strdup("Chaine differrente");
	res1 = ft_strncmp(str1, str2, 99);
	res2 = strncmp(str1, str2, 99);
	if (res1 != res2)
		return (4);
	free(str1);
	free(str2);

	// Test 5
	str1 = strdup("Chaine differente");
	str2 = strdup("Chaine differrente");
	res1 = ft_strncmp(str1, str2, 0);
	res2 = strncmp(str1, str2, 0);
	if (res1 != res2)
		return (3);
	free(str1);
	free(str2);

	return (0);
}

static int	test_ft_atoi(void)
{
	char	*src;
	int		res1;
	int		res2;

	// Test 1
	src = strdup("   -85 51");
	res1 = ft_atoi(src);
	res2 = atoi(src);
	if (res1 != res2)
		return (1);
	free(src);

	// Test 2
	src = strdup("hello45world");
	res1 = ft_atoi(src);
	res2 = atoi(src);
	if (res1 != res2)
		return (2);
	free(src);

	// Test 3
	src = strdup("4-1");
	res1 = ft_atoi(src);
	res2 = atoi(src);
	if (res1 != res2)
		return (3);
	free(src);

	// Test 4
	src = strdup("+857");
	res1 = ft_atoi(src);
	res2 = atoi(src);
	if (res1 != res2)
		return (4);
	free(src);

	// Test 5
	src = strdup("2147483647");
	res1 = ft_atoi(src);
	res2 = atoi(src);
	if (res1 != res2)
		return (5);

	// Test 6
	src = strdup("-2147483648");
	res1 = ft_atoi(src);
	res2 = atoi(src);
	if (res1 != res2)
		return (6);

	// Test 7
	src = strdup("-2147483651");
	res1 = ft_atoi(src);
	res2 = atoi(src);
	if (res1 != res2)
		return (7);

	return (0);
}

static int	test_ft_isalpha(void)
{
	int		res1;
	int		res2;

	// Test 1
	res1 = ft_isalpha('a');
	res2 = isalpha('a');
	if (res1 != res2)
		return (1);

	// Test 2
	res1 = ft_isalpha('\0');
	res2 = isalpha('\0');
	if (res1 != res2)
		return (2);

	// Test 3
	res1 = ft_isalpha('6');
	res2 = isalpha('6');
	if (res1 != res2)
		return (3);

	// Test 4
	res1 = ft_isalpha(' ');
	res2 = isalpha(' ');
	if (res1 != res2)
		return (4);

	return (0);
}

static int	test_ft_isdigit(void)
{
	int	res1;
	int	res2;

	// Test 1
	res1 = ft_isdigit(' ');
	res2 = isdigit(' ');
	if (res1 != res2)
		return (1);

	// Test 2
	res1 = ft_isdigit('\n');
	res2 = isdigit('\n');
	if (res1 != res2)
		return (2);

	// Test 3
	res1 = ft_isdigit('5');
	res2 = isdigit('5');
	if (res1 != res2)
		return (3);
	
	// Test 4
	res1 = ft_isdigit(EOF);
	res2 = isdigit(EOF);
	if (res1 != res2)
		return (4);

	// Test 5
	res1 = ft_isdigit(-1);
	res2 = isdigit(-1);
	if (res1 != res2)
		return (5);

	// Test 6
	res1 = ft_isdigit(529);
	res2 = isdigit(529);
	if (res1 != res2)
		return (6);

	return (0);
}

static int	test_ft_isalnum(void)
{
	int		res1;
	int		res2;

	// Test 1
	res1 = ft_isalnum('a');
	res2 = isalnum('a');
	if (res1 != res2)
		return (1);

	// Test 2
	res1 = ft_isalnum('\0');
	res2 = isalnum('\0');
	if (res1 != res2)
		return (2);

	// Test 3
	res1 = ft_isalnum('6');
	res2 = isalnum('6');
	if (res1 != res2)
		return (3);

	// Test 4
	res1 = ft_isalnum(' ');
	res2 = isalnum(' ');
	if (res1 != res2)
		return (4);

	// Test 5
	res1 = ft_isalnum('@');
	res2 = isalnum('@');
	if (res1 != res2)
		return (5);

	return (0);
}

static int	test_ft_isascii(void)
{
	int	i;

	// Test 1
	i = -1;
	while (i < 530)
	{
		if (ft_isascii(i) != isascii(i))
			return (1);
		i++;
	}
	
	return (0);
}

static int	test_ft_isprint(void)
{
	int	i;

	// Test 1
	i = -1;
	while (i < 530)
	{
		if (ft_isprint(i) != isprint(i))
			return (1);
		i++;
	}
	
	return (0);
}

static int	test_ft_toupper(void)
{
	int i;

	// Test 1
	i = -1;
	while (i < 530)
	{
		if (ft_toupper(i) != toupper(i))
			return (1);
		i++;
	}
	
	return (0);
}

static int	test_ft_tolower(void)
{
	int i;

	// Test 1
	i = -1;
	while (i < 530)
	{
		if (ft_tolower(i) != tolower(i))
			return (1);
		i++;
	}
	
	return (0);
}

static int	test_ft_memalloc(void)
{
	unsigned char	*mem;
	size_t	size;
	size_t	i;

	// Test 1;
	i = 0;
	mem = (unsigned char *)ft_memalloc(999);
	while (i < size)
	{
		if (mem[i] != 0)
			return (1);
		i++;
	}
	free(mem);

	return (0);
}

static int	test_ft_memdel(void)
{
	void	*mem;
	
	// Test 1
	mem = malloc(99);
	ft_memdel(&mem);
	if (mem != NULL)
		return (1);
	
	return (0);
}

static int	test_ft_strnew(void)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strnew(100);
	while (i < 100)
	{
		if (str[i] != '\0')
			return (1);
		i++;
	}
	free(str);

	return (0);
}

static int	test_ft_strdel(void)
{
	char	*str;
	
	// Test 1
	str = (char *)malloc(99);
	memset(str, '$', 99);
	ft_strdel(&str);
	if (str != NULL)
		return (1);

	return (0);
}

static int	test_ft_strclr(void)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("coucou");
	ft_strclr(str);
	while (i < strlen(str) + 1)
	{
		if (str[i] != '\0')
			return (1);
		i++;
	}
	free(str);

	return (0);
}

static void fptr_ft_striter(char *c)
{
	*c = '$';
}

static int	test_ft_striter(void)
{
	char	*str;

	// Test 1
	str = strdup("Coucou");
	ft_striter(str, &fptr_ft_striter);
	if (strcmp(str, "$$$$$$") != 0)
		return (1);
	free(str);

	return (0);
}

static void fptr_ft_striteri(unsigned int i, char *c)
{
	if (i == 3)
		*c = '3';
	else
		*c = '$';
}

static int	test_ft_striteri(void)
{
	char	*str;

	// Test 1
	str = strdup("Coucou");
	ft_striteri(str, &fptr_ft_striteri);
	if (strcmp(str, "$$$3$$") != 0)
		return (1);
	free(str);

	return (0);
}

static char fptr_ft_strmap(char c)
{
	return toupper(c);
}

static int	test_ft_strmap(void)
{
	char	*str;
	char	*res;

	// Test 1
	str = strdup("Coucou");
	res = ft_strmap(str, &fptr_ft_strmap);
	if (strcmp(str, "Coucou") != 0)
		return (101);
	if (strcmp(res, "COUCOU") != 0)
		return (102);
	free(str);
	free(res);

	return (0);
}

static char fptr_ft_strmapi(unsigned int i, char c)
{
	if (i == 3)
		return '3';
	else
		return toupper(c);
}

static int	test_ft_strmapi(void)
{
	char	*str;
	char	*res;

	// Test 1
	str = strdup("Coucou");
	res = ft_strmapi(str, &fptr_ft_strmapi);
	if (strcmp(str, "Coucou") != 0)
		return (101);
	if (strcmp(res, "COU3OU") != 0)
		return (102);
	free(str);
	free(res);

	return (0);
}

static int	test_ft_strequ(void)
{
	// Test 1
	if (ft_strequ("coucou", "coucou") != 1)
		return (1);

	// Test 2
	if (ft_strequ("abcx", "abc") != 0)
		return (2);

	// Test 3
	if (ft_strequ("", "") != 1)
		return (3);

	return (0);
}

static int	test_ft_strnequ(void)
{
	// Test 1
	if (ft_strnequ("coucou", "couxou", 3) != 1)
		return (1);

	// Test 2
	if (ft_strnequ("abcx", "abc", 99) != 0)
		return (2);

	// Test 3
	if (ft_strnequ("", "", 1) != 1)
		return (3);

	// Test 4
	if (ft_strnequ("test", "test ", 5) != 0)
		return (4);

	return (0);
}

static int	test_ft_strsub(void)
{
	char	*res;

	// Test 1
	res = ft_strsub("Voici une grande chaine", 6, 3);
	if (res == NULL)
		return (101);
	if (strcmp(res, "une") != 0)
		return (102);
	free(res);

	// Test 2
	res = ft_strsub("Encore une longue chaine", 0, 2);
	if (res == NULL)
		return (201);
	if (strcmp(res, "En") != 0)
		return (202);
	free(res);

	return (0);
}

static int	test_ft_strjoin(void)
{
	char	*res;

	// Test 1
	res = ft_strjoin("abc", "def");
	if (strcmp(res, "abcdef") != 0)
		return (1);
	free(res);

	// Test 2
	res = ft_strjoin("voici une grande chaine", " qui deviens encore plus grande.");
	if (strcmp(res, "voici une grande chaine qui deviens encore plus grande.") != 0)
		return (2);

	return (0);
}

static int	test_ft_strtrim(void)
{
	char	*res;

	// Test 1
	res = ft_strtrim("  coucou  ");
	if (res == NULL)
		return (101);
	if (strcmp(res, "coucou") != 0)
		return (102);
	free(res);

	// Test 2
	res = ft_strtrim(" \t \n  hello");
	if (res == NULL)
		return (201);
	if (strcmp(res, "hello") != 0)
		return (202);
	free(res);

	// Test 3
	res = ft_strtrim("salut");
	if (res == NULL)
		return (301);
	if (strcmp(res, "salut") != 0)
		return (302);
	free(res);

	// Test 4
	res = ft_strtrim("plop \t \n    ");
	if (res == NULL)
		return (401);
	if (strcmp(res, "plop") != 0)
		return (402);
	free(res);

	// Test 5
	res = ft_strtrim("");
	if (res == NULL)
		return (501);
	if (strcmp(res, "") != 0)
		return (502);
	free(res);

	// Test 6
	res = ft_strtrim("\t    \n \n ");
	if (strcmp(res, "") != 0)
		return (6);

	return (0);
}

static int	test_ft_strsplit(void)
{
	char	**res;
	char	**cmp1;
	int 	i;

	// Test 1
	i = 0;
	res = ft_strsplit("*salut*les***etudiants*", '*');
	if (res == NULL)
		return (101);
	while (res[i] != NULL)
	{
		if (i == 0 && strcmp(res[i], "salut") != 0)
			return (102);
		if (i == 1 && strcmp(res[i], "les") != 0)
			return (103);
		if (i == 2 && strcmp(res[i], "etudiants") != 0)
			return (104);
		free(res[i]);
		i++;
	}
	if (i != 3)
		return (105);
	free(res);

	// Test 2
	i = 0;
	res = ft_strsplit("salut tout le monde", '*');
	if (res == NULL)
		return (201);
	while (res[i] != NULL)
	{
		if (i == 0 && strcmp(res[i], "salut tout le monde") != 0)
			return (202);
		free(res[i]);
		i++;
	}
	if (i != 1)
		return (203);
	free(res);

	// Test 3
	i = 0;
	res = ft_strsplit("", ' ');
	if (res == NULL)
		return (301);
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	if (i > 0)
		return (302);
	free(res);

	// Test 4
	i = 0;
	res = ft_strsplit("*******", '*');
	if (res == NULL)
		return (401);
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	if (i > 0)
		return (402);
	free(res);

	// Test 5
	i = 0;
	res = ft_strsplit("*salut*les***etudiants", '*');
	if (res == NULL)
		return (501);
	while (res[i] != NULL)
	{
		if (i == 0 && strcmp(res[i], "salut") != 0)
			return (502);
		if (i == 1 && strcmp(res[i], "les") != 0)
			return (503);
		if (i == 2 && strcmp(res[i], "etudiants") != 0)
			return (504);
		free(res[i]);
		i++;
	}
	if (i != 3)
		return (505);
	free(res);
	
	return (0);
}

static int	test_ft_itoa(void)
{
	char	*res;

	// Test 1
	res = ft_itoa(45836);
	if (res == NULL)
		return (101);
	if (strcmp(res, "45836") != 0)
		return (102);
	free(res);

	// Test 2
	res = ft_itoa(-1182);
	if (res == NULL)
		return (201);
	if (strcmp(res, "-1182") != 0)
		return (202);
	free(res);

	// Test 3
	res = ft_itoa(0);
	if (res == NULL)
		return (301);
	if (strcmp(res, "0") != 0)
		return (302);
	free(res);

	// Test 4
	res = ft_itoa(2147483647);
	if (res == NULL)
		return (401);
	if (strcmp(res, "2147483647") != 0)
		return (402);
	free(res);

	// Test 5
	res = ft_itoa(-2147483648);
	if (res == NULL)
		return (501);
	if (strcmp(res, "-2147483648") != 0)
		return (502);
	free(res);

	return (0);
}

static int	test_ft_lstnew(void)
{
	t_list	*list;

	// Test 1;
	list = ft_lstnew("coucou", 7);
	if (list == NULL)
		return (101);
	if (list->content == NULL)
		return (102);
	if (list->content_size != 7)
		return (103);
	if (strcmp((char *)list->content, "coucou") != 0)
		return (104);
	free(list);

	// Test 2
	list = ft_lstnew(NULL, 5);
	if (list == NULL)
		return (201);
	if (list->content != NULL)
		return (202);
	if (list->content_size != 0)
		return (203);
	free(list);

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

	g_tests[i].name = strdup("ft_memcmp");
	g_tests[i].f = &test_ft_memcmp;
	i++;

	g_tests[i].name = strdup("ft_strlen");
	g_tests[i].f = &test_ft_strlen;
	i++;

	g_tests[i].name = strdup("ft_strdup");
	g_tests[i].f = &test_ft_strdup;
	i++;

	g_tests[i].name = strdup("ft_strcpy");
	g_tests[i].f = &test_ft_strcpy;
	i++;

	g_tests[i].name = strdup("ft_strncpy");
	g_tests[i].f = &test_ft_strncpy;
	i++;

	g_tests[i].name = strdup("ft_strcat");
	g_tests[i].f = &test_ft_strcat;
	i++;

	g_tests[i].name = strdup("ft_strncat");
	g_tests[i].f = &test_ft_strncat;
	i++;

	g_tests[i].name = strdup("ft_strlcat");
	g_tests[i].f = &test_ft_strlcat;
	i++;

	g_tests[i].name = strdup("ft_strchr");
	g_tests[i].f = &test_ft_strchr;
	i++;

	g_tests[i].name = strdup("ft_strrchr");
	g_tests[i].f = &test_ft_strrchr;
	i++;

	g_tests[i].name = strdup("ft_strstr");
	g_tests[i].f = &test_ft_strstr;
	i++;

	g_tests[i].name = strdup("ft_strnstr");
	g_tests[i].f = &test_ft_strnstr;
	i++;

	g_tests[i].name = strdup("ft_strcmp");
	g_tests[i].f = &test_ft_strcmp;
	i++;

	g_tests[i].name = strdup("ft_strncmp");
	g_tests[i].f = &test_ft_strncmp;
	i++;

	g_tests[i].name = strdup("ft_atoi");
	g_tests[i].f = &test_ft_atoi;
	i++;

	g_tests[i].name = strdup("ft_isalpha");
	g_tests[i].f = &test_ft_isalpha;
	i++;
	
	g_tests[i].name = strdup("ft_isdigit");
	g_tests[i].f = &test_ft_isdigit;
	i++;

	g_tests[i].name = strdup("ft_isalnum");
	g_tests[i].f = &test_ft_isalnum;
	i++;

	g_tests[i].name = strdup("ft_isascii");
	g_tests[i].f = &test_ft_isascii;
	i++;

	g_tests[i].name = strdup("ft_isprint");
	g_tests[i].f = &test_ft_isprint;
	i++;
	
	g_tests[i].name = strdup("ft_toupper");
	g_tests[i].f = &test_ft_toupper;
	i++;

	g_tests[i].name = strdup("ft_tolower");
	g_tests[i].f = &test_ft_tolower;
	i++;

	g_tests[i].name = strdup("ft_memalloc");
	g_tests[i].f = &test_ft_memalloc;
	i++;

	g_tests[i].name = strdup("ft_memdel");
	g_tests[i].f = &test_ft_memdel;
	i++;

	g_tests[i].name = strdup("ft_strnew");
	g_tests[i].f = &test_ft_strnew;
	i++;

	g_tests[i].name = strdup("ft_strdel");
	g_tests[i].f = &test_ft_strdel;
	i++;

	g_tests[i].name = strdup("ft_strclr");
	g_tests[i].f = &test_ft_strclr;
	i++;

	g_tests[i].name = strdup("ft_striter");
	g_tests[i].f = &test_ft_striter;
	i++;

	g_tests[i].name = strdup("ft_striteri");
	g_tests[i].f = &test_ft_striteri;
	i++;

	g_tests[i].name = strdup("ft_strmap");
	g_tests[i].f = &test_ft_strmap;
	i++;

	g_tests[i].name = strdup("ft_strmapi");
	g_tests[i].f = &test_ft_strmapi;
	i++;

	g_tests[i].name = strdup("ft_strequ");
	g_tests[i].f = &test_ft_strequ;
	i++;

	g_tests[i].name = strdup("ft_strnequ");
	g_tests[i].f = &test_ft_strnequ;
	i++;

	g_tests[i].name = strdup("ft_strsub");
	g_tests[i].f = &test_ft_strsub;
	i++;

	g_tests[i].name = strdup("ft_strjoin");
	g_tests[i].f = &test_ft_strjoin;
	i++;

	g_tests[i].name = strdup("ft_strtrim");
	g_tests[i].f = &test_ft_strtrim;
	i++;

	g_tests[i].name = strdup("ft_strsplit");
	g_tests[i].f = &test_ft_strsplit;
	i++;

	g_tests[i].name = strdup("ft_itoa");
	g_tests[i].f = &test_ft_itoa;
	i++;

	g_tests[i].name = strdup("ft_itoa");
	g_tests[i].f = &test_ft_itoa;
	i++;

	g_tests[i].name = strdup("ft_lstnew");
	g_tests[i].f = &test_ft_lstnew;
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


