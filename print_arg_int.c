/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:49:51 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/14 04:44:13 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_nbrlen(long nbr)
{
	int	len;

	if (!nbr)
		return (1);
	len = 0;
	if (nbr < 0)
	{
		nbr = (nbr * -1);
		len++;
	}
	while (nbr)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

int	ft_absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_ltoa(long nbr)
{
	int		len;
	char	*ptr;

	len = ft_nbrlen(nbr);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len--] = '\0';
	if (!nbr)
	{
		ptr[0] = 48;
		return (ptr);
	}
	if (nbr < 0)
		ptr[0] = '-';
	while (nbr)
	{
		ptr[len--] = ft_absolute(nbr % 10) + 48;
		nbr /= 10;
	}
	return (ptr);
}

int	print_arg_int(int arg, char c)
{
	char	*ptr;
	int		ret;

	if (c == 'd' || c == 'i')
	{
		ptr = ft_ltoa((long)arg);
		if (!ptr)
			return (-1);
		ret = write(1, ptr, ft_strlen(ptr));
		free(ptr);
		return (ret);
	}
	else
		return (write(1, &arg, 1));
}
