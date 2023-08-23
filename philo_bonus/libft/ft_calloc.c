/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:38:40 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 19:09:57 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset_n(void *b, int c, size_t len)
{
	unsigned char	c1;
	char			*temp;
	size_t			i;

	temp = (char *)b;
	c1 = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		temp[i] = c1;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = malloc (count * size);
	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	if (!ptr)
		return (NULL);
	return (ft_memset_n(ptr, 0, count * size));
}
/*
int main()
{
	size_t count = 10;
	size_t size = 1;
//	calloc(count, size);
	ft_calloc(count, size);
}*/
