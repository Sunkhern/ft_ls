/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:36:59 by wromano           #+#    #+#             */
/*   Updated: 2014/11/05 15:24:52 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;
	int j;
	int l;

	i = 0;
	j = -42;
	l = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)&str[l]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			j = i;
		i++;
	}
	if (j != -42)
		return ((char *)&str[j]);
	return (NULL);
}
