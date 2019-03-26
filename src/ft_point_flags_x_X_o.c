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
		if ((*format + 1) == 'l')
			base->ld = 2;
		else
			base->ld = 1;
	}
	else if (*format == 'h')
	{
		if ((*format + 1) == 'h')
			base->d = 2;
		else
			base->d = 1;
	}
	else
	{}

}

int				ft_point_flags_x_X_o(const char *format, va_list ap, int *i,
														t_pf_list *base)
{
	int	bol;

	if ((((*format == 'l' || *format == 'h') && (((*(format + 1) == 'X')
	|| (*(format + 2) == 'X')))) || (*format == 'X')))
	{
		base->f = 65;
		ft_for_type_mod(format, base);
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else if ((((*format == 'l' || *format == 'h') && ((*(format + 1) == 'x')
	|| (*(format + 2) == 'x')))) || (*format == 'x'))
	{
		base->f = 97;
		ft_for_type_mod(format, base);
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else if ((((*format == 'l' || *format == 'h') && ((*(format + 1) == 'o')
	|| (*(format + 2) == 'o')))) || (*format == 'o'))
	{
		base->f = 8;
		ft_for_type_mod(format, base);
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else
		bol = 0;
	return (bol);
}
