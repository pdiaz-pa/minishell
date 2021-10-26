/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:48:41 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:35:05 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	outputs the integer ’nb’.
*/

#include "libft.h"

void	ft_putnbr(int nb)
{
	long	aux;

	aux = nb;
	if (aux < 0)
	{
		aux = aux * -1;
		ft_putchar('-');
	}
	if (aux > 9)
		ft_putnbr(aux / 10);
	ft_putchar(aux % 10 + '0');
}
