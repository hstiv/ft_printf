/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:04:56 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/28 00:05:04 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wctype.h>

static void	ft_type_s_accuracy(t_pf_list *base)
{
	if (base->minus && base->wid_bool && base->temp && base->acc_bool)
		base->acc = base->width;
	else if (base->minus && base->width && base->temp == 1)
		base->acc = base->width - base->acc;
	if (base->temp == 1 && !base->minus)
		base->acc = 0;
	if (base->acc && base->nol && base->width == -20)
		base->acc--;
	while (base->acc > 0 && (!base->temp || base->wid_bool))
	{
		if (base->nol)
			ft_putchar('0');
		else
			ft_putchar(' ');
		base->len_return++;
		base->acc--;
	}
}

static void	ft_type_s_precision(t_pf_list *base)
{
	int		i;

	i = base->width - base->acc;
	while (i-- > 0)
	{
		if (base->nol)
			ft_putchar('0');
		else
			ft_putchar(' ');
		base->len_return++;
	}
	base->width = 0;
}

static int	ft_type_c(const char *format, va_list ap, int i, t_pf_list *base)
{
	unsigned char	d;

	if (*format != '%')
		d = va_arg(ap, int);
	else
		d = '%';
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
	if (base->minus && base->width)
		base->acc = base->width - base->acc;
	ft_type_s_accuracy(base);
	base->len_return++;
	format++;
	return (++i);
}

static void	type_s_helper(char *str, t_pf_list *base)
{
	if (str && !base->acc && !base->acc_bool)
		base->acc = ft_strlen(str);
	else if (str == NULL)
		base->acc = 6;
	else if (base->acc && *str == '\0' && !base->minus)
		base->acc = 0;
	(str == 0) ? (base->width = -20) : 0;
	if ((base->width - base->acc) > 0 && !base->minus)
		ft_type_s_precision(base);
	if (base->acc > 0)
	{
		if (str != NULL && *str != '\0')
		{
			write(1, str, base->acc);
			base->len_return += base->acc;
			base->acc = base->width - base->acc;
		}
		else if (str == NULL && !base->nol && str != 0)
		{
			write(1, "(null)", 6);
			base->len_return += 6;
		}
	}
	(str != NULL && *str == '\0') ? (base->temp = 1) : 0;
	ft_type_s_accuracy(base);
}

int			ft_type_s(const char *format, va_list ap, int i, t_pf_list *base)
{
	char	*str;

	if (*format == 'c' || *format == 'C' || *format == '%')
		return (ft_type_c(format, ap, i, base));
	str = va_arg(ap, char *);
	if (base->acc_bool && str != NULL && base->acc > (int)ft_strlen(str))
		base->acc = ft_strlen(str);
	(str == 0 && base->width && !base->acc) ? (base->wid_bool = 0) : 0;
	if (base->acc_bool == 0 && !base->minus && base->wid_bool == 0)
	{
		if (str != NULL)
		{
			write(1, str, ft_strlen(str));
			base->len_return += ft_strlen(str);
		}
		else if (str == NULL)
		{
			write(1, "(null)", 6);
			base->len_return += 6;
		}
	}
	else
		type_s_helper(str, base);
	format++;
	return (++i);
}
