/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 19:12:38 by wromano           #+#    #+#             */
/*   Updated: 2014/11/22 16:57:26 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_time(char *time)
{
	char	*str;
	char	*buf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buf = ft_strdup(time);
	str = ft_memalloc(sizeof(char) * 12);
	while (buf[j])
	{
		if (3 < j && j < 16)
		{
			str[i] = buf[j];
			i++;
		}
		j++;
	}
	str[i] = '\0';
	ft_putstr(str);
	ft_putchar(' ');
	free(str);
	free(buf);
}
