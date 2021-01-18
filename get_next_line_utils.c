#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if ((dst == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char		*ft_strdup(const char *s1)
{
	char	*dst;

	if (!(dst = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_s;
	int		i;
	int		j;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	if (!(joined_s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joined_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		joined_s[i++] = s2[j++];
	joined_s[i] = '\0';
	return (joined_s);
}

char		*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && c != *s)
		s++;
	if (c == *s)
		return ((char *)s);
	return (0);
}

char		*ft_strcpy(char *dst, const char *src)
{
	size_t	srclen;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	srclen = ft_strlen(src);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}