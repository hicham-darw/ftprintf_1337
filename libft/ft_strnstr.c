/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:56:09 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/20 22:34:59 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	ptr = (char *)big;
	if (*little == '\0')
		return (ptr);
	if (!big && !len)
		return (NULL);
	i = 0;
	while (ptr[i] && i < len)
	{
		j = 0;
		while (ptr[i + j] && little[j] && (i + j) < len
			&& ptr[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return (ptr + i);
		i++;
	}
	return (NULL);
}
