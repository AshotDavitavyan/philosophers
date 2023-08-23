/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:38:01 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 15:40:23 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	step;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	step = 0;
	str = (char *)malloc((len + 1) * sizeof (char));
	if (!str)
		return (NULL);
	while (*s1)
		str[step++] = *s1++;
	while (*s2)
		str[step++] = *s2++;
	str[step] = '\0';
	return (str);
}
/*
#include<stdio.h>
int main()
{
	char const s1[] = "";
	char const s2[] = "hjklm";
	printf("%s", ft_strjoin(s1, s2));
}*/
