/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:18:51 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/14 05:11:27 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbrlen_addr(unsigned long n)
{
	int	len;

	len = 0;
	while (n)
	{
		len ++;
		n /= 16;
	}
	return (len);
}

int	ft_put_addr(char *ptr)
{
	int	ret;

	ret = write(1, ptr, ft_strlen(ptr));
	free(ptr);
	return (ret);
}

int	print_address(void *addr)
{
	char			*ptr;
	int				i;
	unsigned long	nbr;

	if (!addr)
		return (write(1, "(nil)", 5));
	nbr = (unsigned long)addr;
	i = nbrlen_addr(nbr);
	ptr = malloc(i + 3);
	if (!ptr)
		return (-1);
	ptr[i + 2] = '\0';
	ptr[1] = 'x';
	ptr[0] = '0';
	i--;
	while (i + 2 >= 2)
	{
		if ((nbr % 16) < 10)
			ptr[i + 2] = (nbr % 16) + 48;
		else
			ptr[i + 2] = (nbr % 16) + 87;
		nbr /= 16;
		i--;
	}
	return (ft_put_addr(ptr));
}
