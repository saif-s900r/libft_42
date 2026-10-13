/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadandi <sbadandi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:39:48 by sbadandi          #+#    #+#             */
/*   Updated: 2026/10/11 21:13:07 by sbadandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n, int fd)
{
	int	num;
	int	nb;

	num = n;
	if (num >= 10)
	{
		nb = num % 10 + '0';
		ft_putnbr_fd(num / 10, fd);
		write(fd, &nb, 1);
	}
	else
	{
		num += '0';
		write(fd, &num, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	num;

	num = n;
	if (num == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	if (num == 0)
	{
		write(fd, "0", 1);
	}
	else
		ft_putnbr(num, fd);
}
