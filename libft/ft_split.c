/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:02:43 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/19 04:15:15 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	vector_len(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		len += 1;
		while (s[i] && s[i] == c)
			i++;
	}
	return (len);
}

static char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	if (!src)
		return (dest);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	dest[i] = '\0';
	return (dest);
}

static char	**free_vec(char **vec, size_t index)
{
	if (!vec)
		return (NULL);
	while (index > 0)
	{
		free(vec[index - 1]);
		index--;
	}
	free(vec);
	return (NULL);
}

static char	**fill_vector(char **vec, char const *s, char c)
{
	size_t	i;
	size_t	index_v;
	size_t	start;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	index_v = 0;
	while (s[i])
	{
		start = i;
		while (s[i] && s[i] != c)
			i++;
		vec[index_v] = (char *)malloc(sizeof(char) * ((i - start) + 1));
		if (!vec[index_v])
			return (free_vec(vec, index_v));
		vec[index_v] = ft_strncpy(vec[index_v], (s + start), (i - start));
		index_v++;
		while (s[i] && s[i] == c)
			i++;
	}
	vec[index_v] = NULL;
	return (vec);
}

char	**ft_split(char const *s, char c)
{
	char	**vec;
	size_t	len_vec;

	if (!s)
		return (NULL);
	len_vec = vector_len(s, c);
	vec = (char **)malloc(sizeof(char *) * (len_vec + 1));
	if (!vec)
		return (NULL);
	return (fill_vector(vec, s, c));
}
