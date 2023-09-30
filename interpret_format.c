/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 02:27:20 by yoda              #+#    #+#             */
/*   Updated: 2023/10/01 05:44:43 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*recognize_signs(const char *format, t_pflags *flags)
{
	while (*format == '0' || *format == '-' || *format == '+'
		|| *format == ' ' || *format == '#')
	{
		if (*format == '0' && !flags->minus)
			flags->zero = 1;
		else if (*format == '-')
		{
			flags->minus = 1;
			flags->zero = 0;
		}
		else if (*format == '+')
		{
			flags->plus = 1;
			flags->space = 0;
		}
		else if (*format == ' ' && !flags->plus)
			flags->space = 1;
		else if (*format == '#')
			flags->sharp = 1;
		format++;
	}
	return (format);
}

static const char	*recognize_width(const char *format, t_pflags *flags)
{
	flags->width = ft_atoi_only_num(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}

static const char	*recognize_precision(const char *format, t_pflags *flags)
{
	if (*format == '.')
	{
		flags->dot = 1;
		format++;
		flags->precision = ft_atoi_only_num(format);
		while (ft_isdigit(*format))
			format++;
	}
	return (format);
}

const char	*interpret_format(const char *format, t_pflags *flags)
{
	ft_bzero(flags, sizeof(t_pflags));
	format = recognize_signs(format, flags);
	format = recognize_width(format, flags);
	format = recognize_precision(format, flags);
	return (format);
}
