/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 08:39:45 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 12:45:30 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allocates (with malloc(3)) and returns a string representing the integer
**	received as an argument. Negative numbers must be handled.
*/

#include "libft.h"

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	long	n2;
	char	*number;

	n2 = n;
	i = ft_intlen(n);
	number = malloc((i + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	number[i] = '\0';
	i--;
	if (n2 == 0)
		number[0] = '0';
	if (n2 < 0)
	{
		number[0] = '-';
		n2 = n2 * -1;
	}
	while (n2 != 0)
	{
		number[i] = ((n2 % 10) + 48);
		n2 = n2 / 10;
		i--;
	}
	return (number);
}
