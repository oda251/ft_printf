/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_format_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 02:56:23 by yoda              #+#    #+#             */
/*   Updated: 2023/09/29 10:32:58 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	solve_char(char **dest, char c)
{
	*dest = strjoin_realloc(*dest, &c, 1);
	if (!*dest)
		return (0);
	return (1);
}

int	solve_str(char **dest, char *str)
{
	if (!str)
	{
		strjoin_realloc(*dest, "(null)", 6);
		return (1);
	}
	*dest = strjoin_realloc(*dest, str, ft_strlen(str));
	if (!*dest)
		return (0);
	return (1);
}

int	solve_ptr(char **dest, unsigned long ptr)
{
	char	*str;

	str = ft_utoa_base(ptr, "0123456789abcdef");
	if (!str)
		return (0);
	*dest = strjoin_realloc(*dest, str, ft_strlen(str));
	free(str);
	if (!*dest)
		return (0);
	return (1);
}

int	solve_int(char **dest, int n)
{
	char	*str;

	str = ft_itoa(n);
	if (!str)
		return (0);
	*dest = strjoin_realloc(*dest, str, ft_strlen(str));
	free(str);
	if (!*dest)
		return (0);
	return (1);
}