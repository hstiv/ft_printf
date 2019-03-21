/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:04:56 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/17 07:30:10 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_type_s_accuracy(t_pf_list *base)
{
	if (base->minus == 1)
		base->acc = base->width;
		while (base->acc > 0 && base->nol && !base->minus)
		{
				ft_putchar('0');
				base->len_return++;
				base->acc--;
		}
		while (base->acc > 0 && (!base->nol || base->minus))
		{
				ft_putchar(' ');
				base->len_return++;
				base->acc--;
		}
}

static void	ft_type_s_precision(t_pf_list *base)
{
	int		i;

	i = base->width - base->acc;
	while (i > 0 && !base->nol)
	{
		ft_putchar(' ');
		i--;
		base->len_return++;
	}
	while (i > 0 && base->nol)
	{
		ft_putchar('0');
		base->len_return++;
		i--;
	}
}

static int	ft_type_bc(const char *fowrmat, va_list ap, int i, t_pf_list *base)
{
	double	l;

	l = va_arg(ap, double);
	ft_putchar(l);
	base->len_return++;
	i++;
	return (i);
}

static int	ft_type_c(const char *format, va_list ap, int i, t_pf_list *base)
{
	int		d;

	d = va_arg(ap, int);
	if (base->width || base->minus != 0 || !base->acc)
	{
		base->acc = 0;
		base->width -= 1;
	}
	if (base->acc_bool == 0)
		ft_putchar(d);
	else
	{
		if ((base->width - base->acc) > 0 && !base->minus)
			ft_type_s_precision(base);
		ft_putchar(d);
		if (base->acc > 0)
			base->acc = 0;
		ft_type_s_accuracy(base);
	}
	base->len_return++;
	format++;
	return (++i);
}

int			ft_type_s(const char *format, va_list ap, int i, t_pf_list *base)
{
	char	*str;

	if (*format == 'c')
		return (ft_type_c(format, ap, i, base));
	if (*format == 'C')
		return (ft_type_bc(format, ap, i, base));
	str = va_arg(ap, char *);
	if (base->acc_bool == 0)
	{
		ft_putstr(str);
		base->len_return += ft_strlen(str);
	}
	else
	{
		if ((base->width - base->acc) > 0 && !base->minus)
			ft_type_s_precision(base);
		while (base->acc-- > 0 && *str != '\0')
		{
			ft_putchar(*str);
			str++;
			base->len_return++;
			base->width--;
		}
		ft_type_s_accuracy(base);
	}
	format++;
	return (++i);
}
