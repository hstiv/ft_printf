/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:20:34 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/13 18:20:36 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...) // USED 
{
    int			result;
    va_list		ap;
	t_pf_list	*base;

	if(!(base = ft_create_pf_list()))
		return(-1);
	va_start(ap, format);
    result = ft_parsing_prnt(format, ap, base);
	va_end(ap);
    return(result);
}
