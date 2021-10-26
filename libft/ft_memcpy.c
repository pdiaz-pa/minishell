/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:45:51 by antgonza          #+#    #+#             */
/*   Updated: 2020/02/06 09:52:40 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	copy memory area
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src2;
	unsigned char		*dst2;

	if ((!dst && !src) || n == 0)
		return (dst);
	i = 0;
	src2 = (const unsigned char *)src;
	dst2 = (unsigned char *)dst;
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst);
}
