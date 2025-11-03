/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:28:28 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/19 04:23:46 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*empty_str(void)
{
	char	*ptr;

	ptr = (char *)malloc(1);
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		last;
	int		i;

	if (!s1)
		return (NULL);
	if (!set || !*set)
		return (ft_strdup(s1));
	last = (int)ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_isset(set, s1[start]))
		start++;
	while ((last - 1) >= start && ft_isset(set, s1[last - 1]))
		last--;
	if (start >= last)
		return (empty_str());
	ptr = (char *)malloc(sizeof(char) * ((last - start) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[start] && start < last)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
