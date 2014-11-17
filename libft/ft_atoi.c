/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:44:55 by wromano           #+#    #+#             */
/*   Updated: 2014/11/05 14:27:58 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spe(int c)
{
	char	*spe_char;
	int		i;

	spe_char = "\n\v\t\r\f ";
	i = 0;
	while (i < 6)
	{
		if (spe_char[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	int		s;
	int		np;

	s = 0;
	np = 1;
	while (ft_spe(*str))
	{
		str++;
	}
	while ((*str == '+' || *str == '-') && np == 1)
	{
		if (*str == '-' || *(str + 1) == '+')
		{
			np = -1;
			if (*(str - 1) == '+')
				str--;
		}
		str++;
	}
	while (*str != '\0' && *str >= 48 && *str <= 57)
	{
		s = s * 10 + (*str) - 48;
		str++;
	}
	return (s * np);
}
