/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:43:28 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/21 11:43:31 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	*new_str(char const *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	if (start > end || start < 0 || end < 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static void	free_mem(char **s, int j)
{
	while (j >= 0)
	{
		free(s[j]);
		j--;
	}
	free(s);
}

static int	make_split(char **split, const char *s, char c)
{
	int		start;
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start == -1 && s[i])
			start = i;
		if ((s[i] == c || s[i] == '\0') && start != -1)
		{
			split[j++] = new_str(s, start, i);
			if (!split[j - 1])
			{
				free_mem(split, j - 1);
				return (0);
			}
			start = -1;
		}
		i++;
	}
	split[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!split)
		return (NULL);
	if (!make_split(split, s, c))
		return (NULL);
	return (split);
}
/*#include <stdio.h>
int	main()
{
	char	**result;

	result = ft_split("Hello world this is a test", ' ');
	for (int i = 0; result[i]; i++)
	{
		printf("result[%d]%s\n", i, result[i]);
	}
}*/
