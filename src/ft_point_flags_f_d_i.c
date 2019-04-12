/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 04:50:23 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/12 11:39:34 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void			ft_help_d_i(const char *format, t_pf_list *base)
{
	if (*format == 'd')
		base->hew = 0;
	if (*format == 'D')
		base->ld = 2;
	if (base->f == 100)
	{
		base->d = 0;
		base->ld = 2;
		base->k = 0;
		base->f = 0;
		base->g_e = 1;
	}
	if (base->acc)
		base->nol = 0;
}

int					ft_point_flags_f_d_i(const char *format, va_list ap, int *i,
														t_pf_list *base)
{
	int	bol;

	if (((*format == 'l' || *format == 'L')
				&& *(format + 1) == 'f') || *format == 'f' || *format == 'F')
	{
		if (*format == 'l')
			base->ld = 1;
		else if (*format == 'L')
			base->d = 1;
		else
			base->f = 1;
		*i += ft_type_f(format, ap, base);
		bol = 1;
	}
	else if (*format == 'D' || *format == 'd' || *format == 'i')
	{
		ft_help_d_i(format, base);
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else
		bol = 0;
	return (bol);
}
