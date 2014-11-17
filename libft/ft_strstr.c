/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:59:27 by wromano           #+#    #+#             */
/*   Updated: 2014/11/10 12:53:45 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	pos;

	if (!*s2)
		return ((char *)s1);
	pos = ft_strlen(s2);
	while (*s1)
	{
		if (ft_strncmp(s1++, s2, pos) == 0)
			return ((char *)s1 - 1);
	}
	return (NULL);
}
