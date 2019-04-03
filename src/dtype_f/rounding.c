/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:51:47 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/20 18:51:50 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double			acnzero(long double n, t_pf_list *base)
{
	long double		nb;

	nb = n - (__uint128_t)n;
	nb *= 10;
	if ((base->acc - 1) == 0)
	{
		if ((__uint128_t)nb >= 5)
			n = n + 1;
	}
	return (n);
}

int					acczero(char c)
{
	float			nb;

	nb = c - '0';
	nb = nb / 2;
	if (nb != (int)nb)
		return (1);
	else
		return (0);
}
