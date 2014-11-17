/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:01:33 by wromano           #+#    #+#             */
/*   Updated: 2014/11/17 20:44:25 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		intsize(int i)
{
	int		ct;

	ct = 1;
	while (i >= 10)
	{
		i = i / 10;
		ct++;
	}
	return (ct);
}

int		*maxsize(char **tab, char *dir)
{
	int		*sizes;

	sizes = ft_memalloc(sizeof(int) * 7);
	sizes[0] = nlinksize(tab, dir);
	sizes[1] = uidsize(tab, dir);
	sizes[2] = gidsize(tab, dir);
	sizes[3] = sizesize(tab, dir);
	sizes[4] = sizemin(tab, dir);
	sizes[5] = sizemaj(tab, dir);
	sizes[6] = 0;
	if (sizes[3] < sizes[4] + sizes[5] + 2)
		sizes[3] = sizes[4] + sizes[5] + 2;
	return (sizes);
}
