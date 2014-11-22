/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:51:52 by wromano           #+#    #+#             */
/*   Updated: 2014/11/22 17:54:46 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ishidden(char *str)
{
	int i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == '/' && str[i + 1] != '.')
			return (0);
		if (str[i] == '/' && str[i + 1] == '.' && i != 0)
			return (1);
		i--;
	}
	return (0);
}

void	print_mini(char *str, struct stat mystat, int *sizes, int arg)
{
	if (arg % 3 == 0)
		print_l(mystat, sizes);
	ft_putstr(str);
	ft_putchar('\n');
}

void	print_argnor(char **tab, int i, int arg, char *dir)
{
	struct stat	mystat;
	char		*buf;
	int			*sizes;

	if (arg % 3 == 0)
		sizes = maxsize(tab, dir);
	while (tab[i])
	{
		if (arg % 7 == 0)
		{
			buf = ft_strjoin(dir, tab[i]);
			lstat(buf, &mystat);
			print_mini(tab[i], mystat, sizes, arg);
			free(buf);
		}
		else if (ft_strcmp(tab[i], ".") != 0 && ft_strcmp(tab[i], "..") != 0
				&& ft_strncmp(tab[i], ".", 1))
		{
			buf = ft_strjoin(dir, tab[i]);
			lstat(buf, &mystat);
			print_mini(tab[i], mystat, sizes, arg);
			free(buf);
		}
		i++;
	}
}

void	print_argr(char **tab, int i, int arg, char *dir)
{
	struct stat	mystat;
	char		*buf;
	int			*sizes;

	if (arg % 3 == 0)
		sizes = maxsize(tab, dir);
	while (i >= 0)
	{
		if (arg % 7 == 0)
		{
			buf = ft_strjoin(dir, tab[i]);
			lstat(buf, &mystat);
			print_mini(tab[i], mystat, sizes, arg);
			free(buf);
		}
		else if (ft_strcmp(tab[i], ".") != 0 && ft_strcmp(tab[i], "..") != 0
				&& ft_strncmp(tab[i], ".", 1))
		{
			buf = ft_strjoin(dir, tab[i]);
			lstat(buf, &mystat);
			print_mini(tab[i], mystat, sizes, arg);
			free(buf);
		}
		i--;
	}
}

void	printdata(char **tab, int len, int arg, char *dir)
{
	int		ct;

	ct = 0;
	if (ishidden(dir) == 0 || arg % 7 == 0)
	{
		print_ismulti(dir, arg);
		if (arg % 23 == 0 && arg % 17 != 0)
		{
			ft_putstr(dir);
			ft_putstr(":\n");
		}
		dir = ft_strjoin(dir, "/");
		if (arg % 3 == 0)
			blocks(tab, dir, arg);
		if (tab[0] == NULL)
			return ;
		if (arg % 13 == 0)
			tab = ft_sorttime(ct, tab, dir);
		if (arg % 11 == 0)
			print_argr(tab, len - 1, arg, dir);
		else
			print_argnor(tab, 0, arg, dir);
		if (arg % 23 == 0)
			ft_putstr("\n");
	}
}
