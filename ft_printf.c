/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:46:15 by yoda              #+#    #+#             */
/*   Updated: 2023/09/29 20:06:42 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*put_until_percent(const char *format, char **dest)
{
	size_t	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	*dest = strjoin_realloc(*dest, format, i);
	if (!*dest)
		return (NULL);
	return (format + i);
}

static const char	*put_converted(const char *format, char **dest, va_list *ap)
{
	if (*format == 'c')
		format += solve_char(dest, va_arg(*ap, int));
	else if (*format == 's')
		format += solve_str(dest, va_arg(*ap, char*));
	else if (*format == 'p')
		format += solve_ptr(dest, va_arg(*ap, unsigned long));
	else if (*format == 'd' || *format == 'i')
		format += solve_int(dest, va_arg(*ap, int));
	else if (*format == 'u')
		format += solve_uint(dest, va_arg(*ap, unsigned int));
	else if (*format == 'x')
		format += solve_hex_lowup(dest, va_arg(*ap, int), 0);
	else if (*format == 'X')
		format += solve_hex_lowup(dest, va_arg(*ap, int), 1);
	else if (*format == '%')
		format += solve_char(dest, '%');
	else
		solve_char(dest, '%');
	if (!*dest)
		return (NULL);
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char		*dest;
	size_t	len;

	if (!initialize_printf(&dest, format))
		return (0);
	va_start(ap, format);
	while (*format)
	{
		format = put_until_percent(format, &dest);
		if (!format)
			return (0) ;
		if (*format == '%')
		{
			format = put_converted(format + 1, &dest, &ap);
			if (!format)
				return (0);
		}
	}
	va_end(ap);
	len = ft_strlen(dest);
	write(1, dest, len);
	return (len);
}
