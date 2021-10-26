/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:31:19 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:45:16 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	concatenate two strings
*/

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int	countd;
	int	counts;

	countd = 0;
	counts = 0;
	while (dest[countd] != '\0')
		countd++;
	while (src[counts] != '\0')
	{
		dest[countd] = src[counts];
		countd++;
		counts++;
	}
	dest[countd] = '\0';
	return (dest);
}
