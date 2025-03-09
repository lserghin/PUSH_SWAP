/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 23:13:17 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 23:13:18 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6), 6);
	count = 0;
	while (*(str + count))
		write(1, str + count++, 1);
	return (count);
}
