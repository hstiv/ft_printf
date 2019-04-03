/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:09:32 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/26 13:09:35 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_for_hew(t_pf_list *base, unsigned long long int num)
{
	if ((base->hew == 1 && base->f == 97 && num != 0) || base->temp == 1)
	{
		ft_putstr("0x");
		//base->width -= 2;
	// if (base->temp == 1)
	// 	base->len_return += 2;
		base->hew = 0;
	}
	if (base->hew == 1 && base->f == 65 && num != 0)
	{
		ft_putstr("0X");
	//	base->width -= 2;
	//	base->len_return += 2;
		base->hew = 0;
	}
	if (base->hew == 1 && base->f == 8 && num != 0)
	{
		ft_putstr("0");
		base->hew = 0;
	}
}

static void				ft_help_base(t_pf_list *base, int len_num, int diff)
{
	base->width = 0;
	if (base->neg == 1 && diff > 0)
		base->len_return += len_num + diff + 1;
	else if (base->neg == 0 && diff > 0)
		base->len_return += len_num + diff;
	else if (base->neg)
		base->len_return += (len_num + base->neg);
	else if (base->neg == 0 && base->plus == 1)
		base->len_return += len_num + base->plus;
	else
		base->len_return += len_num;
	// else
	// 	base->len_return += base->width + diff;
}

static void				ft_next_step(t_pf_list *base, int len_num, int diff)
{
	if (base->width > base->acc && base->width > len_num)
	{
		if (base->width - 1 > base->acc && base->neg == 1)
		{
			base->len_return += base->width;
			base->width -= (len_num + diff + 1);
		}
		else if (base->neg == 0 && base->space == 0 && base->plus == 1)
		{
			base->len_return += base->width;
			base->width -= (len_num + diff + 1);
		}
			else
		{
	// 	}
	// 	else if (base->space)
	// 	{
	// 		base->len_return += base->width;
	// 		base->width -= (len_num + diff + 1);
	// //		printf("\n spwidth = %d\n", base->width);
	// 	}
		
			base->len_return += base->width;
			base->width -= (len_num + diff + base->neg);
	//		printf("\n width = %d\n", base->width);
		}
		// else
		// 	base->len_return += base->width + diff;
	}
	else
	{
		ft_help_base(base, len_num, diff);
	}
}

static void				ft_base_min(t_pf_list *base, int diff,
					unsigned long long int num, int len_num)
{
	ft_next_step(base, len_num, diff);
	if (base->neg == 1 && !base->f)
		ft_putchar('-');
	if (base->neg == 0 && base->space == 0 && base->plus == 1 && !base->f)
		ft_putchar('+');
	ft_for_hew(base, num);
	while (diff-- > 0)
		ft_putchar('0');
	if ((num == 0) && base->acc == 0 && base->acc_bool == 1 && !(base->f == 8 && base->hew == 1))
		{
			if(base->width > 0)
				base->width++;
			else
			{
				base->len_return -= 1;
			}
			
		}
	else if (base->f)
	{
		ft_putstr(base->num_hh);
		free (base->num_hh); //
	}
	else
		ft_putnbr_prntf(num);
	while (base->width-- > 0)
		ft_putchar(' ');
}

static void				ft_base_non_min(t_pf_list *base, int diff,
					unsigned long long int num, int len_num)
{
	ft_next_step(base, len_num, diff);
	if (base->nol == 0 && base->width > 0 && base->space == 1 && base->neg == 0 && (base->width <= diff + 1))
	{
		ft_putchar(' ');
		base->space = 0;
	}
	else if (base->space == 1 && base->neg == 0 && ((base->width <= diff + 1) || (base->acc_bool == 0 && (base->width == len_num + 1))) && !base->f) //base->nol == 0 && 
	{
		ft_putchar(' ');
		base->space = 0;
		// if (base->width < len_num + 1)
		
		if (base->acc_bool == 0 && (base->width == len_num + 1))
			--base->width;
		else
			base->len_return++;
	}
	while (base->nol == 0 && base->width-- > 0)
		ft_putchar(' ');
	if (base->neg == 1 && base->nol == 1 && !base->f)
		ft_putchar('-');
	if (base->neg == 0 && base->space == 0 && base->plus == 1 && !base->f)
		ft_putchar('+');
	if (base->neg == 1 && base->nol == 0 && !base->f)
		ft_putchar('-');
	ft_for_hew(base, num);
	while (base->nol == 1 && base->acc_bool && base->width-- > 0 )
		ft_putchar(' ');
	while (base->nol == 1 && base->width-- > 0)
		ft_putchar('0');
	// while (base->nol == 1 && base->width-- > 0)
	// 	ft_putchar(' ');
	while (diff-- > 0)
		ft_putchar('0');
	if ((num == 0) && base->acc == 0 && base->acc_bool == 1 && !(base->f == 8 && base->hew == 1))
	{	
		if(base->wid_bool == 1)
			ft_putchar(' ');
		else
			base->len_return -= 1;
	}
	else if (base->f)
	{
		ft_putstr(base->num_hh);
		free (base->num_hh); //
	}
	else
		ft_putnbr_prntf(num);

		
}

void					ft_magic_base(t_pf_list *base, int diff,
								long long int num, int len_num)
{
	if (base->minus)
	{
		if (base->neg)
			ft_base_min(base, diff, (unsigned long long int)num * (-1),
															len_num);
		else
			ft_base_min(base, diff, (unsigned long long int)num, len_num);
	}
	else
	{
		if (base->neg)
			ft_base_non_min(base, diff, (unsigned long long int)num * (-1),
															len_num);
		else
			ft_base_non_min(base, diff, (unsigned long long int)num, len_num);
	}
}
