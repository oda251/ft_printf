/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:46:15 by yoda              #+#    #+#             */
/*   Updated: 2023/10/01 07:57:36 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			solve_char(char c, size_t *len, t_pflags *flags);
int			solve_str(char *str, size_t *len, t_pflags *flags);
int			solve_ptr(unsigned long ptr, size_t *len, t_pflags *flags);
int			solve_int(int n, size_t *len, t_pflags *flags);
int			solve_uint(unsigned int n, size_t *len, t_pflags *flags);
int			solve_hex_lowup(
				unsigned int n, int up_flag, size_t *len, t_pflags *flags);
int			solve_ptr(unsigned long ptr, size_t *len, t_pflags *flags);
int			solve_percent(t_pflags *flags, char c, size_t *len);
const char	*interpret_format(const char *format, t_pflags *flags);

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

static const char	*put_converted(const char *format,
	va_list *ap, size_t *len, t_pflags *flags)
{
	int	result;

	result = 0;
	if (*format == 'c')
		result = solve_char(va_arg(*ap, int), len, flags);
	else if (*format == 's')
		result = solve_str(va_arg(*ap, char *), len, flags);
	else if (*format == 'p')
		result = solve_ptr(va_arg(*ap, unsigned long), len, flags);
	else if (*format == 'd' || *format == 'i')
		result = solve_int(va_arg(*ap, int), len, flags);
	else if (*format == 'u')
		result = solve_uint(va_arg(*ap, unsigned int), len, flags);
	else if (*format == 'x')
		result = solve_hex_lowup(va_arg(*ap, int), 0, len, flags);
	else if (*format == 'X')
		result = solve_hex_lowup(va_arg(*ap, int), 1, len, flags);
	else if (*format == '%')
		result = solve_percent(flags, *format, len);
	else
		result = solve_percent(flags, *format, len);
	if (result == -1)
		return (NULL);
	return (format + result);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		len;
	t_pflags	flags;

	if (!format)
		return (0);
	len = 0;
	va_start(ap, format);
	while (*format)
	{
		format = put_until_percent(format, &len);
		if (*format == '%')
		{
			format = interpret_format(format + 1, &flags);
			format = put_converted(format, &ap, &len, &flags);
			if (!format)
				return (-1);
		}
	}
	va_end(ap);
	return (len);
}

// int main()
// {
// 	char *str = "[%.5d]";

// 	printf("%d\n", ft_printf(str, -1));
// 	printf("\n");
// 	printf("%d\n", printf(str, -1));
// 	printf("\n");
// 	return (0);
// }