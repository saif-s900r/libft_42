/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadandi <sbadandi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 17:25:16 by sbadandi          #+#    #+#             */
/*   Updated: 2026/10/11 21:28:00 by sbadandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*res;
	int		len;

	num = (long)n;
	len = ft_len(num);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (num < 0)
	{
		num = -num;
		res[0] = '-';
	}
	res[len] = '\0';
	if (num == 0)
		res[0] = '0';
	while (num != 0)
	{
		res[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (res);
}
