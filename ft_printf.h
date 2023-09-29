/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:46:31 by yoda              #+#    #+#             */
/*   Updated: 2023/09/29 21:29:39 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# define UPPER 1
# define LOWER 0

int		solve_char(char **dest, char c);
int		solve_str(char **dest, char *str);
int		solve_int(char **dest, int n);
int		solve_uint(char **dest, unsigned int n);
int		solve_ptr(char **dest, unsigned long ptr);
int		solve_hex_lowup(char **dest, unsigned int n, int up_flag);
int		initialize_printf(char **dest, const char *format);
int		ft_printf(const char *, ...);
char	*strjoin_realloc(char *root, const char *src, size_t len);

#endif