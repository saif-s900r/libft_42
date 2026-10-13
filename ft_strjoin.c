/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadandi <sbadandi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 16:37:12 by sbadandi          #+#    #+#             */
/*   Updated: 2026/10/11 21:44:42 by sbadandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*alloc(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*sup;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	len = i + j;
	sup = malloc(len + 1);
	if (sup == NULL)
		return (NULL);
	return (sup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sup;
	int		i;
	int		j;

	sup = alloc(s1, s2);
	i = 0;
	while (s1[i])
	{
		sup[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		sup[i] = s2[j];
		i++;
		j++;
	}
	sup[i] = '\0';
	return (sup);
}
