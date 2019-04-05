/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstiv <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 02:46:44 by hstiv             #+#    #+#             */
/*   Updated: 2019/03/19 18:11:10 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		afterstr_maker(char *str, t_pf_list *b, size_t i, long double n)
{
	if (b->acc > 0 || b->minus)
	{
		(b->acc > 0) ? (str[i++] = '.') : 0;
		(b->minus && !b->nol && !b->space) ? (b->temp++) : 0;
		while (b->acc > 0 && !b->num_ll)
		{
			n *= 10;
			n = acnzero(n, b);
			if ((int)(n + 0.000001) != 10 && ((int)n != 10))
				str[i++] = (int)((n + 0.000001) + '0');
			else
				str[i++] = '0';
			b->acc--;
			n -= (int)n;
		}
		if (b->num_h && !b->d && !b->ld && !b->f && b->minus)
			i += ft_puter(str, b, i);
		while (b->temp-- > 1 && b->minus)
			str[i++] = ' ';
		while (b->acc-- > 0 && !b->minus)
			str[i++] = '0';
	}
	str[i] = '\0';
	b->len_return += (ft_strlen(str));
	write(1, str, ft_strlen(str));
}

static int		prestr_maker(t_pf_list *base, char *str)
{
	int			i;

	i = 0;
	if (base->neg == '-' || base->plus)
		base->temp--;
	(base->nol && base->space && base->neg == '-'s
						&& base->temp) ? (base->temp++) : 0;
	if ((base->plus || base->neg == 45) && base->nol)
		str[i++] = base->neg;
	if (base->space && !base->nol && !base->plus && base->neg == '+')
		str[i++] = ' ';
	if (base->temp > 0 && !base->minus)
	{
		if (base->neg == '-' && base->nol && !base->plus
					&& !base->minus && !base->space)
			base->temp++;
		if (base->nol)
			while (base->temp > i)
				str[i++] = '0';
		if (base->temp > i)
			while (base->temp > i)
				str[i++] = ' ';
		return (i);
	}
	return (i);
}

static void		ft_convert_rest(char *s, long double n, t_pf_list *b, int dot)
{
	size_t		i;

	(b->minus && b->space && b->neg == '-' && b->acc) ? (b->acc++) : 0;
	i = prestr_maker(b, s);
	if ((b->plus || b->neg == '-') && !b->nol)
		s[i++] = b->neg;
	while (dot--)
	{
		n *= 10;
		s[i++] = (int)n + '0';
		n -= (int)n;
		if (b->acc == 0 && ((int)(n * 10) >= 5) && dot <= 0
						&& (acczero(s[i - 1]) != 0))
			s[i - 1] += 1;
	}
	afterstr_maker(s, b, i, n);
}

static void		ft_convert(char *str, long double n, t_pf_list *base)
{
	int			dot;

	dot = 0;
	if (n < 0)
	{
		base->neg = 45;
		n = -n;
	}
	while (n >= 1)
	{
		n /= 10;
		dot++;
		base->wid_bool++;
	}
	if (base->plus && base->acc == 0 && base->nol != 0)
		base->temp--;
	if (dot > 15)
		base->num_ll = 1;
	ft_convert_rest(str, n, base, dot);
}

void			pf_ftoa(long double n, t_pf_list *base)
{
	char		*str;
	int			l;
	long double	t;

	t = n;
	if (base->space && base->plus)
		base->space = 0;
	if (base->nol && base->minus)
		base->nol = 0;
	if (t < 0)
		t *= -1;
	if ((inffin(n, base)))
		return ;
	l = facc(t, base);
	str = (char *)malloc(sizeof(str) * (l + 1));
	if (str && t != 1)
		ft_convert(str, n, base);
	free(str);
}
