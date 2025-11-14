/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:22:17 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/14 05:44:40 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_put_everything(va_list list, const char *s, int *ret)
{
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == 'd' || *s == 'i' || *s == 'c')
				*ret += print_arg_int(va_arg(list, int), *s);
			else if (*s == 'x' || *s == 'X' || *s == 'u')
				*ret += print_arg_unsigned(va_arg(list, unsigned int), *s);
			else if (*s == 'p')
				*ret += print_address(va_arg(list, void *));
			else if (*s == 's')
				*ret += print_string(va_arg(list, char *));
			else if (*s == '\0')
				return (0);
			else if (*s == '%')
				*ret += write(1, "%", 1);
			else
				*ret += print_invalid_format(*s);
		}
		else
			*ret += write(1, s, 1);
		s++;
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		ret;

	if (!s)
		return (-1);
	va_start(list, s);
	ret = 0;
	if (!ft_put_everything(list, s, &ret))
	{
		va_end(list);
		return (-1);
	}
	va_end(list);
	return (ret);
}
