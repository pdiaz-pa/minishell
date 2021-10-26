/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:15:18 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 11:24:27 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	save a copy of a string
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, s1, (len + 1));
	return (s2);
}
