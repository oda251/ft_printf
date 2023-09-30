/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:46:31 by yoda              #+#    #+#             */
/*   Updated: 2023/09/30 17:17:59 by yoda             ###   ########.fr       */
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

int	solve_char(char c, size_t *len);
int	solve_str(char *str, size_t *len);
int	solve_int(int n, size_t *len);
int	solve_uint(unsigned int n, size_t *len);
int	solve_ptr(unsigned long ptr, size_t *len);
int	solve_hex_lowup(unsigned int n, int up_flag, size_t *len);
int	ft_printf(const char *format, ...);

#endif