/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:55:01 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/07 14:22:26 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *foin, const char *aiguille)
{
	unsigned int i;
	unsigned int j;
	unsigned int k;

	i = 0;
	if (aiguille == NULL || aiguille[0] == '\0')
		return ((char*)foin);
	while (foin[i])
	{
		j = i;
		k = 0;
		while (foin[j] == aiguille[k])
		{
			if (aiguille[k] == '\0' || aiguille[k + 1] == '\0')
				return ((char*)(&foin[i]));
			j++;
			k++;
		}
		i++;
	}
	return (NULL);
}
