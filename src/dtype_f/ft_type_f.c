/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 03:21:50 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/17 07:44:20 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int		type_mid(t_pf_list *base, t_typef *lol, double n)
{
	char		*s;

	if (lol->f == 1 || lol->d == 1)
	{
		s = ft_ftoa(n, 6);
		base->len += ft_strlen(s);
		ft_putstr(s);
		free(s);
		free(lol);
		return (base->len);
	}
	s = ft_ftoa(n, 11);
	base->len += ft_strlen(s);
	ft_putstr(s);
	free(s);
	free(lol);
	return (base->len);
}

int				ft_type_f(const char *format, va_list ap, t_pf_list *base, t_typef *lol)
{
	double		n;
	char		*s;

	n = va_arg(ap, double);
	while (base->width != 0)
	{
		ft_putchar(' ');
		base->width--;
		base->len++;
	}
	if (base->acc == 0)
		return (type_mid(base, lol, n));
	else if (base->acc != 0)
	{
			base->len += ft_strlen(ft_ftoa(n, base->acc));
			ft_putstr(s = ft_ftoa(n, base->acc));
	}
	free(s);
	format++;
	return (base->len);	
}
