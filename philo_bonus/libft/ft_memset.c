/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:11:03 by adavitav          #+#    #+#             */
/*   Updated: 2023/01/19 14:50:05 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c1;
	unsigned char	*temp;

	temp = b;
	c1 = (unsigned char) c;
	while (len > 0)
	{
		*temp = c1;
		temp++;
		len--;
	}
	return (b);
}
