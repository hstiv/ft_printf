/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_prnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:10:44 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/04 19:10:46 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flag(t_pf_list *base, const char *format, va_list ap)
{
	int		i;
	int		j;

	j = 0;
	while (*format != 's' && *format != 'd' && *format != 'f' && *format != 'F'
		&& *format != 'L' && *format != 'c' && *format != 'i' && *format != 'S'
		&& *format != 'C' && *format != 'b' && *format != 'e' && *format != 'g'
		&& *format != 'r' && *format != 'G' && *format != 'E' && *format != 'D'
		&& *format != 'x' && *format != 'X' && *format != 'o' && *format != 'u'
		&& *format != '\0' && *format != '%' && *format != 'p'
		&& *format != 'U')
	{
		i = ft_fill_flag(base, format, ap);
		if (i == -1)
			return (-1);
		else if (i == 0)
			return (j);
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
		return (i);
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
			format += len_format;
			format += ft_for_un_falid(format, base);
		}
		return_len += base->len_return;
		free(base);
	}
	return (return_len);
}
