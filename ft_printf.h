/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:46:31 by yoda              #+#    #+#             */
/*   Updated: 2023/09/28 02:09:23 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# define CHAR 'c'
# define STR 's'
# define PTR 'p'
# define DEC 'd'
# define INT 'i'
# define U_DEC 'u'
# define HEX_LOWER 'x'
# define HEX_UPPER 'X'
# define PERCENT '%'

int		initialize_printf(char **dest, const char *format);
int		ft_printf(const char *, ...);
char	*strjoin_realloc(char *root, const char *src, size_t len);

#endif