/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:45:50 by wromano           #+#    #+#             */
/*   Updated: 2014/11/05 15:44:34 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	i = 0;
	j = 0;
	count = ft_strlen(s2);
	if (count == 0)
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[j])
		{
			i++;
			j = 0;
		}
		else
		{
			i++;
			j++;
		}
		if (j == count)
			return ((char *)&s1[i - j]);
	}
	return (NULL);
}
