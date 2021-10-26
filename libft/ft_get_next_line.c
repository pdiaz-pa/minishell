/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgonza <antgonza@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:12:40 by antgonza          #+#    #+#             */
/*   Updated: 2021/03/20 11:22:38 by antgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Write a function which returns a line read from a file descriptor,
**	without the newline.
*/

#include "libft.h"

static int	ft_readfd(int fd, char **sc);
static int	ft_writeline(char **sc, char **line);

int	ft_get_next_line(int fd, char **line)
{
	static char	*sc;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	if (!sc)
		sc = ft_strdup("");
	if (sc && (ft_strchr(sc, '\n')))
		return (ft_writeline(&sc, line));
	ret = (ft_readfd(fd, &sc));
	if (ret == -1)
	{
		free(sc);
		sc = NULL;
		return (-1);
	}
	return (ft_writeline(&sc, line));
}

static	int	ft_readfd(int fd, char **sc)
{
	char	*buf;
	char	*tmp;
	ssize_t	nread;

	buf = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, buf, 0) == -1)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	nread = read(fd, buf, BUFFER_SIZE);
	while (nread > 0)
	{
		buf[nread] = 0;
		tmp = *sc;
		*sc = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(*sc, '\n'))
			break ;
		nread = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	buf = NULL;
	return (0);
}

static int	ft_writeline(char **sc, char **line)
{
	size_t	i;
	char	*tmp;

	if ((ft_strchr(*sc, '\n')) == NULL)
	{
		*line = ft_strdup(*sc);
		free(*sc);
		*sc = NULL;
		return (0);
	}
	i = 0;
	tmp = *sc;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	*line = ft_substr(tmp, 0, (i));
	*sc = ft_substr(tmp, (i + 1), (ft_strlen(tmp) - i));
	free(tmp);
	tmp = NULL;
	return (1);
}
