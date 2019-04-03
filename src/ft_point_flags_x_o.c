/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point_flags_x_o.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 04:50:23 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/19 16:18:45 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int		ft_fun_for_help(va_list ap, int i, t_pf_list *base)
{
	i += ft_type_d(ap, base);
	return (i);
}

static void		ft_put_flag(t_pf_list *base)
{
	base->ld = 2;
	base->hew = 1;
	base->temp = 1;
}

int				ft_point_flags_x_o(const char *format, va_list ap, int *i,
														t_pf_list *base)
{
	int	bol;

	bol = 1;
	if (*format == 'X')
	{
		// base->f = 65;
		// base->k = 1;
		if (base->f != 100)
		{
			base->f = 65;
			base->k = 1;
		}
		else
		{
			base->f = 65;
			base->k = 2;
		}
		base->plus = 0;
		*i = ft_fun_for_help(ap, *i, base);
	}
	else if (*format == 'x' || *format == 'p')
	{
		if (*format == 'p')
			ft_put_flag(base);
	//	base->f = 97;
		if (base->f != 100)
		{
			base->f = 97;
			base->k = 1;
		}
		else
		{
			base->f = 97;
			base->k = 2;
		}
		base->plus = 0;
		*i = ft_fun_for_help(ap, *i, base);
	}
	else if (*format == 'o' || *format == 'O')
	{
		if (base->f != 100)
		{
			base->f = 8;
			base->k = 1;
		}
		else
		{
			base->f = 8;
			base->k = 2;
		}
		base->plus = 0;
		//base->f = 8;
		if (*format == 'O')
			base->ld = 2;
	//	base->k = 1;
		*i = ft_fun_for_help(ap, *i, base);
	}
	else
		bol = 0;
	return (bol);
}
