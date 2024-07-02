/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:50:16 by astoll            #+#    #+#             */
/*   Updated: 2024/06/04 15:10:54 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
	{
		return (0);
	}
	while ((char)c != *s)
	{
		if (!*s)
		{
			return (0);
		}
		s++;
	}
	return ((char *)s);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	if (!s || !*s)
	{
		return (0);
	}
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	if (!dest)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		lens1;
	int		lens2;
	char	*dst;

	if (!s1 && !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	dst = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!dst)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	dst[lens1 + lens2] = '\0';
	while (lens2--)
		dst[lens1 + lens2] = s2[lens2];
	while (lens1--)
		dst[lens1] = s1[lens1];
	if (s1)
		free(s1);
	return (dst);
}
