/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:23:43 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/19 18:00:34 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		neg_len(size_t *l, long double *n, t_pf_list *base)
{
	base->wid_bool = 0;
	if (base->plus && base->nol && !base->minus)
		base->temp++;
	if (*n < 0)
	{
		*n = *n * -1;
		*l = *l + 1;
	}
	else if (base->plus)
		*l = *l + 1;
	else
		*l = 0;
}

static size_t	foo(long double n, t_pf_list *base)
{
	size_t		l;

	l = 0;
	base->wid_bool = 0;
	base->acc = 6;
	while (n >= 1)
	{
		n /= 10;
		base->wid_bool++;
	}
	l = base->wid_bool + base->acc;
	base->temp = base->width - l;
	if (base->temp > 0)
		l += base->temp;
	return (l);
}

static size_t	len_zero(long double n, t_pf_list *base)
{
	size_t		l;

	l = 0;
	base->wid_bool = 0;
	while (n >= 1)
	{
		n /= 10;
		base->wid_bool++;
	}
	l = base->wid_bool;
	base->temp = base->width - l;
	if (base->temp > 0)
		l += base->temp;
	return (l);
}

size_t			facc(long double n, t_pf_list *base, int sign)
{
	size_t		l;

	sign = 0;
	neg_len(&l, &n, base);
	if (base->acc_bool)
	{
		if (base->acc)
		{
			while (n >= 1)
			{
				n /= 10;
				base->wid_bool++;
			}
			l = base->wid_bool + base->acc;
			base->temp += base->width - l - 1;
			if (base->temp > 0)
				l += base->temp;
		}
		else
			l += len_zero(n, base);
	}
	else
		l = foo(n, base);
	return (l);
}
