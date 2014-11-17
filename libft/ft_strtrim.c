/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:39:39 by wromano           #+#    #+#             */
/*   Updated: 2014/11/10 15:18:19 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	if (s)
	{
		j = ft_strlen(s) - 1;
		res = ft_strnew(j + 1);
		i = 0;
		k = 0;
		while (ft_isblank(s[i]) == 1)
			i++;
		while (ft_isblank(s[j]) == 1)
			j--;
		while (i <= j)
		{
			res[k] = s[i];
			i++;
			k++;
		}
		res[k] = '\0';
	}
	return (res);
}
