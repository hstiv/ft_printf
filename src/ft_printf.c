/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:34:43 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/28 02:43:06 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flag(t_pf_list *base, const char *format, va_list ap)
{
	int		i;
	int		j;

	j = 0;
	while (*format != 's' && *format != 'd' && *format != 'f' 
		&& *format != 'L' && *format != 'c' && *format != 'i' && *format != 'S'
		&& *format != 'C' && *format != 'b' && *format != 'e' && *format != 'g'
		&& *format != 'r' && *format != 'G' && *format != 'E' && *format != 'D'
		&& *format != 'x' && *format != 'X' && *format != 'o' && *format != 'u'
		&& *format != '\0' && *format != '%' && *format != 'p'
		&& *format != 'U' ) //&& *format != 'h' && *format != 'l' && *format != 'j' && *format != 'z'
	{
		i = ft_fill_flag(base, format, ap);
		if (i == -1)
			return (-1);
		else if (i == 0) // 
			return (j); //
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
		return (0);
	format += i;
	if (ft_point_flags_f_d_i(format, ap, &i, base))
		return (i);
	else if (ft_point_flags_x_o(format, ap, &i, base))
		return (i);
	else if (ft_point_flags_u(format, ap, &i, base))
		return (i);
	else if (*format == 's' || *format == 'c' || *format == 'C'
			|| *format == 'S' || *format == '%')
		i = ft_type_s(format, ap, i, base);
	else if (*format == 'b' || *format == 'e'
			|| (*format == 'L' && (*(format + 1) == 'e')) || *format == 'E')
		i = ft_type_b_e(format, ap, i, base);
	else if ((*format == 'L' || *(format + 1) == 'g')
			|| *format == 'r' || *format == 'g' || *format == 'G')
		i = ft_type_g(format, ap, i, base);
	else
		return (i)	; //-1
	return (i);
}

static int		ft_print(const char *format, t_pf_list *base)
{
	int		i;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')
		i++;
	write(1, format, i);
	base->len_return += i;
	return (i);
	// ft_putchar(*format);
	// base->len_return++;
	// return (1);
}
static void		ft_azbyka(t_pf_list *base)
{
	while (base->width-- > 1)
	{
		ft_putchar(' ');
		base->len_return += 1;
	}
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
		while (*format != '%' && *format != '\0')
			format += ft_print(format, base);
		if (*format == '%')
		{
			format++;
			len_format = ft_parse_flag(format, ap, base);
		//	printf("\nlen %d ... base_w %d", len_format, base->width);
			format += len_format;
			if (((*format >= 'a' && *format <= 'z') || (*format >='A' && *format <= 'Z')) && base->minus == 1 && base->width > 1)
			{
				ft_putchar(*format);
				ft_azbyka(base);
				format++;
				++base->len_return;
			}
			else if (((*format >= 'a' && *format <= 'z') || (*format >='A' && *format <= 'Z')) && base->width > 1)
				ft_azbyka(base);
			else
			{
				/* code */
			}
			
		//	format += len_format;
		}
		return_len += base->len_return;
		free(base);
	}
	return (return_len);
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
