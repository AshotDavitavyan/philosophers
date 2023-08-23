/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:43:36 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 15:37:36 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i + 1);
}

static void	alloc(char **arr, char const *str, char ban)
{
	char const	*tmp;

	tmp = str;
	while (*tmp)
	{
		while (*str == ban)
			str++;
		tmp = str;
		while (*tmp && *tmp != ban)
			tmp++;
		if (*tmp == ban || tmp > str)
		{
			*arr = ft_substr(str, 0, tmp - str);
			str = tmp;
			arr++;
		}
	}
	*arr = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		size;

	if (!s)
		return (NULL);
	size = count(s, c);
	arr = (char **)malloc(sizeof(char *) * size);
	if (!arr)
		return (NULL);
	alloc(arr, s, c);
	return (arr);
}
/*
#include<stdio.h>
int main()
{
	char const s[] = "asdasfsdfasdasdasfasd";
	char c = ' ';
	printf("%s",ft_split(s, c));
}*/
