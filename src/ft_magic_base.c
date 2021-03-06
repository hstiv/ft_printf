/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:09:32 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/12 11:56:35 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					ft_help_base(t_pf_list *base, int len_num, int diff)
{
	base->width = 0;
	if (base->neg == 1 && diff > 0)
		base->len_return += len_num + diff + 1;
	else if (base->neg == 0 && diff > 0 && base->plus == 0)
		base->len_return += len_num + diff;
	else if (base->neg)
		base->len_return += (len_num + base->neg);
	else if (base->neg == 0 && base->plus == 1)
		base->len_return += len_num + diff + base->plus;
	else
		base->len_return += len_num;
}

void					ft_next_step(t_pf_list *base, int len_num, int diff)
{
	base->wid_bool = base->width;
	if (base->width > base->acc && base->width > len_num)
	{
		if (base->width - 1 > base->acc && base->neg == 1)
		{
			base->len_return += base->width;
			base->width -= (len_num + diff + 1);
		}
		else if (base->neg == 0 && base->space == 0 && base->plus == 1)
		{
			base->len_return += base->width;
			base->width -= (len_num + diff + 1);
		}
		else
		{
			base->len_return += base->width;
			base->width -= (len_num + diff + base->neg);
		}
	}
	else
	{
		ft_help_base(base, len_num, diff);
	}
}

void					ft_put_space(t_pf_list *base, int len_num)
{
	if (base->minus == 1 && base->space == 1
				&& (base->acc > len_num && base->acc > base->wid_bool))
	{
		ft_putchar(' ');
		base->len_return += 1;
	}
	else if (base->minus == 1 && base->space == 1 && (base->acc > len_num
					|| (!base->acc_bool && base->wid_bool > len_num)))
	{
		ft_putchar(' ');
		base->width--;
	}
}

void					ft_magic_base(t_pf_list *base, int diff,
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
