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

static void		ft_hep_for_x_p_o(t_pf_list *base, int i)
{
	if (base->f != 100)
	{
		base->f = i;
		base->k = 1;
	}
	else
	{
		base->f = i;
		base->k = 2;
	}
	base->plus = 0;
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
		ft_hep_for_x_p_o(base, 65);
		*i = ft_fun_for_help(ap, *i, base);
	}
	else if (*format == 'x' || *format == 'p')
	{
		if (*format == 'p')
			ft_put_flag(base);
		ft_hep_for_x_p_o(base, 97);
		*i = ft_fun_for_help(ap, *i, base);
	}
	else if (*format == 'o' || *format == 'O')
	{
		ft_hep_for_x_p_o(base, 8);
		if (*format == 'O')
			base->ld = 2;
		*i = ft_fun_for_help(ap, *i, base);
	}
	else
		bol = 0;
	return (bol);
}
