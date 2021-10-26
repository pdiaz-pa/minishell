/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 02:45:57 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:34:27 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Outputs the integer ’n’ to the given file descriptor.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	aux;

	aux = n;
	if (aux < 0)
	{
		aux = aux * -1;
		ft_putchar_fd('-', fd);
	}
	if (aux > 9)
		ft_putnbr_fd(aux / 10, fd);
	ft_putchar_fd(aux % 10 + '0', fd);
}
