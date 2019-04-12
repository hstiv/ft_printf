/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:22:35 by hharrold          #+#    #+#             */
/*   Updated: 2019/04/12 11:37:48 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_for_len_num(t_pf_list *base)
{
	if (((base->f == 97) && base->hew == 1)
					&& base->acc_bool == 1 && !base->temp)
	{
		base->len_return += 2;
		return (0);
	}
	if (((base->f == 65 || base->f == 97) && base->hew == 1) || base->temp == 1)
		return (2);
	if ((base->f == 8) && base->hew == 1)
		return (1);
	return (0);
}

int						ft_fun_for_z(t_pf_list *base, intmax_t num)
{
	if (base->f == 100 && num < 0)
	{
		base->f = 0;
		if (base->k == 1)
			return (0);
	}
	return (1);
}

int						ft_diff_stor(t_pf_list *base, int len_num)
{
	if (base->acc > len_num && base->temp == 1)
	{
		return (base->acc - ft_strlen(base->num_hh));
	}
	else if (base->acc > len_num)
	{
		return (base->acc - len_num);
	}
	else
		return (0);
}

void					ft_control_flag(t_pf_list *base)
{
	if (base->plus)
		base->space = 0;
	if (base->minus)
		base->nol = 0;
	if (base->width < 0)
	{
		base->width *= -1;
		base->minus = 1;
		base->nol = 0;
	}
	if (base->acc < 0)
	{
		base->acc = 0;
		base->acc_bool = 0;
	}
}
