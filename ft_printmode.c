/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 20:48:42 by wromano           #+#    #+#             */
/*   Updated: 2014/11/22 17:57:17 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	lswritemode(mode_t mode)
{
	if (S_ISREG(mode))
		ft_putchar('-');
	else if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	ft_putchar(mode & S_IRUSR ? 'r' : '-');
	ft_putchar(mode & S_IWUSR ? 'w' : '-');
	ft_putchar(mode & S_IXUSR ? 'x' : '-');
	ft_putchar(mode & S_IRGRP ? 'r' : '-');
	ft_putchar(mode & S_IWGRP ? 'w' : '-');
	ft_putchar(mode & S_IXGRP ? 'x' : '-');
	ft_putchar(mode & S_IROTH ? 'r' : '-');
	ft_putchar(mode & S_IWOTH ? 'w' : '-');
	ft_putchar(mode & S_IXOTH ? 'x' : '-');
	ft_putstr("  ");
}

void	blocks(char **tab, char *dir, int arg)
{
	struct stat	mystat;
	char		*buf;
	int			i;
	int			ct;

	i = 0;
	ct = 0;
	while (tab[i])
	{
		buf = ft_strjoin(dir, tab[i]);
		lstat(buf, &mystat);
		if (arg % 7 == 0)
			ct = ct + mystat.st_blocks;
		else if (tab[i][0] != '.')
			ct = ct + mystat.st_blocks;
		free(buf);
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(ct);
	ft_putchar('\n');
}

void	print_l(struct stat mystat, int *sizes)
{
	lswritemode(mystat.st_mode);
	print_sizei(sizes[0], mystat.st_nlink);
	print_sizec2(sizes[1], getpwuid(mystat.st_uid)->pw_name);
	print_sizec2(sizes[2], getgrgid(mystat.st_gid)->gr_name);
	if (S_ISBLK(mystat.st_mode) || S_ISCHR(mystat.st_mode))
		print_majmin(sizes, major(mystat.st_rdev), minor(mystat.st_rdev));
	else
		print_sizei(sizes[3], mystat.st_size);
	print_time(ctime(&mystat.st_mtime));
}
