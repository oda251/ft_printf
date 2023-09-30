/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_format_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:43:08 by yoda              #+#    #+#             */
/*   Updated: 2023/09/30 17:19:13 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	solve_char(char c, size_t *len)
{
	write(1, &c, 1);
	(*len)++;
	return (1);
}

int	solve_str(char *str, size_t *len)
{
	size_t	str_len;

	if (!str)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return (1);
	}
	str_len = ft_strlen(str);
	write(1, str, str_len);
	(*len) += str_len;
	return (1);
}
