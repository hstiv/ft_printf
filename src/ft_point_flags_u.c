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

// static void		ft_for_type_mod(const char *format, t_pf_list *base)
// {
// 	if (*format == 'l')
// 	{
// 		format++;
// 		if ((*format) == 'l')
// 			base->ld = 2;
// 		else
// 			base->ld = 1;
// 	}
// 	else if (*format == 'h')
// 	{
// 		format++;
// 		if ((*format) == 'h')
// 			base->d = 2;
// 		else
// 			base->d = 1;
// 	}
// 	else
// 		return ;
// }

int				ft_point_flags_u(const char *format, va_list ap, int *i,
														t_pf_list *base)
{
	int	bol;

	// if ((((*format == 'l' || *format == 'h' || *format == 'j') && (((*(format + 1) == 'u')
	// || (*(format + 2) == 'u')))) || (*format == 'u')))
	if (*format == 'u')
	{
		if (base->f != 100)
		{
				base->f = 10;
				base->k = 1;
		}
		else
		{
			base->k = 0;
		}
		
		base->plus = 0;
		
	//	ft_for_type_mod(format, base);
		// if (*format == 'j')
		// {	*i += 1;
		// base->d = 0;
		// base->ld = 0;
		// base->f = 100;
		// }
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else if (*format == 'U')
	{
	// else if ((((*format == 'l' || *format == 'h') && (((*(format + 1) == 'U')
	// || (*(format + 2) == 'U')))) || (*format == 'U')))

		base->plus = 0;
		base->f = 100;
	//	ft_for_type_mod(format, base);
		// if (base->d == 1 || base->ld == 1)
		// 	*i += 1;
		// if (base->d == 2 || base->ld == 2)
		// 	*i += 2;
		base->d = 0;
		base->ld = 2;
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else
		bol = 0;
	return (bol);
}
