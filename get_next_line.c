/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:44:47 by sthrace           #+#    #+#             */
/*   Updated: 2020/12/01 12:44:49 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    *treat_leftover(char **lft, char **line) // if leftover contains more than 1 backslash n then only the final line will be returned
{
    char        *ptr;

    if ((ptr = ft_strchr(*lft, '\n')))
    {
        *ptr = '\0';
        *line = ft_strdup(*lft);
        *lft = ft_strdup(++ptr);
    }
    else
    {
        *line = ft_strdup(*lft);
        *lft = NULL;
    }
    return (*line);
}

int     get_next_line(int fd, char **line)
{
    int         res;
    char        buff[B_SIZE + 1];
    char        *ptr;
    static char *lft;

    while (lft)
        treat_leftover(&lft, line);
    while ((res = read(fd, buff, B_SIZE)))
    {
        buff[res] = '\0';
        if ((ptr = (ft_strchr(buff, '\n'))))
        {
            *ptr = '\0';
            *line = ft_strjoin(*line, buff);
            lft = ft_strdup(++ptr);
            break;
        }
        *line = ft_strjoin(*line, buff);
    }
    return (res);
}

int     main()
{
    int     fd;
    char    *line;
    int     i;

    fd = open("test.txt", O_RDONLY);
    while ((i = get_next_line(fd, &line)))
        printf("Line: %s\n", line);
    get_next_line(fd, &line);
        printf("LineF: %s\n", line);
    return (0);
}
