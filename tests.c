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


