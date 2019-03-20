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

static void		ft_magic_base(t_pf_list *base)
{
	if (base->width > base->acc)
	{
		if (base->width - 1 > base->acc && base->neg == 1)
		{
			base->len_return += base->width;
			base->width -= base->acc + 1;
		}
		else if (base->neg == 0 && base->space == 0 && base->plus == 1)
		{
			base->len_return += base->width;
			base->width -= base->acc + 1;
		}
		else
		{
			base->len_return += base->width;
			base->width -= base->acc;
		}
	}
}

static void		ft_base_min(t_pf_list *base, int len_num, int diff, int num)
{
	ft_magic_base(base);
	if (base->neg == 1)
		ft_putchar('-');
	if (base->neg == 0 && base->space == 0 && base->plus == 1)
		ft_putchar('+');
	while (diff-- > 0)
		ft_putchar('0');
	ft_putnbr_prntf(num);
	while (base->width-- > 0)
		ft_putchar(' ');
}

static void		ft_base_non_min(t_pf_list *base, int len_num, int diff, int num)
{
	ft_magic_base(base);
	while (base->width-- > 0)
		ft_putchar(' ');
	if (base->neg == 1 && base->nol == 1)
		ft_putchar('-');
	if (base->neg == 0 && base->space == 0 && base->plus == 1)
		ft_putchar('+');
	if (base->neg == 1 && base->nol == 0)
		ft_putchar('-');
	while (diff-- > 0)
		ft_putchar('0');
	ft_putnbr_prntf(num);
}

int				ft_type_d(const char *format, va_list ap, int i,
													t_pf_list *base)
{
	int		num;
	int		len_num;
	int		diff;

	if (base->d == 1)
		num = va_arg(ap,long int);
	else if (base->ld == 1)
		num = va_arg(ap,long long int);
	else if (base->f == 1)
		num = va_arg(ap, char);
	else
		num = va_arg(ap, int);
	len_num = ft_numlen(num);
	if (num < 0)
		base->neg = 1;
	if (base->acc > len_num)
		diff = base->acc - len_num;
	if (base->minus)
		ft_base_min(base, len_num, diff, num);
	else
		ft_base_non_min(base, len_num, diff, num);
	i++;
	return (i);
}
