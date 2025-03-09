/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:14:23 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:14:25 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*find;
	char	*variant_s;

	find = NULL;
	variant_s = (char *)s;
	while (*variant_s)
	{
		if (*variant_s == (char)c)
			find = variant_s;
		variant_s++;
	}
	if (*variant_s == (char)c)
		return (variant_s);
	return (find);
}
