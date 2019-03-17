/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:04:56 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/17 03:23:52 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_s(const char *format, va_list ap, int i, t_pf_list *base)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	if (base->acc_bool == 0)
		ft_putstr(str);
	else
	{
		while (base->acc > 0 && *str != '\0')
		{
			ft_putchar(*str);
			str++;
			base->acc -= 1;
			base->width -= 1;
		}
		while (base->width > 0)
			{
				ft_putchar(' ');
				base->width -= 1;
			}
	}
	format++;
	return (++i);
}
