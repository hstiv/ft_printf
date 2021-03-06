/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_prntf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:47:03 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/30 19:06:15 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_prntf(unsigned long long int n)
{
	if (n <= 9)
	{
		n = n + '0';
		write(1, &n, 1);
	}
	else
	{
		ft_putnbr_prntf(n / 10);
		ft_putnbr_prntf(n % 10);
	}
}
