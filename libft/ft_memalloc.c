/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:53:36 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/03 18:54:09 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *memory;

	memory = NULL;
	if (size)
	{
		memory = (void*)malloc(size);
		if (!memory)
			return (NULL);
		ft_memset(memory, 0, size);
	}
	return (memory);
}
