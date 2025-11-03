/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 02:10:53 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/20 08:22:42 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_bytes, size_t size)
{
	char	*ptr;
	size_t	max;

	max = n_bytes * size;
	if (n_bytes != 0 && (max / n_bytes) != size)
		return (NULL);
	ptr = (char *)malloc(max);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, max);
	return ((void *)ptr);
}
