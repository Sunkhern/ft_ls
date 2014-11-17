/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:17:42 by wromano           #+#    #+#             */
/*   Updated: 2014/11/05 14:36:52 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	lens1;
	size_t	lens2;
	size_t	lenor;

	lenor = n;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	while (*s1 && n)
	{
		s1++;
		n--;
	}
	if (!n)
		return (lenor + lens2);
	while (*s2 && n-- > 1)
		*s1++ = *s2++;
	*s1 = '\0';
	return (lens1 + lens2);
}
