/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsize3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:18:28 by wromano           #+#    #+#             */
/*   Updated: 2014/11/17 20:46:40 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		minisize(struct stat mystat, int ct, int ct2)
{
	if (S_ISBLK(mystat.st_mode) || S_ISCHR(mystat.st_mode))
	{
		ct2 = intsize(major(mystat.st_rdev)) +
		intsize(minor(mystat.st_rdev)) + 2;
		if (ct <= ct2)
			ct = ct2;
	}
	else if (ct <= intsize(mystat.st_size))
		ct = intsize(mystat.st_size);
	return (ct);
}

int		sizesize(char **tab, char *dir)
{
	int			ct;
	int			ct2;
	int			i;
	char		*buf;
	struct stat	mystat;

	i = 0;
	ct = 0;
	ct2 = 0;
	while (tab[i])
	{
		buf = ft_strjoin(dir, tab[i]);
		if (lstat(buf, &mystat) == 0)
			ct = minisize(mystat, ct, ct2);
		i++;
	}
	free(buf);
	return (ct);
}

int		sizemin(char **tab, char *dir)
{
	int			ct;
	int			i;
	char		*buf;
	struct stat	mystat;

	i = 0;
	ct = 0;
	while (tab[i])
	{
		buf = ft_strjoin(dir, tab[i]);
		if (lstat(buf, &mystat) == 0)
		{
			if (ct <= intsize(minor(mystat.st_rdev))
				&& (S_ISBLK(mystat.st_mode) || S_ISCHR(mystat.st_mode)))
				ct = intsize(minor(mystat.st_rdev));
		}
		i++;
	}
	free(buf);
	return (ct);
}

int		sizemaj(char **tab, char *dir)
{
	int			ct;
	int			i;
	char		*buf;
	struct stat	mystat;

	i = 0;
	ct = 0;
	while (tab[i])
	{
		buf = ft_strjoin(dir, tab[i]);
		if (lstat(buf, &mystat) == 0)
		{
			if (ct <= intsize(major(mystat.st_rdev))
				&& (S_ISBLK(mystat.st_mode) || S_ISCHR(mystat.st_mode)))
				ct = intsize(major(mystat.st_rdev));
		}
		i++;
	}
	free(buf);
	return (ct);
}
