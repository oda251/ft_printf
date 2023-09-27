/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoda <yoda@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 01:38:54 by yoda              #+#    #+#             */
/*   Updated: 2023/09/28 02:09:28 by yoda             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	initialize_printf(char **dest, const char *format)
{
	if (!format)
		return (0);
	*dest = malloc(1);
	if (!*dest)
		return (0);
	**dest = '\0';
	return (1);
}

char	*strjoin_realloc(char *root, const char *src, size_t len)
{
	char					*dest;
	const size_t	len_root = ft_strlen(root);
	size_t				i;

	dest = malloc(len_root + len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < len_root)
	{
		dest[i] = root[i];
		i++;
	}
	while (i < len_root + len)
	{
		dest[i] = src[i - len_root];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
