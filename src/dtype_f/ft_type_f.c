/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 03:21:50 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/17 19:41:21 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int				ft_type_f(const char *format, va_list ap, t_pf_list *base)
{
	double		n;

	n = va_arg(ap, double);
	if (base->acc == 0 || base->width == 0)
		base->len = -1;
	else
		pf_ftoa(n, base);
	return (base->len);
}
