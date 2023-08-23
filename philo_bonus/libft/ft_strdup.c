/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavitav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:18:32 by adavitav          #+#    #+#             */
/*   Updated: 2023/02/05 16:38:35 by adavitav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		count;
	int		s1_len;
	char	*ptr;

	count = 0;
	s1_len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(s1_len * sizeof(char));
	if (!ptr)
		return (NULL);
	while (s1_len > count)
	{
		ptr[count] = s1[count];
		count++;
	}
	return (ptr);
}
/*
int main()
{
    const char s1[] = "asdfg";
    ft_strdup(s1);
}*/
