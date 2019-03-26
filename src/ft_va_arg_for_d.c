/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_for_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:41:21 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/26 12:41:23 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_l_ll_mod(va_list ap, t_pf_list *base)
{
	long long int		num;

	if (base->ld == 1)
		num = (long long int)va_arg(ap, long int);
	else
		num = va_arg(ap, long long int);
	return (num);
}

static long long int	ft_h_hh_mod(va_list ap, t_pf_list *base)
{
	long long int		num;

	if (base->d == 1)
		num = (long long int)va_arg(ap, int);
	else
		num = (long long int)va_arg(ap, int);
	return (num);
}

long long int			ft_va_arg_for_d(va_list ap, t_pf_list *base)
{
	intmax_t		num;

	if (base->ld)
		num = ft_l_ll_mod(ap, base);
	else if (base->d)
		num = ft_h_hh_mod(ap, base);
	else
		num = (int)va_arg(ap, int);
	return (num);
}
