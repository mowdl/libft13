/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hello_test.cc                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-meka <mel-meka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:14:59 by mel-meka          #+#    #+#             */
/*   Updated: 2023/10/31 23:03:44 by mel-meka         ###   ########.fr       */
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
	for (int i = 0; i <= 127; i++)
	{
		EXPECT_EQ(ft_isdigit(i), isdigit(i));
	}
}

TEST(ft_isalpha, general_tests)
{
	for (int i = 0; i <= 127; i++)
	{
		EXPECT_EQ(ft_isalpha(i), isalpha(i));
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
