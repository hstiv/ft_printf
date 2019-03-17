/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointed_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 04:50:23 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/17 06:21:49 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				ft_pointed_flags(const char *format, va_list ap, int i, t_pf_list *base)
{
	t_typef		*lol;

	if ((*format == 'l' || *format == 'L') && *(format + 1) == 'f')
	{
		lol = ft_creat_flst();
		if (*(format + 1) == 'l')
			lol->d = 1;
		else if (*format == 'L')
			lol->ld = 1;
		else
			lol->f = 1;
		return(ft_type_f(format, ap, i, base, lol));
	}
}
