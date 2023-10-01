/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_format_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:56:23 by yoda              #+#    #+#             */
/*   Updated: 2023/10/01 18:37:28 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	solve_with_flags(char *str, char *prefix, t_pflags *flags, size_t *len);

int	solve_ptr(unsigned long ptr, size_t *len, t_pflags *flags)
{
	char		*str;
	const char	*prefix = "0x";

	if (!ptr && flags->dot && !flags->precision)
		str = ft_calloc(1, 1);
	else
		str = ft_ultoa_hex(ptr, LOWER);
	if (!str)
		return (-1);
	solve_with_flags(str, (char *)prefix, flags, len);
	return (1);
}

int	solve_int(int n, size_t *len, t_pflags *flags)
{
	char	*str;
	char	*prefix;

	prefix = "\0";
	if (n == 0 && flags->dot && !flags->precision)
		str = ft_calloc(1, 1);
	else
		str = ft_itoa_sign_sep(n, &prefix);
	if (!str)
		return (-1);
	if (flags->space && *prefix != '-')
		prefix = " ";
	else if (flags->plus && *prefix != '-')
		prefix = "+";
	solve_with_flags(str, prefix, flags, len);
	return (1);
}

int	solve_uint(unsigned int n, size_t *len, t_pflags *flags)
{
	char	*str;

	if (n == 0 && flags->dot && !flags->precision)
		str = ft_calloc(1, 1);
	else
		str = ft_ultoa(n);
	if (!str)
		return (-1);
	solve_with_flags(str, "", flags, len);
	return (1);
}

int	solve_hex_lowup(unsigned int n, int up_flag, size_t *len, t_pflags *flags)
{
	char	*str;
	char	*prefix;

	if (n == 0 && flags->dot && !flags->precision)
		str = ft_calloc(1, 1);
	else if (up_flag)
		str = ft_ultoa_hex(n, UPPER);
	else
		str = ft_ultoa_hex(n, LOWER);
	if (!str)
		return (-1);
	prefix = "";
	if (flags->sharp && n)
	{
		if (up_flag)
			prefix = "0X";
		else
			prefix = "0x";
	}
	solve_with_flags(str, prefix, flags, len);
	return (1);
}
