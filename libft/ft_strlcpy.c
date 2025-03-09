/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:14:01 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:14:03 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	size;

	if (!src)
		return (0);
	srclen = ft_strlen(src);
	size = dstsize - 1;
	if (dstsize == 0)
		return (srclen);
	while (*src && size--)
		*dst++ = *src++;
	*dst = '\0';
	return (srclen);
}
