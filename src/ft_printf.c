/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:43 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/12 11:36:51 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_azbyka(t_pf_list *base)
{
	char s;

	s = ' ';
	if (base->nol == 1)
		s = '0';
	while (base->width-- > 1)
	{
		ft_putchar(s);
		base->len_return += 1;
	}
}

int				ft_for_un_falid(const char *format, t_pf_list *base)
{
	if (((*format >= 'a' && *format <= 'z') || (*format >= 'A'
		&& *format <= 'Z')) && base->minus == 1 && base->width > 1)
	{
		ft_putchar(*format);
		ft_azbyka(base);
		++base->len_return;
		return (1);
	}
	else if (((*format >= 'a' && *format <= 'z') || (*format >= 'A'
		&& *format <= 'Z')) && base->width > 1)
		ft_azbyka(base);
	return (0);
}

int				ft_printf(const char *format, ...)
{
	int			result;
	va_list		ap;

	va_start(ap, format);
	result = ft_parsing_prnt(format, ap);
	va_end(ap);
	return (result);
}
