/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:03:07 by wromano           #+#    #+#             */
/*   Updated: 2014/11/10 17:23:01 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned		i;
	const char		*s1b;
	const char		*s2b;

	i = 0;
	s1b = s1;
	s2b = s2;
	while (i < n)
	{
		if (s1b[i] != s2b[i])
			return ((unsigned char)s1b[i] - (unsigned char)s2b[i]);
		i++;
	}
	return (0);
}
