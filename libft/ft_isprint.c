/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 19:14:13 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/19 08:36:44 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  tests for any printing character, including space (` ').  The value of the
**	argument must be representable as an unsigned char or the value of EOF
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
