/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 13:20:05 by wromano           #+#    #+#             */
/*   Updated: 2014/11/22 17:48:08 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_sort(char **tab)
{
	int y;

	y = 0;
	while (tab[y + 1])
	{
		if (ft_strcmp(tab[y], tab[y + 1]) > 0)
		{
			swap(&tab[y], &tab[y + 1]);
			if (y > 0)
				y--;
			continue;
		}
		y++;
	}
	return (tab);
}

char	**ft_sorttime(int ct, char **tab, char *dir)
{
	char		*tmp;
	char		*tmp2;
	struct stat	buff;
	struct stat	buff2;

	while (tab[ct + 1])
	{
		tmp = ft_strjoin(dir, tab[ct]);
		tmp2 = ft_strjoin(dir, tab[ct + 1]);
		lstat(tmp, &buff);
		lstat(tmp2, &buff2);
		if (buff.st_mtime < buff2.st_mtime)
		{
			swap(&tab[ct], &tab[ct + 1]);
			free(tmp);
			free(tmp2);
			if (ct > 0)
				ct--;
			continue;
		}
		free(tmp);
		free(tmp2);
		ct++;
	}
	return (tab);
}

void	printwrongdir(char *str)
{
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": No such file or directory", 2);
	ft_putchar_fd('\n', 2);
}

char	**dirsort(char **src, int arg)
{
	char	**tab;
	int		ct;
	int		i;
	int		j;

	ct = dirnb(src);
	i = 1;
	j = 0;
	tab = (char**)ft_memalloc(sizeof(char *) * ct + 1);
	while (src[i][0] == '-')
		i++;
	while (src[i])
	{
		if (dircheck(src[i]) == 1)
		{
			tab[j] = ft_strdup(src[i]);
			j++;
		}
		i++;
	}
	tab[j] = NULL;
	tab = ft_sort(tab);
	return (tab);
}

int		minisizer(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i - 1);
}
