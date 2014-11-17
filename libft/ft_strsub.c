/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:17:35 by wromano           #+#    #+#             */
/*   Updated: 2014/11/10 15:16:26 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	if (s && start && len)
	{
		i = 0;
		res = ft_strnew(len + 1);
		while (i < (len + start))
		{
			if (i >= start)
				res[i - start] = s[i];
			i++;
		}
	}
	return (res);
}
