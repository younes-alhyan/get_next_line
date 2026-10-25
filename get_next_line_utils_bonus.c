/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalahian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 18:01:27 by yalahian          #+#    #+#             */
/*   Updated: 2026/10/25 18:55:18 by yalahian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, char c)
{
	while (s && *s && *s != c)
		s++;
	if (s && *s == c)
		return (s);
	return (NULL);
}

char	*ft_strljoin(char *s1, char *s2, size_t s2_len)
{
	size_t	i;
	size_t	s1_len;
	char	*str;

	s1_len = ft_strlen(s1);
	if (!s1_len)
		return (ft_strndup(s2, s2_len));
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		str[s1_len + i] = s2[i];
		i++;
	}
	str[s1_len + s2_len] = '\0';
	return (str);
}

char	*ft_strndup(char *s, size_t n)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n && s && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
