/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 22:02:25 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 14:04:45 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allocates (with malloc(3)) and returns an array of strings obtained by
**	splitting ’s’ using the character ’c’ as a delimiter.  The array must
**	be ended by a NULL pointer.
*/

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int		i;
	int		j;

	if (!s || !c)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j++;
			while ((s[i + 1] != c && s[i + 1] != '\0'))
				i++;
		}
		i++;
	}
	j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i[4];

	if (!s)
		return (NULL);
	i[0] = ft_wordcount(s, c);
	split = (char **)malloc(sizeof(char *) * (i[0] + 1));
	if (split == NULL)
		return (NULL);
	i[0] = -1;
	i[3] = 0;
	while (s[++i[0]] != '\0')
	{
		if (s[i[0]] != c)
		{
			i[2] = i[0];
			i[1] = 0;
			while (s[i[0] + 1] != c && s[i[0] + 1] != '\0' && i[1]++ >= 0)
				i[0]++;
			split[i[3]] = ft_substr(s, i[2], (i[1] + 1));
			i[3]++;
		}
	}
	split[i[3]] = NULL;
	return (split);
}
