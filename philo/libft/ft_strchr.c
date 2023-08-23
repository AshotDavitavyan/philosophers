/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:11:18 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 15:17:14 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	loc;

	loc = (char)c;
	while (*s != '\0')
	{
		if (*s == loc)
			return ((char *)s);
		s++;
	}
	if (*s == loc)
		return ((char *)s);
	return (NULL);
}
