/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_e_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 03:37:13 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/28 06:17:56 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_type_e(long double nb, t_pf_list *base)
{
	if (nb < 0)
	{
		base->neg = '-';
		nb *= -1;
	}
	while ((long long int)nb > 9)
	{
		base->num_h++;
		nb = nb / 10;
	}
	base->width -= 4;
	pf_ftoa(nb, base);
	if (!base->minus)
	{
		(base->num_l == 1) ? write(1, "E+", 2) : write(1, "e+", 2);
		if (base->num_h > 9)
			ft_putstr(ft_itoa(base->num_h));
		else
		{
			ft_putchar(48);
			ft_putchar(base->num_h + '0');
		}
		base->len_return += 4;
	}
}
