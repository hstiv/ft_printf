/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:38:58 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/28 16:39:02 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_type_r(va_list ap, t_pf_list *base)
{
	char		*s;
	int			i;

	s = va_arg(ap, char *);
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isprint(s[i]) == 0)
			s[i] = '*';
		i++;
	}
	base->len_return = ft_strlen(s);
	write(1, s, ft_strlen(s));
}
