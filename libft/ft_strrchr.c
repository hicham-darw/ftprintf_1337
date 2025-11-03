/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:55:03 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/27 22:53:27 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (*(s + i) == c)
		{
			p = (char *)(s + i);
			return (p);
		}
		i--;
	}
	if (*s == c)
	{
		p = (char *)s;
		return (p);
	}
	return (NULL);
}
