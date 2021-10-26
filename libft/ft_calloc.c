/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:15:04 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 10:01:53 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	allocates enough space for count objects that are size bytes of memory
**	each and returns a pointer to the allocated memory.  The allocated memory
**	is filled with bytes of value zero
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
