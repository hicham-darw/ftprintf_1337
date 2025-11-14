/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 23:18:59 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/14 05:38:18 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	ptr = malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_nbrlen_hexa(unsigned int n)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char	*print_hexa(char *ptr, unsigned int nbr, int len, char c)
{
	char	*hex;

	hex = ft_strdup("0123456789ABCDEF");
	if (!hex)
		return (NULL);
	ptr[len--] = '\0';
	while (len >= 0)
	{
		if (c == 'X')
			ptr[len--] = hex[nbr % 16];
		else
		{
			if ((nbr % 16) > 9)
				ptr[len--] = hex[nbr % 16] + 32;
			else
				ptr[len--] = hex[nbr % 16];
		}
		nbr /= 16;
	}
	free(hex);
	return (ptr);
}

int	print_arg_unsigned(unsigned int nbr, char c)
{
	char	*ptr;
	int		ret;

	if (c == 'u')
	{
		ptr = ft_ltoa(nbr);
		if (!ptr)
			return (-1);
		ret = write(1, ptr, ft_strlen(ptr));
		free(ptr);
		return (ret);
	}
	ret = ft_nbrlen_hexa(nbr);
	ptr = malloc(ret + 1);
	if (!ptr)
		return (-1);
	if (print_hexa(ptr, nbr, ret, c) == NULL)
		return (-1);
	ret = write(1, ptr, ft_strlen(ptr));
	free(ptr);
	return (ret);
}
