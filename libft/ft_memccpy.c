/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:46:06 by antgonza          #+#    #+#             */
/*   Updated: 2020/04/15 17:19:52 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  copy string until character found
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dst2;
	const unsigned char		*src2;
	size_t					i;

	if (!src && !dst)
		return (NULL);
	dst2 = (unsigned char *)dst;
	src2 = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (src2[i] == (const unsigned char)c)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
