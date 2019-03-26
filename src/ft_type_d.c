/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:19:19 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/19 15:49:02 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_base_min(t_pf_list *base, int diff,
					unsigned long long int num, int len_num)
{
	ft_magic_base(base, len_num, diff);
	if (base->neg == 1 && !base->f)
		ft_putchar('-');
	if (base->neg == 0 && base->space == 0 && base->plus == 1 && !base->f)
		ft_putchar('+');
	while (diff-- > 0)
		ft_putchar('0');
	if (base->f)
		ft_putstr(base->num_hh);
	else
		ft_putnbr_prntf(num);
	while (base->width-- > 0)
		ft_putchar(' ');
}

static void				ft_base_non_min(t_pf_list *base, int diff,
					unsigned long long int num, int len_num)
{
	ft_magic_base(base, len_num, diff);
	while (base->width-- > 0)
		ft_putchar(' ');
	if (base->neg == 1 && base->nol == 1 && !base->f)
		ft_putchar('-');
	if (base->neg == 0 && base->space == 0 && base->plus == 1 && !base->f)
		ft_putchar('+');
	if (base->neg == 1 && base->nol == 0 && !base->f)
		ft_putchar('-');
	while (diff-- > 0)
		ft_putchar('0');
	if (base->f)
		ft_putstr(base->num_hh);
	else
		ft_putnbr_prntf(num);
}

static void				ft_next_step(t_pf_list *base, int diff,
								long long int num, int len_num)
{
	if (base->minus)
	{
		if (base->neg)
			ft_base_min(base, diff, (unsigned long long int)num * (-1),
															len_num);
		else
			ft_base_min(base, diff, (unsigned long long int)num, len_num);
	}
	else
	{
		if (base->neg)
			ft_base_non_min(base, diff, (unsigned long long int)num * (-1),
															len_num);
		else
			ft_base_non_min(base, diff, (unsigned long long int)num, len_num);
	}
}

static char    *ft_itoa_unsigned(uintmax_t num, int base, t_pf_list *b)
{
    uintmax_t    value;
    long        i;
    char        *s;

    i = 0;
    value = num;
    while (value)
    {
        i++;
        value /= base;
    }
    s = ft_strnew(i);
    s[i] = 0;
    while (num)
    {
		if (b->f == 'A')
    		s[--i] = "0123456789ABCDEF"[num % base];
		else
			s[--i] = "0123456789abcdef"[num % base];
        num /= base;
    }
    return (s);
}

int						ft_type_d(va_list ap, t_pf_list *base)
{
	long long int		num;
	int					len_num;
	int					diff;

	diff = 0;
	num = ft_va_arg_for_d(ap, base);
	if (base->f)
	{
		base->num_hh = ft_itoa_unsigned(num, 16, base);
		len_num = ft_strlen(base->num_hh);
	}
	else
		len_num = ft_numlen_for_prf(num);
	if (num < 0 && !base->f)
		base->neg = 1;
	else
		base->neg = 0;
	if (base->acc > len_num)
		diff = base->acc - len_num;
	ft_next_step(base, diff, num, len_num);
	return (base->d + base->ld + 1);
}
