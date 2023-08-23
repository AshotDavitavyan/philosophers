/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:25:07 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 15:26:13 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		loc;
	const char	*save;

	loc = (char)c;
	save = s;
	while (*s != '\0')
		s++;
	if (loc == '\0')
		return ((char *)s);
	s--;
	while (s >= save)
	{
		if (*s == loc)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
/*
int main()
{
	char s[] = "asdfghj";
	int c = 'd';
	ft_strrchr(s + 4, c);
}*/
