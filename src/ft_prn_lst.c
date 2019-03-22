/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prn_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:44:14 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/19 18:25:44 by hstiv            ###   ########.fr       */
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
	base->len_return = 0;
	base->len_flag = 0;
	base->temp = 0;
	base->neg = 43;
	base->d = 0;
	base->ld = 0;
	base->f = 0;
	base->num_l = 0;
	base->num_ll = 0;
	base->num_h = 0;
	base->num_hh = 0;
	return(base);
}
