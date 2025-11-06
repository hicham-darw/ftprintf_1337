/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlyformat_cat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:58:46 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/06 04:20:06 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_onlyformat_cat(char *dest)
{
	int	i;

	if (!dest)
		return (NULL);
	i = 0;
	while (dest[i])
		i++;
	dest[i++] = '%';
	dest[i] = '\0';
	return (dest);
}
