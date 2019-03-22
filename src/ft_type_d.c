/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:19:19 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/19 15:49:02 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_magic_base(t_pf_list *base, int len_num , int diff)
{
	if (base->width > base->acc && base->width > len_num)
	{
		if (base->width - 1 > base->acc && base->neg == 1)
		{
			base->len_return += base->width;
			base->width -= base->acc + 1;
		}
		else if (base->neg == 0 && base->space == 0 && base->plus == 1)
		{
			base->len_return += base->width;
			base->width -= base->acc + 1;
		}
		else
		{
			base->len_return += base->width;
			base->width -= base->acc;
		}
	}
	else
	{
		base->width = 0;
		if (base->neg == 1 && diff > 0)
			base->len_return += len_num + diff + 1;
		else if (base->neg == 0 && diff > 0)
			base->len_return += len_num + diff;
		else if (base->neg == 1 && diff < 0)
			base->len_return += len_num + 1;
		else
			base->len_return += len_num;
	}
}

static void		ft_base_min(t_pf_list *base, int diff, int num, int len_num)
{
	ft_magic_base(base, len_num, diff);
	if (base->neg == 1)
		ft_putchar('-');
	if (base->neg == 0 && base->space == 0 && base->plus == 1)
		ft_putchar('+');
	while (diff-- > 0)
		ft_putchar('0');
	ft_putnbr_prntf(num);
	while (base->width-- > 0)
		ft_putchar(' ');
}

static void		ft_base_non_min(t_pf_list *base, int diff, int num, int len_num)
{
	ft_magic_base(base, len_num, diff);
	while (base->width-- > 0)
		ft_putchar(' ');
	if (base->neg == 1 && base->nol == 1)
		ft_putchar('-');
	if (base->neg == 0 && base->space == 0 && base->plus == 1)
		ft_putchar('+');
	if (base->neg == 1 && base->nol == 0)
		ft_putchar('-');
	while (diff-- > 0)
		ft_putchar('0');
	ft_putnbr_prntf(num);
}
// int			ft_l_ll_mod(va_list ap, t_pf_list *base)
// {
// 	if (base->ld == 1)
// 	{
// 		base->num_l = va_arg(ap,long int);
// 		if (base->num_l < 0)
// 			base->neg = 1;
// 		return ((long long int)base->num_l);
// 	}
// 	else
// 	{
// 		base->num_ll = va_arg(ap,long long int);
// 		if (base->num_ll < 0)
// 			base->neg = 1;
// 		return ((long long int)base->num_ll);
// 	}
// }

// int			ft_h_hh_mod(va_list ap, t_pf_list *base)
// {
// 	if (base->d == 1)
// 	{
// 		base->num_h = va_arg(ap, short);
// 		if (base->num_h < 0)
// 			base->neg = 1;
// 		return ((long long int)base->num_h);
// 	}
// 	else
// 	{
// 		base->num_hh = va_arg(ap, char);
// 		if (base->num_hh < 0)
// 			base->neg = 1;
// 		return ((long long int)base->num_hh);
// 	}
// }

int				ft_type_d(va_list ap, t_pf_list *base)
{
	long long int		num;
	int					len_num;
	int					diff;

	// if(base->ld)
	// 	num = ft_l_ll_mod(ap, base);
	// else if (base->d)
	// 	num = ft_h_hh_mod(ap, base);
	num = (long long int)va_arg(ap, int);
	len_num = ft_numlen(num);
	if (num < 0)
		base->neg = 1;
	else
		base->neg = 0;
	if (base->acc > len_num)
		diff = base->acc - len_num;
	if (base->minus)
		ft_base_min(base, diff, num, len_num);
	else
		ft_base_non_min(base, diff, num, len_num);
	return (base->d + base->ld + 1);
}

// static char			*ft_itoa_d(t_pf_list *base, va_list ap)
// {
// 	char			*char_num;
// 	int				num;

// 	char_num = NULL;
	// if(base->ld)
	// {
	// 	// if (base->ld == 1)
	// 	// {
	// 	// 	base->num_l = va_arg(ap,long int);
	// 	// 	if (base->num_l < 0)
	// 	// 		base->neg == 1;
	// 	// 	ft_hiaiarka((long long int)base->num_l);
	// 	// }
	// 	// else
	// 	// {
	// 	// 	base->num_ll = va_arg(ap,long long int);
	// 	// 	if (base->num_ll < 0)
	// 	// 		base->neg == 1;
	// 	// 	ft_hiaiarka((long long int)base->num_ll);
	// 	// }
	// }
	// else if(base->d)
	// {
	// 	if (base->d == 1)
	// 		base->num_h = va_arg(ap, short int);
	// 	else
	// 		base->num_hh = va_arg(ap, char);
	// }
	// else
	// 	num = va_arg(ap, int);
	//len_num = ft_numlen_for_prf(num);
	//return(char_num);
//}

// #include <unistd.h>

// void	ft_putnbr_prntf(int n)
// {
// 	if (n < 0)
// 	{
// 		if (n == -2147483648)
// 		{
// 			ft_putnbr_prntf(214748364);
// 			ft_putnbr_prntf(8);
// 		}
// 		else
// 		{
// 			n = n * -1;
// 			ft_putnbr_prntf(n);
// 		}
// 	}
// 	else if (n <= 9)
// 	{
// 		n = n + '0';
// 		write(1, &n, 1);
// 	}
// 	else
// 	{
// 		ft_putnbr_prntf(n / 10);
// 		ft_putnbr_prntf(n % 10);
// 	}
// }
