/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadandi <sbadandi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 19:29:33 by sbadandi          #+#    #+#             */
/*   Updated: 2026/10/11 23:33:50 by sbadandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			p = (char *)&s[i];
			return (p);
		}
		i++;
	}
	if ((char)c == 0)
		return ((char *)&s[i]);
	p = NULL;
	return (p);
}
