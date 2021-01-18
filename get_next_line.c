#include "get_next_line.h"

void    *treat_leftover(char *lft, char **line) // if leftover contains more than 1 backslash n then only the final line will be returned
{
    char        *ptr;

    ptr = NULL;
    if (lft)
    {
        if ((ptr = ft_strchr(lft, '\n')))
        {
            *ptr = '\0';
            *line = ft_strdup(lft);
            ft_strcpy(lft, ++ptr);
        }
        else
        {
            *line = ft_strdup(lft);
            *lft = '\0';
        }
    }
    else
    {
        *line = (char *)malloc(sizeof(char) + 1);
        **line = '\0';
    }
    return (ptr);
}

int     get_next_line(int fd, char **line)
{
    int         res;
    char        buff[BUFFER_SIZE + 1];
    char        *ptr;
    static char *lft;

    ptr = treat_leftover(lft, line);   
    while (!ptr && (res = read(fd, buff, BUFFER_SIZE)))
    {
        
        if ((ptr = (ft_strchr(buff, '\n'))))
        {
            *ptr = '\0';
            lft = ft_strdup(++ptr);
        }
        buff[res] = '\0';
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
        printf("Line: %s\n\n", line);
    printf("LineF: %s\n\n", line);
    return (0);
}