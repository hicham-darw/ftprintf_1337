/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:38:18 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/27 22:53:03 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
	{
		p = (char *)s;
		return (p);
	}
	return (NULL);
}
