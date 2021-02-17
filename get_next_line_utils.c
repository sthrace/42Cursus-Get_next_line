/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthrace <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:45:03 by sthrace           #+#    #+#             */
/*   Updated: 2021/01/20 05:42:44 by sthrace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char		*dst;
	size_t		i;
	size_t		len;

	len = ft_strlen(s1);
	if (!(dst = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)s1)[i];
		i++;
	}
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
