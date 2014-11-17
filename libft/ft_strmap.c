/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:42:42 by wromano           #+#    #+#             */
/*   Updated: 2014/11/10 17:14:43 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*res;

	if (s && f)
	{
		i = ft_strlen(s);
		j = 0;
		res = ft_strnew(i);
		while (j < i)
		{
			res[j] = (*f)(s[j]);
			j++;
		}
	}
	return (res);
}
