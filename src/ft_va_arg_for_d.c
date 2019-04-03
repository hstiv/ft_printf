/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_for_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:41:21 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/26 12:41:23 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_l_ll_mod(va_list ap, t_pf_list *base)
{
	long long int		num;

	if (base->ld == 1)
		num = (long long int)va_arg(ap, long int);
	else
		num = va_arg(ap, long long int);
	return (num);
}

static long long int	ft_h_hh_mod(va_list ap, t_pf_list *base)
{
	long long int		num;
	num = 0;
//	printf("\nbasef %d\n num %lld ld %d d %d\n", base->f, num, base->ld, base->d);
	if (base->d == 1 && base->k == 0)
		num = (short)va_arg(ap, int);
		//num = va_arg(ap, int);
	// else if	(base->d == 2 && base->k == 0)
	// 	num = (char)va_arg(ap, int);
	// else if (base->d == 1 && base->k == 1)
	// 	num = va_arg(ap, int);
	else
		num = (char)va_arg(ap, int);
	
//printf("\nbasef %d\n num %lld ld %d d %d\n", base->f, num, base->ld, base->d);
	return (num);
}

static long long int	ft_h_hhu_mod(va_list ap, t_pf_list *base)
{
	unsigned short int		num;
	unsigned char			num1;

	num = 0;
//	printf("\nbasef %d\n num %lld ld %d d %d\n", base->f, num, base->ld, base->d);
	if (base->d == 1)
		num = va_arg(ap, int);
		//num = va_arg(ap, int);
	else
	{	
	num1 = va_arg(ap, int);
	return ((int)num1);
	}
//printf("\nbasef %d\n num %lld ld %d d %d\n", base->f, num, base->ld, base->d);
	return (num);
}

long long int			ft_va_arg_for_d(va_list ap, t_pf_list *base)
{
	intmax_t		num;

	num = 0;
//printf("\nbasef %d\n num %jd ld %d d %d k %d\n", base->f, num, base->ld, base->d, base->k);
	if (base->ld && (base->f != 100))
		num = ft_l_ll_mod(ap, base);
	else if (base->d && (base->f != 100) && base->k == 0)
		num = ft_h_hh_mod(ap, base);
	else if (base->d && (base->f != 100) && base->k == 1)
		num = ft_h_hhu_mod(ap, base);
	else if ((base->f == 100 && base->k == 0) || base->k == 2)
	{
		//num = va_arg(ap, unsigned long long);
		base->num_ull = va_arg(ap, unsigned long long);
	//	printf("\nllu %llu\n", base->num_ull);
		ft_for_base_num(base->num_ull, base);
	//	printf("\nllu %s\n", base->num_hh);
	//	return (base->num_ull);
	}
	else if (base->f == 100 && base->k == 1)
	{
		num = va_arg(ap, unsigned long long);
		//base->num_ull = va_arg(ap, unsigned long long);
	//	printf("\nllu %llu\n", base->num_ull);
	
	//	ft_for_base_num(base->num_ull, base);
	//	printf("\nllu %s\n", base->num_hh);
	//	return (base->num_ull);
	}
	else
		num = (int)va_arg(ap, int);
//	printf("\nbasef %d\n num %jd\n", base->f, num);
	return (num);
}
