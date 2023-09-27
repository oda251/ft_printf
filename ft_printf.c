/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:46:15 by yoda              #+#    #+#             */
/*   Updated: 2023/09/28 02:55:50 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*put_until_percent(const char *format, char **dest)
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

const char	*put_converted(const char *format, char **dest, va_list *ap)
{
	if (*format == CHAR)
		format = solve_char(dest, va_arg(*ap, char));
	else if (*format == STR)
		format = solve_str(dest, va_arg(*ap, char*));
	else if (*format == PTR)
		format = solve_lx(dest, va_arg(*ap, unsigned long));
	else if (*format == DEC || *format == INT)
		format = solve_int(dest, va_arg(*ap, int));
	else if (*format == U_DEC)
		format = solve_uint(dest, va_arg(*ap, unsigned int));
	else if (*format == HEX_LOWER)
		format = solve_hex_low(dest, va_arg(*ap, int));
	else if (*format == HEX_UPPER)
		format = solve_hex_up(dest, va_arg(*ap, int));
	else if (*format == PERCENT)
		format = solve_percent(dest);
	else
	{
		*dest = strjoin_realloc(*dest, "%", 1);
		if (!*dest)
			return (NULL);
	}
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char		*dest;

	if (!initialize_printf(&dest, format))
		return (0);
	va_start(ap, format);
	while (*format)
	{
		format = put_until_percent(format, &dest);
		if (!format)
			break ;
		if (*format == '%')
		{
			format = put_converted(format + 1, &dest, &ap);
			if (!format)
				return (0);
		}
	}
	va_end(ap);
	write(1, dest, ft_strlen(dest));
	return (ft_strlen(dest));
}

int main()
{
	ft_printf("Hello, world!\n");
	return 0;
}