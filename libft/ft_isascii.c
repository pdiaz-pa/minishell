/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:13:56 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:35:59 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** test for ASCII character
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}