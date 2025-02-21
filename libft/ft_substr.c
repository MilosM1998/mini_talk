/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmilicev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:45:11 by mmilicev          #+#    #+#             */
/*   Updated: 2024/09/21 11:45:12 by mmilicev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*subs;
	size_t			subs_len;
	size_t			s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	subs_len = s_len - start;
	if (subs_len > len)
		subs_len = len;
	subs = malloc((sizeof(char) * subs_len + 1));
	if (!subs)
		return (NULL);
	while (i < subs_len)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
/*#include <stdio.h>
int main()
{
	char *str = "This is a test.";
	char *dup = ft_substr(str, 5 , 15);
	printf("%s\n", dup);
	free(dup);
}*/
