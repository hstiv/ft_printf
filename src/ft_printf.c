/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:43 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/19 16:23:27 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flag(t_pf_list *base, const char *format, va_list ap)
{
	int		i;

	i = 0;
	while (*format != 's' && *format != 'd' && *format != 'f' && *format != 'l'
			&& *format != 'L' && *format != 'c' && *format != 'i' && *format != 'S'
			&& *format != 'C' && *format != 'b' && *format != 'e' && *format != 'g'
			&& *format != 'r' && *format != 'G' && *format != 'E' && *format != 'h'
			&& *format != 'x' && *format != 'X' && *format != 'o')
	{
		if (ft_pars_flag(base, format))
		{}
		else if (*format == '.')
		{
			format++;
			if (*format == '*')
				base->acc = va_arg(ap, int);
			else
			{
				base->acc = ft_atoi(format);
				format += ft_numlen(base->acc) - 1;
				i += ft_numlen(base->acc) - 1;
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
	if (ft_point_flags_f_d_i(format, ap, &i, base))
	{}
	if (ft_point_flags_x_X_o(format, ap, &i, base))
	{}
	else if (*format == 's' || *format == 'c' || *format == 'C' || *format == 'S')
		i = ft_type_s(format, ap, i, base);
	else if (*format == 'b' || *format == 'e'
		|| (*format == 'L' && (*(format + 1) == 'e')) || *format == 'E')
		i = ft_type_b_e(format, ap, i, base);
	else if ((*format == 'L' || *(format + 1) == 'g')
		|| *format == 'r' || *format == 'g' || *format == 'G')
		i = ft_type_g(format, ap, i, base);
	else
		return (i);
	// format += i;
	//	format++;
	return (i);
}

int				ft_parsing_prnt(const char *format, va_list ap) //USED
{
	int			len_format;
	t_pf_list	*base;
	int			return_len;

	return_len = 0;
	while (*format != '\0')
	{
		if (!(base = ft_create_pf_list()))
			return (-1);
		while(*format != '%' && *format != '\0')
		{
			ft_putchar(*format);
			format++;
			base->len_return++;
		}
		if (*format == '%')
		{
			format++;
			len_format = ft_parse_flag(format, ap, base);
		if (len_format == -1)
				return(-1);
			format += len_format;
		}
		return_len += base->len_return;
		free (base);
	}
	return(return_len);
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

