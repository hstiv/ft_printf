/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:41:08 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/13 18:41:09 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_flag(t_pf_list *base, const char *format, va_list ap)
{
	int		i;

	i = 0;
	while (*format != 's' && *format != 'd' && *format != '%')
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
	//	printf("\n%d - width\n", base->width);
	//	printf("\n%d - acc\n", base->acc);
		i++;
		format++;
	}
	return (i);
}

int			ft_parse_flag(const char *format, va_list ap, t_pf_list *base)
{
	int		i;


	i = ft_flag(base, format, ap);
	format += i;
	if (*format == 's')
	{
		i = ft_type_s(format, ap, i, base);
		format++;
	}
	else if (*format == 'd')
	{
		i = ft_type_d(format, ap, i, base);
		format++;
	}
	else if (*format == '%') // обработать
		{

			format++;
		}
	else
		return (-1);
	free(base);
	return (i);

}








int    		 ft_parsing_prnt(const char *format, va_list ap, t_pf_list *base)
{
    int		len_format;

    while (*format != '\0')
	    {
	    	while (*format != '%' && *format != '\0')
	    	{
	    		ft_putchar(*format);
	    		format++;
	    		base->len++;
	    	}
	    	if (*format == '%') 
	    	{
	    		format++;
                len_format = ft_parse_flag(format, ap, base); // возвращает колличество иттерируемых символов по format
                if (len_format == -1)
				    return(len_format);
                format += len_format;
	    	}
		}
    return(base->len);
}