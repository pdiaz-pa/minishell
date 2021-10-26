/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:40:04 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:28:11 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	concatenate two strings
*/

#include "libft.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	countd;
	unsigned int	counts;

	countd = 0;
	counts = 0;
	while (dest[countd] != '\0')
		countd++;
	while (src[counts] != '\0' && counts < nb)
	{
		dest[countd] = src[counts];
		countd++;
		counts++;
	}
	dest[countd] = '\0';
	return (dest);
}
