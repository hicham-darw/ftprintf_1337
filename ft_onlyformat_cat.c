/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_onlyformat_cat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:58:46 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/27 11:07:29 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_onlyformat_cat(char *dest, char c)
{
	int	i;

	if (!dest)
		return (NULL);
	i = 0;
	while (dest[i])
		i++;
	dest[i++] = '%';
	dest[i++] = c;
	dest[i] = '\0';
	return (dest);
}
