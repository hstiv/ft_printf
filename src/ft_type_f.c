/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 03:21:50 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/17 03:43:20 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include"ft_printf.h"

int				ft_type_f(const char *format, va_list ap, int i, t_pf_list *base)
{
	double		n;
	int			i;

	i = base->str_len;
	n = va_arg(ap, double);
	while (base->width != 0)
	{
		ft_putchar(' ');
		base_width--;
		i++;
	}
	if (base->acc == 0)
	{
		i += ft_strlen(ft_ftoa(n, 6));
		ft_putstr(ft_ftoa(n, 6));
	}
	else if (base->acc != 0)
	{
		i += ft_strlen(ft_ftoa(n, base->acc));
		ft_putstr(ft_ftoa(n, base->acc));
	}
	format++;
	return (i);	
}
