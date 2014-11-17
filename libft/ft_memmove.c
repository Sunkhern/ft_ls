/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:38:21 by wromano           #+#    #+#             */
/*   Updated: 2014/11/10 17:13:16 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*str1;
	char		*str2;
	char		*temp;
	size_t		i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	temp = ft_strnew(ft_strlen(str2));
	temp = ft_strcpy(temp, str2);
	while (i < n)
	{
		str1[i] = temp[i];
		i++;
	}
	return (str1);
}
