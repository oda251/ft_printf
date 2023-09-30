/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_format_nums_sub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 04:18:53 by yoda              #+#    #+#             */
/*   Updated: 2023/10/01 07:57:27 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_zero_len(size_t str_len, size_t pre_len, t_pflags *flags)
{
	size_t	zero_len;

	zero_len = 0;
	if (flags->dot && (size_t) flags->precision > str_len)
		zero_len = flags->precision - str_len;
	else if (flags->zero && !flags->dot && (size_t)flags->width > str_len)
		zero_len = flags->width - str_len - pre_len;
	return (zero_len);
}

static char	*get_space_char(t_pflags *flags)
{
	char	*space;

	space = " ";
	if (flags->zero && !flags->dot)
		space = "0";
	return (space);
}

static void	put_contents_and_free(
	char *str, char *prefix, size_t str_len, size_t zero_len)
{
	write(1, prefix, ft_strlen(prefix));
	while (zero_len-- > 0)
		write(1, "0", 1);
	write(1, str, str_len);
	free(str);
}

void	put_spaces(
	size_t *len, const char *space, size_t width, t_pflags *flags)
{
	while (flags->width != SSIZE_MAX
		&& (size_t)(flags->width)-- > width)
	{
		write(1, space, 1);
		(*len)++;
	}
}

void	solve_with_flags(char *str, char *prefix, t_pflags *flags, size_t *len)
{
	size_t			zero_len;
	const char		*space = get_space_char(flags);
	const size_t	str_len = ft_strlen(str);
	const size_t	pre_len = ft_strlen(prefix);

	zero_len = get_zero_len(str_len, pre_len, flags);
	*len += str_len + zero_len + pre_len;
	if (flags->minus)
	{
		put_contents_and_free(str, prefix, str_len, zero_len);
		put_spaces(len, space, str_len + zero_len + pre_len, flags);
	}
	else
	{
		put_spaces(len, space, str_len + zero_len + pre_len, flags);
		put_contents_and_free(str, prefix, str_len, zero_len);
	}
}
