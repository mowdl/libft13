/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_test.cc                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <mel-meka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:14:59 by mel-meka          #+#    #+#             */
/*   Updated: 2023/11/05 20:40:35 by mel-meka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>

extern "C"
{
#include "libft.h"
#include <stdlib.h>
#include <string.h>
}

#include <gtest/gtest.h>

const int str_num = 9;
char const *strings[str_num] = {
	"",		   "hello", "World",
	"BANG",	   "feww",	"Hello World!",
	"on1 tw2", "  ",	"what\tbeautiful\t\t day \nHello",
};

// Demonstrate some basic assertions.
TEST(ft_strlen, general_tests)
{
	int i = 0;
	while (i < str_num)
	{
		// Expect two strings not to be equal.
		EXPECT_EQ(ft_strlen(strings[i]), strlen(strings[i]));
		i++;
	}
}

TEST(ft_isdigit, general_tests)
{
	for (int i = 300; i <= 300; i++)
	{
		EXPECT_EQ(ft_isdigit(i), isdigit(i));
	}
}

TEST(ft_isalpha, general_tests)
{
	for (int i = -300; i <= 300; i++)
	{
		EXPECT_EQ(ft_isalpha(i), isalpha(i));
	}
}


TEST(ft_isalnum, general_tests)
{
	for (int i = -300; i <= 300; i++)
	{
		EXPECT_EQ(ft_isalnum(i), isalnum(i));
	}
}

TEST(ft_isascii, general_tests)
{
	for (int i = -10; i <= 200; i++)
	{
		EXPECT_EQ(ft_isascii(i), isascii(i));
	}
}
TEST(ft_isprint, general_tests)
{
	for (int i = -10; i <= 200; i++)
	{
		EXPECT_EQ(ft_isprint(i), isprint(i));
	}
}

#include <vector>
TEST(ft_memset, general_tests)
{
	void *b1;
	void *b2;
	std::vector<int> cs = {-1, 0, 1, 10, 15, 100, 200, 300};
	std::vector<size_t> lens = {0, 1, 2, 3, 10, 100};
	for (size_t len : lens)
	{
		for (int c : cs)
		{
			b1 = malloc(len);
			b2 = malloc(len);
			b1 = ft_memset(b1, c, len);
				b2 = memset(b2, c, len);
			for (size_t i = 0; i < len; i++)
			{
				EXPECT_EQ(((unsigned char*)b1)[i], ((unsigned char*)b2)[i]);
			}
			free(b1);
			free(b2);
		}
	}
}

TEST(ft_bzero, general_tests)
{
	void *b1;
	void *b2;
	std::vector<size_t> lens = {0, 1, 2, 3, 10, 100};
	for (size_t len : lens)
	{
			b1 = malloc(len);
			b2 = malloc(len);
			ft_bzero(b1, len);
			bzero(b2, len);
			for (size_t i = 0; i < len; i++)
			{
				EXPECT_EQ(((unsigned char*)b1)[i], ((unsigned char*)b2)[i]);
			}
			free(b1);
			free(b2);
	}
}

TEST(ft_memcpy, general_tests)
{
	for(int i = 0; i < str_num; i++)
	{
		size_t n = ft_strlen(strings[i]);
		char *dst = (char *)malloc(n+1);
		char *r = (char *)ft_memcpy(dst, strings[i], n+1);
		EXPECT_EQ(r, dst);
		for(int j = 0; j < (n+1); j++)
		{
			EXPECT_EQ(dst[j], strings[i][j]);
		}
		free(dst);
	}
}

TEST(ft_memmove, general_tests)
{
	for(int i = 0; i < str_num; i++)
	{
		size_t n = ft_strlen(strings[i]);
		char *dst = (char *)malloc(n+1);
		char *r = (char *)ft_memmove(dst, strings[i], n+1);
		EXPECT_EQ(r, dst);
		for(int j = 0; j < (n+1); j++)
		{
			EXPECT_EQ(dst[j], strings[i][j]);
		}
		free(dst);
	}
}

TEST(ft_memmove, overlaping_test)
{
	char *buffer = (char *)malloc(sizeof(char) * 10);
	char *src = buffer;
	char *dst = buffer + 2;
	const char *str = "Hello";
	memcpy(src, str, strlen(str)+1);
	ft_memmove(dst, src, strlen(str)+1);
	EXPECT_EQ(strcmp(dst, str), 0);
	EXPECT_NE(strcmp(src, str), 0);
	free(buffer);
}

TEST(ft_strlcpy, general_tests)
{
	const char *src = "Hello";
	// test return value;
	for (int i = 0; i < 10; i++)
	{
		char *dst = (char *)malloc(sizeof(char) * i);
		EXPECT_EQ(strlcpy(dst, src, i), ft_strlcpy(dst, src, i)) << "error in return value";
		free(dst);
	}
	for (int i = 1; i < 10; i++)
	{
		char *dst1 = (char *)malloc(sizeof(char) * i);
		char *dst2 = (char *)malloc(sizeof(char) * i);
		ft_strlcpy(dst1, src, i);
		strlcpy(dst2, src, i);
		EXPECT_EQ(strlen(dst1), strlen(dst2)) << "error in dst len";
		EXPECT_STREQ(dst1, dst2) << "error in dst";
		free(dst1);
		free(dst2);
	}
}

TEST(ft_strlcat, dst_is_not_a_string)
{
	const char	*src = "aaa";
	char	dst1[20];
	char	dst2[20];
	int		ret1;
	int		ret2;

	memset(dst1, 'B', sizeof(dst1));
	memset(dst2, 'B', sizeof(dst2));

	strlcat(dst1, src, 20);
	strlcat(dst1, src, 20);
	ret1 = strlcat(dst1, src, 20);

	ft_strlcat(dst2, src, 20);
	ft_strlcat(dst2, src, 20);
	ret2 = ft_strlcat(dst2, src, 20);
	EXPECT_EQ(ret1, ret2);
	EXPECT_STREQ(dst1, dst2);
}

TEST(ft_strlcat, basic_input)
{
# define STRING_1 "the cake is a lie !\0I'm hidden lol"
# define STRING_2 "there is no stars in the sky"	
	const char	*str = STRING_1;
	char	buff1[100] = STRING_2;
	char	buff2[100] = STRING_2;
	size_t	max = strlen(STRING_1) + 4;
	strlcat(buff1, str, max);
	ft_strlcat(buff2, str, max);
	EXPECT_STREQ(buff1, buff2);
}

TEST(ft_toupper, general_tests)
{
	for (int i = -300; i <= 300; i++)
	{
		EXPECT_EQ(ft_toupper(i), toupper(i));
	}
}

TEST(ft_tolower, general_tests)
{
	for (int i = -300; i <= 300; i++)
	{
		EXPECT_EQ(ft_tolower(i), tolower(i));
	}
}

TEST(ft_strchr, general_tests)
{
	int c = '\0';
	for (int i = 0; i < str_num; i++)
	{
		EXPECT_EQ(ft_strchr(strings[i], c), strchr(strings[i], c));
		c = 'm';
		EXPECT_EQ(ft_strchr(strings[i], c), strchr(strings[i], c));
		c = 'M';
		EXPECT_EQ(ft_strchr(strings[i], c), strchr(strings[i], c));
		c = '\t';
		EXPECT_EQ(ft_strchr(strings[i], c), strchr(strings[i], c));
		c = 200;
		EXPECT_EQ(ft_strchr(strings[i], c), strchr(strings[i], c));
		c = 127;
		EXPECT_EQ(ft_strchr(strings[i], c), strchr(strings[i], c));
	}
}

TEST(ft_strrchr, general_tests)
{
	int c = '\0';
	for (int i = 0; i < str_num; i++)
	{
		EXPECT_EQ(ft_strrchr(strings[i], c), strrchr(strings[i], c));
		c = 'm';
		EXPECT_EQ(ft_strrchr(strings[i], c), strrchr(strings[i], c));
		c = 'M';
		EXPECT_EQ(ft_strrchr(strings[i], c), strrchr(strings[i], c));
		c = '\t';
		EXPECT_EQ(ft_strrchr(strings[i], c), strrchr(strings[i], c));
		c = 200;
		EXPECT_EQ(ft_strrchr(strings[i], c), strrchr(strings[i], c));
		c = 127;
		EXPECT_EQ(ft_strrchr(strings[i], c), strrchr(strings[i], c));
	}
}

TEST(ft_strnstr, general_tests)
{
	for (int i = 0; i < str_num; i++)
	{
		for (int j = 0; j < str_num; j++)
		{
			EXPECT_EQ(ft_strnstr(strings[i], strings[j], 100), strnstr(strings[i], strings[j], 100)) << strings[i] << "~~" << strings[j] << "~~" << 100;
			EXPECT_EQ(ft_strnstr(strings[i], strings[j], 3), strnstr(strings[i], strings[j], 3)) << strings[i] << "~~" << strings[j] << "~~" << 3;
		}
	}
}

TEST(ft_atoi, general_tests)
{
	EXPECT_EQ(ft_atoi(""), atoi(""));
	char str[] = "00123ab";
	for (int i = 0; i <= 127; i++) {
		for (int j = 0; j <= 127; j++) {
			str[0] = i;
			str[1] = j;
			EXPECT_EQ(ft_atoi(str), atoi(str));
		}
	}
}

TEST(ft_strtrim, null)
{
	EXPECT_EQ(ft_strtrim(0, 0), nullptr);
}

TEST(ft_strtrim, empty_strings)
{
	EXPECT_STREQ(ft_strtrim("", "   "), "");
	EXPECT_STREQ(ft_strtrim("hello world", ""), "hello world");
	EXPECT_STREQ(ft_strtrim("", ""), "");
}

TEST(ft_strtrim, general_tests)
{
	EXPECT_STREQ(ft_strtrim("  Hello World!  ", " !"), "Hello World");
	EXPECT_STREQ(ft_strtrim("Hello World", " !"), "Hello World");
	EXPECT_STREQ(ft_strtrim(" !\n", "\n !"), "");
}

TEST(ft_split, general_tests)
{
	char s1[] = "Hello World!";
	char **arr = ft_split(s1, ' ');
	EXPECT_STREQ(arr[0], "Hello"); free(arr[0]);
	EXPECT_STREQ(arr[1], "World!"); free(arr[1]);
	EXPECT_EQ(arr[2], nullptr); free(arr);

	char s2[] = " Hello   World! ";
	arr = ft_split(s2, ' ');
	EXPECT_STREQ(arr[0], "Hello"); free(arr[0]);
	EXPECT_STREQ(arr[1], "World!"); free(arr[1]);
	EXPECT_EQ(arr[2], nullptr); free(arr);

	char s3[] = "Hello";
	arr = ft_split(s3, ' ');
	EXPECT_STREQ(arr[0], "Hello"); free(arr[0]);
	EXPECT_EQ(arr[1], nullptr); free(arr);
}
TEST(ft_split, empty_arr)
{
	char s4[] = "";
	char **arr = ft_split(s4, ' ');
	EXPECT_EQ(arr[0], nullptr) << "string is empty:" << arr[0] << strlen(arr[0]) << arr[1]; free(arr);

	char s5[] = " ";
	arr = ft_split(s5, ' ');
	EXPECT_EQ(arr[0], nullptr) << "string only one c"; free(arr);
}

