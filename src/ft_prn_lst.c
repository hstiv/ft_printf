/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prn_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:44:14 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/10 17:44:16 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_list	*ft_create_pf_list()
{
	t_pf_list	*base;

	if (!(base = (t_pf_list*)malloc(sizeof(*base))))
		return (NULL);
	base->hew = 0;
	base->space = 0;
	base->plus = 0;
	base->minus = 0;
    base->nol = 0;
    base->width = 0;
    base->wid_bool = 0;
    base->acc = 0;
	base->acc_bool = 0;
	base->len = 0;
	base->len_str = 0;
	return(base);
}
