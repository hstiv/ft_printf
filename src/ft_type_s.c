/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:04:56 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/24 12:46:47 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wctype.h>

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

static int	ft_type_c(const char *format, va_list ap, int i, t_pf_list *base)
{
	char	d;

	d = va_arg(ap, int);
	if (base->width || base->minus != 0 || !base->acc)
	{
		base->acc = 0;
		base->width -= 1;
	}
	if (base->width > 0 && !base->minus)
		ft_type_s_precision(base);
	write(1, &d, 1);
	if (base->acc > 0)
		base->acc = 0;
	ft_type_s_accuracy(base);
	base->len_return++;
	format++;
	return (++i);
}

int			ft_type_s(const char *format, va_list ap, int i, t_pf_list *base)
{
	char	*str;

	 if (*format == 'c' || *format == 'C')
	 	return (ft_type_c(format, ap, i, base));
	str = va_arg(ap, char *);
	if (base->acc_bool == 0)
	{
		write(1, str, ft_strlen(str));
		base->len_return += ft_strlen(str);
	}
	else
	{
		if (base->acc > (int)ft_strlen(str))
			base->acc = ft_strlen(str);
		if ((base->width - base->acc) > 0 && !base->minus)
			ft_type_s_precision(base);
		if (base->acc > 0 && *str != '\0')
		{
			write(1, str, base->acc);
			base->len_return += base->acc;
			base->width -= base->acc;
			base->acc -= base->acc;
		}
		ft_type_s_accuracy(base);
	}
	format++;
	return (++i);
}
