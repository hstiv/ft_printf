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

static int	ft_type_bc(const char *fowrmat, va_list ap, int i, t_pf_list *base)
{
	double	l;

	l = va_arg(ap, double);
	ft_putchar(l);
	i++;
	return (i);
}

static int	ft_type_c(const char *format, va_list ap, int i, t_pf_list *base)
{
	int		d;

	d = va_arg(ap, int);
	if (base->acc_bool == 0)
		ft_putchar(d);
	else
	{
		ft_putchar(d);
		while (base->width-- > 0)
			ft_putchar(' ');
	}
	format++;
	i++;
	return (i);
}

int			ft_type_s(const char *format, va_list ap, int i, t_pf_list *base)
{
	char	*str;

	if (*format == 'c')
		return (ft_type_c(format, ap, i, base));
	if (*format == 'C')
		return (ft_type_bc(format, ap, i, base));
	str = va_arg(ap, char *);
	i += ft_strlen(str);
	if (base->acc_bool == 0)
		ft_putstr(str);
	else
	{
		while (base->acc-- > 0 && *str != '\0')
		{
			ft_putchar(*str);
			str++;
			base->width--;
		}
		while (base->width-- > 0)
				ft_putchar(' ');
	}
	format++;
	return (++i);
}
