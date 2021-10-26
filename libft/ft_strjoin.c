/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:19:17 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 11:24:58 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allocates (with malloc(3)) and returns a new string,
**	which is the result of the concatenation of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (ft_strdup(""));
	len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	s3 = malloc(len * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	len = ft_strlen(s1);
	while (s2[i - len] != '\0')
	{
		s3[i] = s2[i - len];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
