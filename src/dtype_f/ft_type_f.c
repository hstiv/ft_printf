/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 03:21:50 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/19 18:26:15 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_type_f(const char *format, va_list ap, t_pf_list *base)
{
	double		n;
	long double	nb;
	int			i;

	i = 0;
	if (base->ld > 0 || base->f > 0)
	{
		n = va_arg(ap, double);
		pf_ftoa(n, base);
	}
	else
	{
		nb = va_arg(ap, long double);
		pf_ftoa(nb, base);
	}
	if (base->d == 1)
		i++;
	format++;
	return (++i);
}
