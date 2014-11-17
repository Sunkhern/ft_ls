/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:00:51 by wromano           #+#    #+#             */
/*   Updated: 2014/11/10 15:10:13 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*res;

	if (s && f)
	{
		i = ft_strlen(s);
		j = 0;
		res = ft_strnew(i);
		while (j < i)
		{
			res[j] = (*f)(j, s[j]);
			j++;
		}
	}
	return (res);
}
