/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:31:55 by wromano           #+#    #+#             */
/*   Updated: 2014/11/08 17:38:33 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbrinstr(char *str, int n, int np, int i)
{
	if (n > 9)
		ft_putnbrinstr(str, n / 10, np, i - 1);
	str[i] = '0' + n % 10;
	if (np == -1)
		str[0] = '-';
	return (str);
}

static int	ft_intlen(unsigned int n)
{
	int		i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_groscrade(char *str)
{
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		len;
	int		np;
	char	*res;

	np = 1;
	if (n == -2147483648)
	{
		res = ft_strnew(12);
		res = ft_groscrade(res);
		return (res);
	}
	if (n < 0)
	{
		n = -n;
		np = -1;
	}
	len = ft_intlen(n);
	if (np == -1)
		len = len + 1;
	res = ft_strnew(len + 1);
	ft_putnbrinstr(res, n, np, len - 1);
	res[len] = '\0';
	return (res);
}
