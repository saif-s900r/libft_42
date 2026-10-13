/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadandi <sbadandi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:40:27 by sbadandi          #+#    #+#             */
/*   Updated: 2026/10/11 23:54:51 by sbadandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		if (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

int	word_len(char const *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	*get_word(char const *s, char c)
{
	char	*word;
	int		k;

	word = (char *)malloc(sizeof(char) * (word_len(s, c) + 1));
	if (!word)
		return (NULL);
	k = 0;
	while (s[k] && s[k] != c)
	{
		word[k] = s[k];
		k++;
	}
	word[k] = '\0';
	return (word);
}

char	**free_all(char **str, int j)
{
	while (j > 0)
	{
		j--;
		free(str[j]);
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			str[j] = get_word(s, c);
			if (!str[j])
				return (free_all(str, j));
			j++;
			while (*s != c && *s)
				s++;
		}
		if (*s && *s == c)
			s++;
	}
	str[j] = NULL;
	return (str);
}
