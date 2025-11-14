/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:39:35 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/14 03:51:04 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_string(const char *s)
{
	int	i;
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	i = count;
	while (s[i])
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}

int	print_invalid_format(char c)
{
	write(1, "%", 1);
	write(1, &c, 1);
	return (2);
}
