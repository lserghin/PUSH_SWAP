/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:12:16 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:12:17 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*variant_d;
	unsigned char		*variant_s;

	if (!dest && !src)
		return (NULL);
	variant_d = (unsigned char *)dest;
	variant_s = (unsigned char *)src;
	while (n--)
		*variant_d++ = *variant_s++;
	return (dest);
}
