/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:47:33 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:41:53 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	size-bounded string copying and concatenation
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dst);
	if (dstsize > len)
	{
		i = 0;
		while (src[i] != '\0' && (dstsize - 1) > (len + i))
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
		return (len + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}
