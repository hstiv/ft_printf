/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 03:37:13 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/24 05:42:33 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		b_print_bits(char *s, t_pf_list *base, int i)
{
	int			count;

	while(s[i])
	{
		count = 0;
		while (s[i] != ' ')
		{
			if (s[i] == '1')
				count++;
			i--;
		}
		if(count == 0)
		{
			i = i + 6;
			ft_putstr(s + i);
			base->len_return += ft_strlen(s + i);
			return ;
		}
		i--;
	}
}

int				ft_puter(char *str, t_pf_list *base, int l)
{
	int				i;
	char			s[4];

	i = 0;
	s[0] = 'e';
	s[1] = '+';
	if (base->num_h > 9)
		{
			s[2] = (base->num_h / 10) + '0';
			s[3] =(base->num_h % 10) + '0';
		}
	else
	{
		s[2] = '0';
		s[3] = base->num_h + '0';
	}
	while (s[i])
	{
		str[l] = s[i];
		i++;
		l++;
	}
	return (4);
}

void			ft_type_e(long double nb, t_pf_list *base)
{
	if (nb < 0)
	{
		base->neg = '-';
		nb *= -1;
	}
	while ((long long int)nb > 9)
	{
		base->num_h++;
		nb = nb / 10;
	}
	base->width -= 4;
	pf_ftoa(nb, base);
	if (!base->minus)
	{
		write(1,"e+", 2);
		if (base->num_h > 9)
			ft_putstr(ft_itoa(base->num_h));
		else
		{
			ft_putchar(48);
			ft_putchar(base->num_h + '0');
		}
		base->len_return += 4;
	}
}

static int			ft_make_str(char *str, unsigned long long int octet)
{
	unsigned long long int		t;
	int							o;
	int							i;

	o = 0;
	i = 0;
	t = 1152921504606846976;
	while (t >>= 1)
	{
		if (o % 4 == 0 && o > 3)
		{
			str[i] = ' ';
			i++;
		}
		if (octet & t)
			str[i] = '1';
		else
			str[i] = '0';
		i++;
		o++;
	}
	str[i] = '\0';
	return (i);
}

static void			ft_type_b(va_list ap, t_pf_list *base)
{
	unsigned long long int		octet;
	char						*str;
	int							i;
	
	octet = va_arg(ap, unsigned long long int);
	str = (char *)malloc(sizeof(char) * (35 * 4));
	i =	ft_make_str(str, octet);
	b_print_bits(str, base, i - 1);
	free(str);
}

int					ft_type_b_e(const char *format, va_list ap, int i, t_pf_list *base)
{
	if (*format == 'b')
	{
		ft_type_b(ap, base);
		i++;
	}
	else if (*format == 'e' || (*format == 'L' && *(format + 1) == 'e') || *format == 'E')
	{
		if (*format == 'L')
		{
			i += 2;
			ft_type_e(va_arg(ap, long double), base);
		}
		else
		{
			i++;
			ft_type_e(va_arg(ap, double), base);
		}
	}
	format++;
	return (i);
}
