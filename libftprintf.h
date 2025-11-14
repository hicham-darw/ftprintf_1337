/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hamo <hel-hamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:21:04 by hel-hamo          #+#    #+#             */
/*   Updated: 2025/11/14 05:44:22 by hel-hamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_put_everything(va_list list, const char *s, int *ret);
int		nbrlen_addr(unsigned long n);
int		ft_put_addr(char *ptr);
int		print_address(void *addr);
size_t	ft_strlen(const char *s);
int		ft_nbrlen(long nbr);
int		ft_absolute(int nbr);
char	*ft_ltoa(long nbr);
int		print_arg_int(int arg, char c);
char	*ft_strdup(const char *s);
int		ft_nbrlen_hexa(unsigned int n);
char	*print_hexa(char *ptr, unsigned int nbr, int len, char c);
int		print_arg_unsigned(unsigned int nbr, char c);
int		print_string(const char *s);
int		print_invalid_format(char c);

#endif
