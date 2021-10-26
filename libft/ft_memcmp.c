/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:46:50 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:34:05 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	compare byte string
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s11;
	const unsigned char	*s22;

	if (n == 0 || (!s1 && !s2))
		return (0);
	i = 0;
	s11 = (const unsigned char *)s1;
	s22 = (const unsigned char *)s2;
	while (s11[i] == s22[i] && i < (n - 1))
		i++;
	return ((int)(s11[i] - s22[i]));
}
