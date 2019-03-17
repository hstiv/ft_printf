/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:43 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/17 07:41:51 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flag(t_pf_list *base, const char *format, va_list ap)
{
	int		i;

	i = 0;
	while (*format != 's' && *format != 'd' && *format != 'f' && *format != 'l'
			&& *format != 'L' && *format != 'c')
	{
		if (ft_pars_flag(base, format))
		{
			//format++;
		//	printf("\nprs_flag\n");
		}
		else if (*format == '.')
		{
			format++;
			if (*format == '*')
				base->acc = va_arg(ap, int);
			else
			{
				base->acc = ft_atoi(format);
				format += ft_numlen(base->acc) - 1;
				i += ft_numlen(base->acc);
			}
			base->acc_bool = 1;
			i++;
		}
		else if (*format == '*')
		{
			base->width = va_arg(ap, int);
			base->wid_bool = 1;
		}
		else if (*format >= '0' && *format <= '9')
		{
			base->width = ft_atoi(format);
			base->wid_bool = 1;
			format += ft_numlen(base->width) - 1;
			i += ft_numlen(base->acc) - 1;
		}
		else
			return (-1); // hz
		i++;
		format++;
	}
	return (i);
}

static int		ft_parse_flag(const char *format, va_list ap)
{
	t_pf_list	*base;
	int			i;

	base = ft_create_pf_list();
	i = ft_flag(base, format, ap);
	format += i;
	if (i < ft_point_flags(format, ap, i, base))
		return (ft_point_flags(format, ap, i, base));
	if (*format == 's' || *format == 'c' || *format == 'C')
	{
		i = ft_type_s(format, ap, i, base);
		format++;
	}
	else if (*format == 'd')
	{
		i = ft_type_d(format, ap, i, base);
		format++;
	}
	else
		return (i);
		//printf("CHECK! 7 \n"); // PRINTF
	free(base);
	return (i);
}

int				ft_printf(const char *format, ...) // USED 
{
	va_list ap;
	int		i;
	int		len;
	
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			ft_putchar(*format);
			format++;
			i++;
		}
		if (*format == '%') 
		{
			format++;
			// if (*format == '%') // это тип переделать
			// {
			// 	ft_putchar('%');
			// 	format++;
			// }
			// else
		//	printf("CHECK! %%++ \n"); // PRINTF
			len = ft_parse_flag(format, ap);
			if (len == -1)
				return(len);
			format += len;
		}
	}
	va_end(ap);
	return (0);
}
