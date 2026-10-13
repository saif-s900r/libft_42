/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadandi <sbadandi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 15:21:55 by sbadandi          #+#    #+#             */
/*   Updated: 2026/09/25 17:46:19 by sbadandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_set(char c, char const *set)
{
	int		i;
	int		in;
	char	*set1;

	set1 = (char *)set;
	i = 0;
	in = 0;
	while (set1[i])
	{
		if (set1[i] == c)
		{
			in = 1;
			return (in);
		}
		i++;
	}
	return (in);
}

int	find_start(char const *s1, char const *set)
{
	int	i;
	int	start;

	i = 0;
	while (s1[i] && in_set(s1[i], set))
		i++;
	start = i;
	return (start);
}

int	find_end(char const *s1, char const *set)
{
	int	len;
	int	end;

	len = ft_strlen(s1) - 1;
	while ((len >= 0) && in_set(s1[len], set))
		len--;
	end = len;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*result;

	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start > end)
		len = 0;
	else
		len = end - start + 1;
	result = ft_substr(s1, start, len);
	return (result);
}
