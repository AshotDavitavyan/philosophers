/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:21:57 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/06 10:20:22 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	destlen;
	size_t	srclen;

	if ((!dest && destsize == 0) || (!src && destsize == 0))
		return (0);
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destlen >= destsize)
		return (destsize + srclen);
	if (destsize - destlen <= srclen)
	{
		ft_memcpy(dest + destlen, src, srclen);
		dest[destsize - 1] = 0;
	}
	else
		ft_memcpy(dest + destlen, src, srclen + 1);
	return (destlen + srclen);
}
