/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 04:50:23 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/19 16:18:45 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void		ft_for_type_mod(const char *format, t_pf_list *base)
{
	if (*format == 'l')
	{
		format++;
		if ((*format) == 'l')
			base->ld = 2;
		else
			base->ld = 1;
	}
	else if (*format == 'h')
	{
		format++;
		if ((*format) == 'h')
			base->d = 2;
		else
			base->d = 1;
	}
	else
	{}

}

int				ft_point_flags_u(const char *format, va_list ap, int *i,
														t_pf_list *base)
{
	int	bol;

	if ((((*format == 'l' || *format == 'h') && (((*(format + 1) == 'u')
	|| (*(format + 2) == 'u')))) || (*format == 'u')))
	{
		base->f = 10;
		ft_for_type_mod(format, base);
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else
		bol = 0;
	return (bol);
}
