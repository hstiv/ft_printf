/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 07:46:32 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/28 06:15:05 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				type_g_maker(t_pf_list *b, long double nb, int i)
{
	if (i >= 6 && ((!b->acc_bool && !b->wid_bool)
							|| (!b->acc && !b->width)))
	{
		if (!b->acc_bool)
		{
			b->acc = 5;
			b->acc_bool = 1;
		}
		ft_type_e(nb, b);
	}
	else
	{
		b->acc = 5 - i;
		b->acc_bool = 1;
		pf_ftoa(nb, b);
	}
}

static void				ft_tttype_g(long double nb, t_pf_list *base)
{
	long double			n;
	int					i;

	n = nb;
	i = 0;
	if (n < 0)
		n *= -1;
	while ((long long int)n > 9 && ++i)
		n = n / 10;
	if (base->wid_bool && base->acc_bool && base->width && base->acc)
	{
		if (base->width < base->acc)
		{
			base->acc = 9;
			pf_ftoa(nb, base);
			return ;
		}
	}
	type_g_maker(base, nb, i);
}

int						ft_type_g(const char *format, va_list ap,
												int i, t_pf_list *base)
{
	if (*format == 'g' || (*format == 'L' && *(format + 1) == 'g') ||
														*format == 'G')
	{
		if (*format == 'L')
		{
			i += 2;
			ft_tttype_g(va_arg(ap, long double), base);
		}
		else
		{
			i++;
			if (*format == 'G')
				base->num_l = 1;
			ft_tttype_g(va_arg(ap, double), base);
		}
	}
	else if (*format == 'r')
	{
		ft_type_r(ap, base);
		i++;
	}
	format++;
	return (i);
}
