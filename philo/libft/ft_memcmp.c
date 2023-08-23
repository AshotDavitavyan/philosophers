/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:00:01 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 15:02:10 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;

	str1 = (unsigned const char *)s1;
	str2 = (unsigned const char *)s2;
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		n--;
		str1++;
		str2++;
	}
	return (0);
}
/*
#include<string.h>
int main()
{
	char s1[] = {0, 0, 127, 0};
	char s2[] = {0, 0, 42, 0};
	int a = 4;
	printf("%d",ft_memcmp(s1, s2, a));
//	printf("%d", memcmp(s1, s2, a));
	return 0;
}*/
