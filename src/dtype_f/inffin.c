/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inffin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:40:12 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/28 16:40:15 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				inffin(long double n, t_pf_list *base)
{
	if (n == (1.0 / 0.0))
	{
		ft_putstr("inf");
		base->len_return += 3;
		return (1);
	}
	else if (n == (-1.0 / 0.0))
	{
		ft_putstr("-inf");
		base->len_return += 4;
		return (1);
	}
	else if (n == (0 / 0.0))
	{
		ft_putstr("nan");
		base->len_return += 3;
		return (1);
	}
	else
		return (0);
}
