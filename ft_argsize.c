/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 15:45:04 by wromano           #+#    #+#             */
/*   Updated: 2014/11/17 20:45:45 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>
#include <stdio.h>

int		nlinksize(char **tab, char *dir)
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
			if (ct <= intsize(mystat.st_nlink))
				ct = intsize(mystat.st_nlink);
		}
		i++;
	}
	free(buf);
	return (ct);
}

int		uidsize(char **tab, char *dir)
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
			if (ct <= ft_strlen(getpwuid(mystat.st_uid)->pw_name))
				ct = ft_strlen(getpwuid(mystat.st_uid)->pw_name);
		}
		i++;
	}
	free(buf);
	return (ct);
}

int		gidsize(char **tab, char *dir)
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
			if (ct <= ft_strlen(getgrgid(mystat.st_gid)->gr_name))
				ct = ft_strlen(getgrgid(mystat.st_gid)->gr_name);
		}
		i++;
	}
	free(buf);
	return (ct);
}
