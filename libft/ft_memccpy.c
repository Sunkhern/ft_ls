/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:47:03 by wromano           #+#    #+#             */
/*   Updated: 2014/11/05 15:47:05 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char	*src1;
	char		*dest1;

	dest1 = dest;
	src1 = src;
	while (n > 0)
	{
		*dest1++ = *src1;
		if ((char)c == *src1)
			return (dest1);
		src1++;
		n--;
	}
	return (NULL);
}
