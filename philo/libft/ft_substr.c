/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:45:14 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 15:49:42 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put(char *substr, char const *s, size_t len, unsigned int start)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		substr[i] = *(s + start + i);
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len2;

	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	len2 = ft_strlen(s) - start;
	if (len2 < len)
	{
		substr = (char *)malloc(len2 + 1 * sizeof(char));
		if (!substr)
			return (NULL);
		return (put(substr, s, len2, start));
	}
	else
	{
		substr = (char *)malloc(len + 1 * sizeof(char));
		if (!substr)
			return (NULL);
		return (put(substr, s, len, start));
	}
}
/*
#include<stdio.h>
int main()
{
	char const s[] = "asdfghjkl";
	unsigned int start = 6;
	size_t len = 6;
	printf("%s", ft_substr(s, start, len));
}*/
