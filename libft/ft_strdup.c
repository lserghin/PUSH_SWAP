/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:13:41 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:13:43 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	slen;
	char	*str;
	char	*origin;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	str = malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	origin = str;
	while (*s)
		*str++ = *s++;
	*str = '\0';
	return (origin);
}
