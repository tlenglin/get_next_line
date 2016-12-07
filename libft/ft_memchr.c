/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:55:53 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/03 18:56:45 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*src1;

	if (s == NULL)
		return (NULL);
	i = 0;
	src1 = (char*)s;
	while (i < n)
	{
		if (src1[i] == (char)c)
		{
			src1 = src1 + i;
			return (src1);
		}
		i++;
	}
	return (NULL);
}
