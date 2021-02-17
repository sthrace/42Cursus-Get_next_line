/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:44:47 by sthrace           #+#    #+#             */
/*   Updated: 2021/01/20 09:03:45 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_free(char *str)
{
	free(str);
	str = NULL;
	return (0);
}

static void			ft_dupandfree(char **dest, char **source)
{
	char		*templine;

	templine = *dest;
	*dest = ft_strdup(*source);
	free(templine);
}

static void			*treat_leftover(char **lft, char **line)
{
	char		*ptr;

	ptr = NULL;
	*line = ft_strdup("");
	if (*lft)
	{
		if ((ptr = ft_strchr(*lft, '\n')))
		{
			*ptr = '\0';
			ft_dupandfree(line, lft);
			ptr++;
			ft_dupandfree(lft, &ptr);
			return (ptr);
		}
		ft_dupandfree(line, lft);
		free(*lft);
		*lft = NULL;
	}
	return (ptr);
}

int					get_next_line(int fd, char **line)
{
	int			res;
	char		buff[BUFFER_SIZE + 1];
	char		*ptr;
	static char	*lft;
	char		*temp;

	if (!(line) || BUFFER_SIZE <= 0 || fd < 0 || read(fd, buff, 0) == -1)
		return (-1);
	ptr = treat_leftover(&lft, line);
	while (!ptr && (res = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[res] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			*ptr = '\0';
			lft = ft_strdup(++ptr);
		}
		temp = *line;
		if (!(*line = ft_strjoin(*line, buff)))
			return (-1);
		free(temp);
	}
	return (lft) ? 1 : ft_free(lft);
}
