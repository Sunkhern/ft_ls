/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 16:24:17 by wromano           #+#    #+#             */
/*   Updated: 2014/11/22 16:57:29 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	print_sizei(int size, int data)
{
	int		ct;

	ct = 0;
	if (intsize(data) < size)
		ct = size - intsize(data);
	while (ct > 0)
	{
		ft_putchar(' ');
		ct--;
	}
	ft_putnbr(data);
	ft_putchar(' ');
}

void	print_sizec(int size, char *data)
{
	int		ct;

	ct = 0;
	if (ft_strlen(data) < size)
		ct = size - ft_strlen(data);
	while (ct > 0)
	{
		ft_putchar(' ');
		ct--;
	}
	ft_putstr(data);
	ft_putchar(' ');
}

void	print_sizec2(int size, char *data)
{
	int		ct;

	ct = 0;
	if (ft_strlen(data) < size)
		ct = size - ft_strlen(data);
	ft_putstr(data);
	while (ct > 0)
	{
		ft_putchar(' ');
		ct--;
	}
	ft_putchar(' ');
	ft_putchar(' ');
}

void	print_majmin(int *size, int major, int minor)
{
	int		ct;
	int		ct2;

	ct = 0;
	ct2 = 0;
	if (intsize(minor) < size[4])
		ct2 = size[4] - intsize(minor);
	if (intsize(major) < size[5])
		ct = size[5] - intsize(major);
	while (ct-- > 0)
		ft_putchar(' ');
	ft_putnbr(major);
	ft_putstr(", ");
	while (ct2-- > 0)
		ft_putchar(' ');
	ft_putnbr(minor);
	ft_putchar(' ');
}
