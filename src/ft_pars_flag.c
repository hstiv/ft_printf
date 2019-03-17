/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:06:42 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/17 18:53:38 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_pars_flag(t_pf_list *base, const char *format)
{
    int		bol;

    bol = 1;
    if (*format == '#')
		base->hew = 1;
	else if (*format == '0')
		base->nol = 1;
	else if (*format == ' ')
		base->space = 1;
	else if (*format == '+')
		base->plus = 1;
	else if (*format == '-')
		base->minus = 1;
	else
		bol = 0;
    return (bol);
}

// %[флаги -+ #0 ][ширина][.точность][размер]тип

// %-+ #0*.*s
