/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_acc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:04:56 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/28 00:05:04 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_type_s_accuracy(t_pf_list *base)
{
	if (base->minus && base->wid_bool && base->temp && base->acc_bool)
		base->acc = base->width;
	else if (base->minus && base->width && base->temp == 1)
		base->acc = base->width - base->acc;
	if (base->temp == 1 && !base->minus)
		base->acc = 0;
	if (base->acc && base->nol && base->width == -20)
		base->acc--;
	while (base->acc > 0 && (!base->temp || base->wid_bool))
	{
		if (base->nol)
			ft_putchar('0');
		else
			ft_putchar(' ');
		base->len_return++;
		base->acc--;
	}
}

void		ft_type_s_precision(t_pf_list *base)
{
	int		i;

	i = base->width - base->acc;
	while (i-- > 0)
	{
		if (base->nol)
			ft_putchar('0');
		else
			ft_putchar(' ');
		base->len_return++;
	}
	base->width = 0;
}
