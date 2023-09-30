/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_format_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:43:08 by yoda              #+#    #+#             */
/*   Updated: 2023/10/01 06:54:11 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	solve_percent_sub(char *buf, size_t *len, char *width, char *precision);

static size_t	solve_per_sub(
	char *buf, t_pflags *flags, char **width, char **precision)
{
	size_t	size;

	*width = "";
	*precision = "";
	size = 1;
	if (flags->sharp)
		buf[size++] = '#';
	if (flags->plus)
		buf[size++] = '+';
	if (flags->space)
		buf[size++] = ' ';
	if (flags->minus)
		buf[size++] = '-';
	if (flags->zero)
		buf[size++] = '0';
	buf[size] = '\0';
	if (flags->width)
		*width = ft_itoa(flags->width);
	if (flags->dot)
		*precision = ft_itoa(flags->precision);
	return (size);
}

int	solve_percent(t_pflags *flags, char c, size_t *len)
{
	size_t	size;
	char	buf[5];
	char	*width;
	char	*precision;

	size = 0;
	buf[0] = '%';
	if (c == '%')
	{
		write(1, buf, 1);
		(*len)++;
		return (1);
	}
	size = solve_per_sub(buf, flags, &width, &precision);
	if (!width || !precision)
		return (-1);
	(*len) += size;
	if (c != '\0')
	{
		solve_percent_sub(buf, len, width, precision);
		return (0);
	}
	return (-1);
}

int	solve_char(char c, size_t *len, t_pflags *flags)
{
	if (flags->width == 0)
		flags->width = 1;
	*len += flags->width;
	if (flags->minus)
	{
		write(1, &c, 1);
		while (flags->width-- > 1)
			write(1, " ", 1);
	}
	else
	{
		while (flags->width-- > 1)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	return (1);
}

static void	solve_str_sub(
	char *str, size_t str_len, size_t width, t_pflags *flags)
{
	if (flags->minus)
	{
		write(1, str, str_len);
		while (width-- > str_len)
			write(1, " ", 1);
	}
	else
	{
		while (width-- > str_len)
			write(1, " ", 1);
		write(1, str, str_len);
	}
}

int	solve_str(char *str, size_t *len, t_pflags *flags)
{
	size_t	str_len;
	size_t	width;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	if (flags->dot && (size_t) flags->precision < str_len)
		str_len = flags->precision;
	if ((size_t) flags->width < str_len)
		width = str_len;
	else
		width = flags->width;
	solve_str_sub(str, str_len, width, flags);
	(*len) += width;
	return (1);
}
