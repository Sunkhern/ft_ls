/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argmake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:47:23 by wromano           #+#    #+#             */
/*   Updated: 2014/11/17 20:50:24 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		argcheck(char *core, int ct)
{
	int		i;

	i = 1;
	while (core[i] && i <= 5)
	{
		if (core[i] == 'l' && ct % 3 != 0)
			ct *= 3;
		else if (core[i] == 'R' && ct % 5 != 0)
			ct *= 5;
		else if (core[i] == 'a' && ct % 7 != 0)
			ct *= 7;
		else if (core[i] == 'r' && ct % 11 != 0)
			ct *= 11;
		else if (core[i] == 't' && ct % 13 != 0)
			ct *= 13;
		else if (core[i] == 'l' || core[i] == 'R' || core[i] == 'a' ||
				core[i] == 'r' || core[i] == 't')
			return (ct);
		else
			return (-1);
		i++;
	}
	return (ct);
}

int		treat_core(char **core, int argnb)
{
	int		i;
	int		j;
	int		ct;

	i = 1;
	ct = 1;
	if (core[0] == NULL)
		return (0);
	while (i < argnb)
	{
		if (core[i][0] == '-')
		{
			ct = argcheck(core[i], ct);
			if (ct < 0)
				return (-1);
		}
		i++;
	}
	return (ct);
}
