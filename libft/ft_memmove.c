/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:46:24 by antgonza          #+#    #+#             */
/*   Updated: 2020/02/06 12:11:49 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	copy byte string
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst2;
	const unsigned char	*src2;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (dst);
	dst2 = (unsigned char *)dst;
	src2 = (const unsigned char *)src;
	i = 1;
	if (src < dst)
	{
		while (len >= i)
		{
			dst2[len - i] = src2[len - i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
