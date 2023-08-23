/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:05:27 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 19:13:51 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	number(int i, char *str, int n, int start)
{
	while (i-- > start)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		start;
	char	*str;

	start = 0;
	i = size(n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!(str))
		return (0);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
		start = 2;
	}
	if (n < 0)
	{
		str[0] = '-';
		start = 1;
		n = -n;
	}
	number(i, str, n, start);
	str[i] = '\0';
	return (str);
}
/*
int main()
{
	int n = -12345;
	ft_itoa(n);
}*/
