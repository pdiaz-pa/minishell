/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:14:28 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:38:07 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** lower case to upper case letter conversion
*/

int	ft_toupper(int c)
{
	if (c >= (char)97 && c <= (char)122)
		return (c - 32);
	else
		return (c);
}
