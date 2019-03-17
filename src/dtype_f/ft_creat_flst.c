/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_flst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 05:04:25 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/17 19:39:29 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_typef			*ft_creat_flst(void)
{
	t_typef		*base;

	if (!(base = (t_typef*)malloc(sizeof(*base))))
		return (0);
	base->f = 1;
	base->d = 1;
	base->ld = 1;
	return (base);
}
