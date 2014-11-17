/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:28:32 by wromano           #+#    #+#             */
/*   Updated: 2014/11/10 17:14:04 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		j = 0;
		res = ft_strnew(i + 1);
		i = 0;
		while (s1[i] != '\0')
		{
			res[j] = s1[i];
			i++;
			j++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			res[j++] = s2[i++];
		}
		res[j] = '\0';
	}
	return (res);
}
