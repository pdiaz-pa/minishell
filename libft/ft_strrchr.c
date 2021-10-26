/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:48:05 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:38:38 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	locate character in string
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	i;

	i = (long)ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
