/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:23:40 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/06 10:18:35 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	check(const char *haystack, const char *needle, size_t len)
{
	while (*haystack == *needle && *haystack != '\0' && len > 0)
	{
		haystack++;
		needle++;
		len--;
	}
	if (*needle == '\0')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if ((!haystack && len == 0) || (!needle && len == 0))
		return (NULL);
	if (!needle[0])
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		if (*haystack == *needle)
		{
			if (check(haystack, needle, len) == 1)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>
int main()
{
	const char haystack[] = "asdfasghqwerasdwet";
	const char needle[] = "wet";
	size_t len = 4;
	printf("FT %s\n", ft_strnstr(haystack, needle, len));
	printf("ORIG %s\n", strnstr(haystack, needle, len));
}
*/
