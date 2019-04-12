/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_min_nonmin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:18:04 by hstiv             #+#    #+#             */
/*   Updated: 2019/04/12 12:18:08 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			base_min2(t_pf_list *base, unsigned long long int num)
{
	if ((num == 0) && base->acc == 0 && base->acc_bool == 1
					&& !(base->f == 8 && base->hew == 1))
	{
		if (base->width > 0)
			base->width++;
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
	while (base->width-- > 0)
		ft_putchar(' ');
}

void				ft_base_min(t_pf_list *base, int diff,
					unsigned long long int num, int len_num)
{
	ft_next_step(base, len_num, diff);
	(base->neg == 1) ? ft_put_space(base, len_num) : 0;
	(base->neg == 1 && !base->f) ? (ft_putchar('-')) : 0;
	(base->neg == 0 && base->space == 0
		&& base->plus == 1 && !base->f) ? ft_putchar('+') : 0;
	ft_for_hew(base, num);
	if (base->neg == 0)
		ft_put_space(base, len_num);
	while (diff-- > 0)
		ft_putchar('0');
	base_min2(base, num);
}

static void			nonmin(t_pf_list *base, int *len_num)
{
	ft_putchar(' ');
	base->space = 0;
	if (base->acc_bool == 0 && (base->width >= *len_num + 1))
		--base->width;
	else
		base->len_return++;
}

void				ft_base_non_min(t_pf_list *base, int diff,
					unsigned long long int num, int len_num)
{
	ft_next_step(base, len_num, diff);
	if ((base->nol == 0 && base->wid_bool > 0 &&
	base->space == 1 && base->neg == 0 &&
	((base->wid_bool && base->acc_bool && (base->k == 0)) ||
	(base->acc_bool == 0 && (base->wid_bool <= len_num))) && num != 0 &&
	(base->wid_bool <= base->acc || ((base->wid_bool >= base->acc)
	&& (base->wid_bool <= len_num && base->acc_bool)))))
	{
		ft_putchar(' ');
		base->space = 0;
		if ((base->wid_bool <= diff + 1) || (base->wid_bool <= len_num + 1))
			base->len_return++;
	}
	else if (base->space == 1 && base->neg == 0 &&
	(((base->wid_bool <= diff + 1) && (base->acc_bool == 1)) ||
	(base->acc_bool == 0 && (base->wid_bool <= len_num)) ||
	(base->wid_bool <= base->acc && base->acc_bool) ||
	(!base->acc_bool && base->nol == 1))
	&& !base->f)
		nonmin(base, &len_num);
	ft_magi(base, num, diff);
}
