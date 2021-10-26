/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:46:39 by antgonza          #+#    #+#             */
/*   Updated: 2020/02/06 12:57:00 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	locate byte in byte string
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s2;
	unsigned char		c2;
	size_t				i;

	s2 = (const unsigned char *)s;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s2[i] == c2)
			return ((void *)s2 + i);
		i++;
	}
	return (NULL);
}
