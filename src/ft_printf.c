/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:43 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/27 21:20:48 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static void		ft_num_for_width(t_pf_list *base, va_list ap, int n,
													const char *format)
{
	if (n == 1)
	{
		base->width = va_arg(ap, int);
		base->wid_bool = 1;
	}
	else
	{
		base->width = ft_atoi(format);
		base->wid_bool = 1;
	}
}

static int		ft_fill_flag(t_pf_list *base, const char *format, va_list ap)
{
	int	i;
	
	i = 0;
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
		ft_num_for_width(base, ap, 1, format);
	else if (*format >= '0' && *format <= '9')
	{
		ft_num_for_width(base, ap, 0, format);
		format += ft_numlen(base->width) - 1;
		i += ft_numlen(base->acc) - 1;
	}
	else
		return (-1);
	i++;
	return (i);
}

static int		ft_flag(t_pf_list *base, const char *format, va_list ap)
{
	int		i;
	int		j;

	j = 0;
	while (*format != 's' && *format != 'd' && *format != 'f' && *format != 'l'
			&& *format != 'L' && *format != 'c' && *format != 'i' && *format != 'S'
			&& *format != 'C' && *format != 'b' && *format != 'e' && *format != 'g'
			&& *format != 'r' && *format != 'G' && *format != 'E' && *format != 'h'
			&& *format != 'x' && *format != 'X' && *format != 'o' && *format != 'u'
			&& *format != '\0' && *format != '%')
	{
		i = ft_fill_flag(base, format, ap);
		j += i;
		format += i;
	}
	return (j);
}

static int		ft_parse_flag(const char *format, va_list ap, t_pf_list *base)
{
	int			i;

	i = ft_flag(base, format, ap);
	if (i == -1)
		return (-1);
	format += i;
	if (ft_point_flags_f_d_i(format, ap, &i, base))
	{}
	else if (ft_point_flags_x_X_o(format, ap, &i, base))
	{}
	else if (ft_point_flags_u(format, ap, &i, base))
	{}
	else if (*format == 's' || *format == 'c' || *format == 'C' || *format == 'S' || *format == '%') // добавить печать %
		i = ft_type_s(format, ap, i, base);
	else if (*format == 'b' || *format == 'e'
		|| (*format == 'L' && (*(format + 1) == 'e')) || *format == 'E')
		i = ft_type_b_e(format, ap, i, base);
	else if ((*format == 'L' || *(format + 1) == 'g')
		|| *format == 'r' || *format == 'g' || *format == 'G')
		i = ft_type_g(format, ap, i, base);
	else
		return (-1);
	format++; //deleted?!
	return (i);
}

static int		ft_print(const char *format, t_pf_list *base)
{
	ft_putchar(*format);
	base->len_return++;
	return (1);
}

int				ft_parsing_prnt(const char *format, va_list ap)
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
			format += ft_print(format, base);
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

int				ft_printf(const char *format, ...)
{
	int			result;
	va_list		ap;

	va_start(ap, format);
	result = ft_parsing_prnt(format, ap);
	va_end(ap);
	return (result);
}

