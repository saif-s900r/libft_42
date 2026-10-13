/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadandi <sbadandi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 20:30:23 by sbadandi          #+#    #+#             */
/*   Updated: 2026/10/11 23:27:00 by sbadandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	l1;
	unsigned char	l2;
	size_t			i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		l1 = (unsigned char)s1[i];
		l2 = (unsigned char)s2[i];
		if (l1 != l2)
			return (l1 - l2);
		i++;
	}
	return (0);
}
