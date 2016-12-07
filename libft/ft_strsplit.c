/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:53:15 by tlenglin          #+#    #+#             */
/*   Updated: 2016/11/08 12:44:59 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static unsigned int	ft_countword(char const *s, char c)
{
	unsigned int nb;
	unsigned int i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			nb++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (nb);
}

static char			**splitnext(char const *s, int c, char **split)
{
	unsigned int k;
	unsigned int i;
	unsigned int j;
	unsigned int l;

	k = 0;
	i = 0;
	while (s[i] && k < ft_countword(s, c))
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if ((split[k] = (char*)malloc(sizeof(char) * (j - i) + 1)) == NULL)
			return (NULL);
		l = 0;
		while (s[i] && s[i] != c)
			split[k][l++] = s[i++];
		split[k][l] = '\0';
		k++;
	}
	split[k] = NULL;
	return (split);
}

char				**ft_strsplit(char const *s, char c)
{
	char **split;

	if (s == NULL)
		return (NULL);
	split = (char**)malloc(sizeof(char*) * ft_countword(s, c) + 1);
	if (split == NULL)
		return (NULL);
	return (splitnext(s, c, split));
}
