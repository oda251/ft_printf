/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_format_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:43:08 by yoda              #+#    #+#             */
/*   Updated: 2023/09/29 19:22:43 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	solve_char(char **dest, char c)
{
	*dest = strjoin_realloc(*dest, &c, 1);
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
	return (1);
}
