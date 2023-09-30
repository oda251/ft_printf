/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_format_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:56:23 by yoda              #+#    #+#             */
/*   Updated: 2023/09/30 17:21:32 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	solve_ptr(unsigned long ptr, size_t *len)
{
	char	*str;
	size_t	str_len;

	str = ft_ultoa_hex(ptr, 0);
	if (!str)
		return (1);
	write(1, "0x", 2);
	str_len = ft_strlen(str);
	write(1, str, ft_strlen(str));
	free(str);
	(*len) += str_len + 2;
	return (1);
}

int	solve_int(int n, size_t *len)
{
	char	*str;
	size_t	str_len;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	str_len = ft_strlen(str);
	write(1, str, ft_strlen(str));
	free(str);
	(*len) += str_len;
	return (1);
}

int	solve_uint(unsigned int n, size_t *len)
{
	char	*str;
	size_t	str_len;

	str = ft_ultoa(n);
	if (!str)
		return (-1);
	str_len = ft_strlen(str);
	write(1, str, ft_strlen(str));
	free(str);
	(*len) += str_len;
	return (1);
}

int	solve_hex_lowup(unsigned int n, int up_flag, size_t *len)
{
	char	*str;
	size_t	str_len;

	if (up_flag)
		str = ft_ultoa_hex(n, UPPER);
	else
		str = ft_ultoa_hex(n, LOWER);
	if (!str)
		return (-1);
	str_len = ft_strlen(str);
	write(1, str, ft_strlen(str));
	free(str);
	(*len) += str_len;
	return (1);
}
