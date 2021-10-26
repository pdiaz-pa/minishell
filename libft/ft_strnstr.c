/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:11:58 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:28:45 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	locate a substring in a string
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack) || len == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] != '\0'
			&& needle[j] != '\0' && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
