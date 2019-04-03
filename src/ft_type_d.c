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

static int				ft_numlen_base(uintmax_t value, int base)
{
	long		i;

	i = 0;
	while (value)
	{
		i++;
		value /= base;
		
	}
	return (i);
}

static char				*ft_str_for_null(void)
{
	char *s;

	s = ft_strnew(1);
	s[0] = '0';
	s[1] = 0;
	return (s);
}

static char				*ft_itoa_unsigned(uintmax_t num, int base, t_pf_list *b)
{
	uintmax_t		value;
	long			i;
	char			*s;

	i = 0;
	if(b->k == 2)
		value = num;
	else if (b->f == 100)
		value = (unsigned long)num;
	else if (!b->ld && !b->d)
		value = (unsigned int)num;
	else
		value = num;
	i = ft_numlen_base(value, base);
	if (num == 0)
		s = ft_str_for_null();
	else
	{
		s = ft_strnew(i);
		s[i] = 0;
		while (value)
		{
			s[--i] = "0123456789abcdef"[value % base];
			value /= base;
		}
	}
	return (s);
}

void				ft_for_base_num(uintmax_t num, t_pf_list *base)
{
	if (base->f == 8)
		base->num_hh = ft_itoa_unsigned(num, 8, base);
	else if (base->f == 10)
		base->num_hh = ft_itoa_unsigned(num, 10, base);
	else if (base->f == 100)
		base->num_hh = ft_itoa_unsigned(num, 10, base);
	else
		base->num_hh = ft_itoa_unsigned(num, 16, base);
	if (base->f == 65)
		ft_strupper(base->num_hh);
}

int						ft_type_d(va_list ap, t_pf_list *base)
{
	intmax_t		num;
	int				len_num;
	int				diff;

	diff = 0;
	
	num = ft_va_arg_for_d(ap, base);
//	printf("\nnum %jd\n", num);
	if (base->f == 100 && num < 0)
	{
	//	printf("\nin f = 0 %llu\n", base->num_ull);
		base->f = 0;
		if (base->k == 1)
			num = -1;
	}
	if (base->f)
	{
	//	printf("\nin f %llu\n", base->num_ull);
		if (base->num_ull == 0)
			ft_for_base_num(num, base);
		len_num = ft_strlen(base->num_hh);
		if (((base->f == 65 || base->f == 97) && base->hew == 1 && num != 0) || base->temp == 1)
			len_num += 2;
		if ((base->f == 8) && base->hew == 1 && num != 0)
			len_num += 1;
	}
	else
		len_num = ft_numlen_for_prf(num);
	if (num < 0 && !base->f)
	{
		base->neg = 1;

	}
	else
		base->neg = 0;
	if (base->acc > len_num && base->temp == 1)
		diff = base->acc - ft_strlen(base->num_hh);
	else if (base->acc > len_num)
		diff = base->acc - len_num;
	ft_magic_base(base, diff, num, len_num);
	// if (base->temp == 1)
	// 	return (1);
	// else
		return (1);
}
