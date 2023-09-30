/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:46:31 by yoda              #+#    #+#             */
/*   Updated: 2023/10/01 04:55:51 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"
# define UPPER 1
# define LOWER 0

typedef struct s_pflags
{
	unsigned int	zero;
	unsigned int	minus;
	ssize_t			width;
	unsigned int	dot;
	ssize_t			precision;
	unsigned int	plus;
	unsigned int	space;
	unsigned int	sharp;
}	t_pflags;
int	ft_printf(const char *format, ...);

#endif