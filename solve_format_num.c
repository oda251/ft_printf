/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_format_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:56:23 by yoda              #+#    #+#             */
/*   Updated: 2023/09/29 19:46:32 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	solve_ptr(char **dest, unsigned long ptr)
{
	char	*str;

	str = ft_ultoa_hex(ptr, 0);
	if (!str)
		return (1);
	*dest = strjoin_realloc(*dest, "0x", 2);
	if (!*dest)
		return (1);
	*dest = strjoin_realloc(*dest, str, ft_strlen(str));
	free(str);
	return (1);
}

int	solve_int(char **dest, int n)
{
	char	*str;

	str = ft_itoa(n);
	if (!str)
		return (1);
	*dest = strjoin_realloc(*dest, str, ft_strlen(str));
	free(str);
	if (!*dest)
		return (1);
	return (1);
}

int	solve_uint(char **dest, unsigned int n)
{
	char	*str;

	str = ft_ultoa(n);
	if (!str)
		return (1);
	*dest = strjoin_realloc(*dest, str, ft_strlen(str));
	free(str);
	if (!*dest)
		return (1);
	return (1);
}

int	solve_hex_lowup(char **dest, unsigned int n, int up_flag)
{
	char	*str;

	if (up_flag)
		str = ft_ultoa_hex(n, UPPER);
	else
		str = ft_ultoa_hex(n, LOWER);
	if (!str)
		return (1);
	*dest = strjoin_realloc(*dest, str, ft_strlen(str));
	free(str);
	if (!*dest)
		return (1);
	return (1);
}
