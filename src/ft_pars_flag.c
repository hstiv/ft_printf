/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:06:42 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/29 21:22:40 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_pars_flag(t_pf_list *base, const char *format)
{
	int		bol;

	bol = 1;
	if (*format == '#')
		base->hew = 1;
	else if (*format == '0')
		base->nol = 1;
	else if (*format == ' ')
		base->space = 1;
	else if (*format == '+')
		base->plus = 1;
	else if (*format == '-')
		base->minus = 1;
	else
		bol = 0;
	return (bol);
}

static void		ft_num_for_width(t_pf_list *base, va_list ap, int n,
													const char *format)
{
	if (n == 1)
	{
		base->width = va_arg(ap, int);
		base->wid_bool = 1;
	}
	else
	{
		base->width = ft_atoi(format);
		base->wid_bool = 1;
	}
}

static int		ft_pars_dot(t_pf_list *base, const char *format, va_list ap)
{
	int		i;

	i = 0;
	format++;
	if (*format == '*')
		base->acc = va_arg(ap, int);
	else if (*format >= '0' && '9' >= *format)
	{
		base->acc = ft_atoi(format);
		format += ft_numlen(base->acc) - 1;
		i += ft_numlen(base->acc) - 1;
		if (i < 0)
			return (-1);
	}
	else
	{
		base->acc = 0;
		--i;
	}
	base->acc_bool = 1;
	++i;
	return (i);
}

static int		ft_parse_mod(const char *format, t_pf_list *base)
{
	if (*format == 'l')
	{
		format++;
		base->ld = 1;
		if ((*format) == 'l')
			base->ld = 2;
		return (base->ld);
	}
	else if (*format == 'h')
	{
		format++;
		base->d = 1;
		if ((*format) == 'h')
			base->d = 2;
		return (base->d);
	}
	else if ((*format) == 'z' || (*format) == 'j')
	{
		if ((*format) == 'j')
			base->ld = 2;
		else
			base->f = 100;
		return (1);
	}
	return (0);
}

int				ft_fill_flag(t_pf_list *base, const char *format, va_list ap)
{
	int	i;

	i = 0;
	if (ft_pars_flag(base, format))
		ft_control_flag(base);
	else if (*format == '.')
		i += ft_pars_dot(base, format, ap);
	else if (*format == '*')
		ft_num_for_width(base, ap, 1, format);
	else if (*format >= '0' && *format <= '9')
	{
		ft_num_for_width(base, ap, 0, format);
		format += ft_numlen(base->width) - 1;
		i += ft_numlen(base->width) - 1;
	}
	else if (*format != 'h' || *format != 'l' || *format != 'j' ||
														*format != 'z')
		i += ft_parse_mod(format, base) - 1;
	else
		return (i);
	ft_control_flag(base);
	return (++i);
}
