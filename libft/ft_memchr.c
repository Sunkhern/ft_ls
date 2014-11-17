/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:51:31 by wromano           #+#    #+#             */
/*   Updated: 2014/11/05 16:38:20 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		if (*((unsigned char *)str + i) == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
