/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wromano <wromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:45:15 by wromano           #+#    #+#             */
/*   Updated: 2014/11/07 18:56:00 by wromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;

	res = malloc(sizeof(char) * size + 1);
	if (res == NULL)
		return (NULL);
	ft_bzero(res, size + 1);
	return (res);
}
