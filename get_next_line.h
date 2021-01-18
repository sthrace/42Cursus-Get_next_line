#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *dst, const char *src);

#endif
#endif