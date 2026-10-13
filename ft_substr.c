/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadandi <sbadandi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:54:49 by sbadandi          #+#    #+#             */
/*   Updated: 2026/10/11 23:39:52 by sbadandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub;

	if (s == NULL)
		return (NULL);
	i = start;
	if (i >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - i)
		len = ft_strlen(s) - i;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	j = 0;
	while (j < len && s[i])
	{
		sub[j] = s[i];
		i++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}
