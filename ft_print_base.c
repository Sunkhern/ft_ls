/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:51:52 by wromano           #+#    #+#             */
/*   Updated: 2014/11/17 20:57:28 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_argnor(char **tab, int i, int arg, char *dir)
{
	struct stat	mystat;
	char		*buf;
	int			*sizes;

	sizes = maxsize(tab, dir);
	while (tab[i])
	{
		buf = ft_strjoin(dir, tab[i]);
		lstat(buf, &mystat);
		if (arg % 3 == 0)
			print_l(mystat, sizes, dir);
		ft_putstr(tab[i]);
		ft_putchar('\n');
		free(buf);
		i++;
	}
}

void	print_argr(char **tab, int i, int arg, char *dir)
{
	struct stat	mystat;
	char		*buf;
	int			*sizes;

	sizes = maxsize(tab, dir);
	while (i >= 0)
	{
		buf = ft_strjoin(dir, tab[i]);
		lstat(buf, &mystat);
		if (arg % 3 == 0)
			print_l(mystat, sizes, dir);
		ft_putstr(tab[i]);
		ft_putchar('\n');
		free(buf);
		i--;
	}
}

void	printdata(char **tab, int len, int arg, char *dir)
{
	int			i;
	struct stat	mystat;
	char		*buf;

	dir = ft_strjoin(dir, "/");
	i = 0;
	if (arg % 11 == 0)
		print_argr(tab, len - 1, arg, dir);
	else
		print_argnor(tab, 0, arg, dir);
}
