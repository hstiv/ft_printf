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

long double			acczero(long double n, t_pf_list *base, int dot)
{
	int				d;
	long double		nb;

	d = dot * 10;
	nb = 0;
	if (base->acc == 0)
		if ((((int)n / 2) % 10) == 0)
		{
			while (dot--)
			{
				nb *= 10;
				n *= 10;
				nb += (int)n;
				n -= (int)n;
			}
			n *= 10;
			if ((int)n >= 5)
				nb += 1;
			return (nb * dot);
		}
		return (n);
}