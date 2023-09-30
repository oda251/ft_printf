/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_format_chars_sub.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 06:24:33 by yoda              #+#    #+#             */
/*   Updated: 2023/10/01 06:40:57 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	solve_percent_sub(char *buf, size_t *len,
	char *width, char *precision)
{
	const size_t	width_len = ft_strlen(width);
	const size_t	precision_len = ft_strlen(precision);

	ft_putstr(buf);
	if (*width)
	{
		write(1, width, width_len);
		(*len) += width_len;
		free(width);
	}
	if (*precision)
	{
		write(1, ".", 1);
		write(1, precision, precision_len);
		(*len) += precision_len + 1;
		free(precision);
	}
}
