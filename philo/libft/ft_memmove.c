/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:09:30 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 15:10:25 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	int					i;

	d = (unsigned char *)dst;
	s = (unsigned const char *)src;
	if (!dst && !src)
		return (NULL);
	if (src > dst)
	{
		ft_memcpy(dst, src, n);
		return (dst);
	}
	i = n - 1;
	while (i >= 0)
	{
		d[i] = s[i];
		i--;
	}
	return (dst);
}
/*
int main()
{
	char dst[] = "asdfgh";
	const char src[] = "fgh";
	size_t n = 4;
	ft_memmove(dst, src, n);
}*/
