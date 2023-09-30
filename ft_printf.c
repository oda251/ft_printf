/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:46:15 by yoda              #+#    #+#             */
/*   Updated: 2023/09/30 17:12:35 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*put_until_percent(const char *format, size_t *len)
{
	size_t	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	write(1, format, i);
	*len += i;
	return (format + i);
}

static const char	*put_converted(const char *format, va_list *ap, size_t *len)
{
	if (*format == 'c')
		format += solve_char(va_arg(*ap, int), len);
	else if (*format == 's')
		format += solve_str(va_arg(*ap, char*), len);
	else if (*format == 'p')
		format += solve_ptr(va_arg(*ap, unsigned long), len);
	else if (*format == 'd' || *format == 'i')
		format += solve_int(va_arg(*ap, int), len);
	else if (*format == 'u')
		format += solve_uint(va_arg(*ap, unsigned int), len);
	else if (*format == 'x')
		format += solve_hex_lowup(va_arg(*ap, int), 0, len);
	else if (*format == 'X')
		format += solve_hex_lowup(va_arg(*ap, int), 1, len);
	else if (*format == '%')
		format += solve_char('%', len);
	else
		solve_char('%', len);
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	if (!format)
		return (0);
	va_start(ap, format);
	while (*format)
	{
		format = put_until_percent(format, &len);
		if (*format == '%')
		{
			format = put_converted(format + 1, &ap, &len);
			if (!format)
				return (0);
		}
	}
	va_end(ap);
	return (len);
}
