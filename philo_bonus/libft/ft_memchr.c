/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:57:28 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 14:58:58 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*temp;
	char	c1;

	temp = (char *)s;
	c1 = (char)c;
	while (n > 0)
	{
		if (*temp == c1)
			return ((void *)temp);
		temp++;
		n--;
	}
	return (0);
}
/*
#include<stdio.h>
int main()
{
	char s[] = {0, 1, 2, 3, 4, 5};
	printf("%s",ft_memchr(s, 0, 1));
}
*/
