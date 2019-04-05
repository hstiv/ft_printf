/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:44:50 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/04 18:44:52 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_for_hew(t_pf_list *base, unsigned long long int num)
{
	if ((base->hew == 1 && base->f == 97 && num != 0) || base->temp == 1)
	{
		ft_putstr("0x");
		base->hew = 0;
	}
	if (base->hew == 1 && base->f == 65 && num != 0)
	{
		ft_putstr("0X");
		base->hew = 0;
	}
	if (base->hew == 1 && base->f == 8 && num != 0)
	{
		ft_putstr("0");
		base->hew = 0;
	}
}

static void			ft_hep_magi(t_pf_list *base,
					unsigned long long int num)
{
	if ((num == 0) && base->acc == 0 && base->acc_bool == 1 && !(base->f == 8
															&& base->hew == 1))
	{
		if (base->wid_bool == 1)
			ft_putchar(' ');
		else
			base->len_return -= 1;
	}
	else if (base->f)
	{
		ft_putstr(base->num_hh);
		free(base->num_hh);
	}
	else
		ft_putnbr_prntf(num);
}

void				ft_magi(t_pf_list *base,
					unsigned long long int num, int diff)
{
	while (base->nol == 0 && base->width-- > 0)
		ft_putchar(' ');
	if (base->neg == 1 && base->nol == 1 && !base->f)
		ft_putchar('-');
	if (base->neg == 0 && base->space == 0 && base->plus == 1 && !base->f)
		ft_putchar('+');
	if (base->neg == 1 && base->nol == 0 && !base->f)
		ft_putchar('-');
	ft_for_hew(base, num);
	while (base->nol == 1 && base->acc_bool && base->width-- > 0)
		ft_putchar(' ');
	while (base->nol == 1 && base->width-- > 0)
		ft_putchar('0');
	while (diff-- > 0)
		ft_putchar('0');
	ft_hep_magi(base, num);
}
