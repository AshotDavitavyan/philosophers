/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:10:12 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 16:11:07 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (i);
	while (*src && dstsize - 1 > 0)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (i);
}
/*
#include<stdio.h>
int main()
{
	char dst[] = "asdfg";
	const char src[] = "";
	size_t d = 4;
	printf("%d", ft_strlcpy(dst, src, d ));
	printf("%s", strlcpy(dst, src, d));
}*/
