/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:13:35 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:13:37 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*variant_s;

	if (!s)
		return (NULL);
	variant_s = (char *)s;
	while (*variant_s)
	{
		if (*variant_s == (char)c)
			return (variant_s);
		variant_s++;
	}
	if (*variant_s == (char)c)
		return (variant_s);
	return (NULL);
}
