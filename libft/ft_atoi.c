/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:50:09 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/10/21 13:53:00 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13)
		|| c == 32)
		return (1);
	return (0);
}

static int	get_start(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	str += get_start(str, &sign);
	while (*str && *str >= '0' && *str <= '9')
	{
		if (sign == 1
			&& (res > LONG_MAX / 10
				|| (res == LONG_MAX / 10 && (*str - '0') > LONG_MAX % 10)))
			return (-1);
		if (sign == -1
			&& (res > LONG_MAX / 10
				|| (res == LONG_MAX / 10
					&& (*str - '0') > (LONG_MAX % 10) + 1)))
			return (0);
		res = (res * 10) + (*str - 48);
		str++;
	}
	return ((int)(res * sign));
}
