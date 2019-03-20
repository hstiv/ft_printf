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

int				ft_point_flags(const char *format, va_list ap, int *i,
														t_pf_list *base)
{
	int	bol;

	bol = 0;
	if (((*format == 'l' || *format == 'L')
				&& *(format + 1) == 'f') || *format == 'f')
	{
		if (*format == 'l')
			base->d = 1;
		else if (*format == 'L')
			base->ld = 1;
		else
			base->f = 1;
		*i += ft_type_f(format, ap, base);
		bol = 1;
	}
	// if (((*format == 'l' || *format == 'h')
	// 			&& (*(format + 1) == 'd') || *(format + 1) == 'i'))
	// 				|| (*format == 'd' || *format == 'i'))
	// {
	// 	*format++;
	// 	if ((*format == 'l' || *format == 'h'))
	// }
	return(bol);
}
