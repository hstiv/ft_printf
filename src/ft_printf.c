/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:43 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/18 18:54:46 by hstiv            ###   ########.fr       */
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
		if (ft_pars_flag(base, format) != 0)
		{
		//	printf("\nprs_flag\n");
		}
		if (*format == '.')
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

static int		ft_parse_flag(const char *format, va_list ap, t_pf_list *base)
{
	int			i;

	i = ft_flag(base, format, ap);
	format += i;
	if (i < ft_point_flags(format, ap, i, base))
		i = ft_point_flags(format, ap, i, base);
	else if (*format == 's' || *format == 'c' || *format == 'C')
		i = ft_type_s(format, ap, i, base);
	else if (*format == 'd')
		i = ft_type_d(format, ap, i, base);
	else
		return (i);
		//printf("CHECK! 7 \n"); // PRINTF
	free(base);
	format++;
	return (i);
}

int				ft_parsing_prnt(const char *format, va_list ap) //USED
{
	int			len_format;
	t_pf_list	*base;
	
	if (!(base = ft_create_pf_list()))
		return (-1);
	while (*format != '\0')
	{
		while(*format != '%' && *format != '\0')
		{
			ft_putchar(*format);
			format++;
			base->len++;
		}
		if (*format == '%')
		{
			format++;
			len_format = ft_parse_flag(format, ap, base);
			if (len_format == -1)
				return(-1);
			format += len_format;
		}
	}
	return(base->len);
}

int				ft_printf(const char *format, ...) // USED
{
	int			result;
	va_list		ap;

	va_start(ap, format);
	result = ft_parsing_prnt(format, ap);
	va_end(ap);
	return (result);
}

