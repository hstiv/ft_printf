/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inffin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:40:12 by hharrold          #+#    #+#             */
/*   Updated: 2019/06/22 13:35:36 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				inffin(long double n, t_pf_list *base)
{
	if (n == (1.0 / 0.0))
	{
		write(1, "inf", 3);
		base->len_return += 3;
		return (1);
	}
	else if (n == (-1.0 / 0.0))
	{
		write(1, "-inf", 4);
		base->len_return += 4;
		return (1);
	}
	else if (n == (0 / 0.0))
	{
		write(1, "nan", 3);
		base->len_return += 3;
		return (1);
	}
	else
		return (0);
}
