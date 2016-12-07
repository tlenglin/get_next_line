/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:52:10 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/03 19:53:00 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;

	if (s == NULL)
		return (NULL);
	str = (char*)s;
	i = ft_strlen(s);
	while (str[i] != (char)c && i > 0)
		i--;
	if (str[i] == (char)c)
		return (str + i);
	return (NULL);
}
