/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 01:34:22 by antgonza          #+#    #+#             */
/*   Updated: 2020/02/02 02:02:35 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Outputs the character ’c’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}
