/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 14:47:22 by wromano           #+#    #+#             */
/*   Updated: 2014/11/22 17:42:32 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ismulti(char **tab)
{
	int i;
	int ct;

	i = 1;
	ct = 0;
	while (tab[i])
	{
		if (tab[i][0] != '-')
			ct++;
		i++;
	}
	if (ct > 1)
		return (1);
	return (0);
}

int		littleln(int arg)
{
	if (arg % 19 != 0)
	{
		arg = arg * 19;
		ft_putchar('\n');
	}
	return (arg);
}

void	print_ismulti(char *tab, int arg)
{
	if (arg % 17 == 0)
	{
		ft_putstr(tab);
		ft_putchar(':');
		ft_putchar('\n');
	}
}

void	iswrongargprint(int i, char **tab)
{
	int		j;

	j = 1;
	while (tab[i][j])
	{
		if (tab[i][j] != 'R' && tab[i][j] != 'r' && tab[i][j] != 't'
			&& tab[i][j] != 'l' && tab[i][j] != 'a')
			ft_putchar_fd(tab[i][j], 2);
		j++;
	}
}

int		iswrongarg(int arg, char **tab)
{
	int		i;

	i = 0;
	if (arg == -1)
	{
		ft_putstr_fd("ls illegal option -- ", 2);
		while (tab[i] != NULL)
		{
			if (tab[i][0] == '-')
				iswrongargprint(i, tab);
			i++;
		}
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("usage: ls [-Ralrt] [file ...]", 2);
		ft_putchar_fd('\n', 2);
		return (0);
	}
}
