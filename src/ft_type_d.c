/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:19:19 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/17 05:19:14 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_d(const char *format, va_list ap, int i, t_pf_list *base)
{
	int		num;

	num = va_arg(ap, int);
	base->len_str = ft_numlen(num);
	ft_spaces_nol(base);
	if (base->plus == 1 && num >= 0)
	{
		ft_putchar('+');
		ft_putnbr(num);
	}
	else if (base->space == 1 && base->plus != 1 && num >= 0)
	{
		ft_putchar(' ');
		ft_putnbr(num);
	}
	else
	{
		ft_putnbr(num);
		base->len += base->len_str;
	}
	ft_spaces_nol(base);
	i++;
	return (i);
}
