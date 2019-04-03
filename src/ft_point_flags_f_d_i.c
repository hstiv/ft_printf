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

// static void		ft_for_type_d(const char *format, t_pf_list *base)
// {
// 	if (*format == 'l' || *format == 'j')
// 	{
// 		format++;
// 		if ((*format) == 'l' || (*format - 1) == 'j')
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

int				ft_point_flags_f_d_i(const char *format, va_list ap, int *i,
														t_pf_list *base)
{
	int	bol;

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
	else if (*format == 'D' || *format == 'd' || *format == 'i')
	{
	// else if ((((*format == 'l' || *format == 'h' || *format == 'j' || *format == 'z') && ((*(format + 1) == 'd')
	// || (*(format + 2) == 'd') || ((*(format + 1) == 'i') ||
	// (*(format + 2) == 'i')))) || (*format == 'd' || *format == 'i')))
	
	//	ft_for_type_d(format, base);
		if (*format == 'd')
			base->hew = 0;
		if (*format == 'D')
			base->ld = 2;
		if (base->f == 100)
		{
		//*i += 1;
		base->d = 0;
		base->ld = 0;
		base->k = 1;
		}
		if (base->acc)
			base->nol = 0;
		*i += ft_type_d(ap, base);
		bol = 1;
	}
	else
		bol = 0;
	return (bol);
}
