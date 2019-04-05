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

static void		ft_hep_u(t_pf_list *base)
{
	base->plus = 0;
	base->f = 100;
	base->d = 0;
	base->ld = 2;
}

int				ft_point_flags_u(const char *format, va_list ap, int *i,
														t_pf_list *base)
{
	int	bol;

	if (*format == 'u')
	{
		if (base->f != 100)
		{
			base->f = 10;
			base->k = 1;
		}
		else
			base->k = 0;
		base->plus = 0;
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else if (*format == 'U')
	{
		ft_hep_u(base);
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else
		bol = 0;
	return (bol);
}
