/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:14:13 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:14:14 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*variant_s1;
	unsigned char	*variant_s2;

	variant_s1 = (unsigned char *)s1;
	variant_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*variant_s1 && *variant_s2 && *variant_s1 == *variant_s2 && n > 0)
	{
		variant_s1++;
		variant_s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*variant_s1 - *variant_s2);
}
