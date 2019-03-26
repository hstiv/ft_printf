/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:09:32 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/26 13:09:35 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_help_base(t_pf_list *base, int len_num, int diff)
{
	base->width = 0;
	
	if (base->neg == 1 && diff > 0)
		base->len_return += len_num + diff + 1;
	else if (base->neg == 0 && diff > 0)
		base->len_return += len_num + diff;
	else
		base->len_return += (len_num + base->neg);
	// else
	// 	base->len_return += base->width + diff;
}

void				ft_magic_base(t_pf_list *base, int len_num, int diff)
{
	if (base->width > base->acc && base->width > len_num)
	{
		if (base->width - 1 > base->acc && base->neg == 1)
		{
			base->len_return += base->width;
			base->width -= len_num + diff + 1;
		}
		else if (base->neg == 0 && base->space == 0 && base->plus == 1)
		{
			base->len_return += base->width + base->plus;
			base->width -= base->acc + 1;
		}
		else
		{
			base->len_return += base->width;
			base->width -= (len_num + diff);
		}
		// else
		// 	base->len_return += base->width + diff;	
	}
	else
	{
		ft_help_base(base, len_num, diff);
	}
}
