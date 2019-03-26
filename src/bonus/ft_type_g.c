/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_g.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 07:46:32 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 07:46:34 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_hex(long long int nb, t_pf_list *base)
{
	int i;

	i = 0;
	//printf("\ng_e - %d\n", base->g_e);
	if (nb >= 16)
		print_hex(nb / 16, base);
	if ((nb % 16) < 10)
	{
		ft_putchar((nb % 16) + '0');
		base->len_return++;
		i++;
	}
	else
	{
		ft_putchar((nb % 16) - 10 + base->f);
		base->len_return++;
		i++;
	}
	return (i);
}

void					ft_type_p(va_list ap, t_pf_list *base)
{
	long unsigned int	p;

	p = va_arg(ap, long unsigned int);
	ft_putstr("0x10");
	base->len_return += 4;
	print_hex((long long int)p, base);
}

static void				type_g_maker(t_pf_list *b, long double nb, int i)
{
	if (i >= 6 && !b->acc_bool && !b->wid_bool)
    {
		if (!b->acc_bool)
		{
			b->acc = 5;
			b->acc_bool = 1;
		}
		ft_type_e(nb, b);
    }
    else
	{
		b->acc = 5 - i;
		b->acc_bool = 1;
		pf_ftoa(nb, b);
	}
}

static void				ft_tttype_g(long double nb, t_pf_list *base)
{
	long double			n;
    int             	i;

	n = nb;
    i = 0;
	if (n < 0)
		n *= -1;
	while ((long long int)n > 9 && ++i)
		n = n / 10;
	if (base->wid_bool && base->acc_bool)
	{
		if (base->width < base->acc)
			{
				base->acc = 9;
				pf_ftoa(nb, base);
				return ;
			}
	}
	type_g_maker(base, nb, i);
}

int						ft_type_g(const char *format, va_list ap, int i, t_pf_list *base)
{
    if (*format == 'g' || (*format == 'L' && *(format + 1) == 'g') || *format == 'G')
	{
		if (*format == 'L')
		{
			i += 2;
			ft_tttype_g(va_arg(ap, long double), base);
		}
		else
		{
			i++;
			ft_tttype_g(va_arg(ap, double), base);
		}
	}
	else if (*format == 'p')
	{
		ft_type_p(ap, base);
		i++;
	}
    format++;
    return (i);
}