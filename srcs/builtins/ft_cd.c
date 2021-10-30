/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 11:10:30 by antgonza          #+#    #+#             */
/*   Updated: 2021/10/30 11:28:45 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/* \
Primero necesito hacer env para actualizar PWD con el nuevo dir
 */
void	ft_cd()
{
	size_t	i;
	
	i = 0;
	getcwd("/bin/", i);
}