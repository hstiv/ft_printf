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

static void		fstr_maker(char *str, t_pf_list *base, size_t i, long double n)
{
	long double	nb;

	nb = 0.000001;
	if (base->acc > 0)
	{
		str[i++] = '.';
		while (base->acc > 0)
		{
			n *= 10;
//			n = acnzero(n, base);
			if ((int)(n + nb) != 10 && ((int)n != 10))
				str[i++] = (int)(n + '0' + nb);
			else
				str[i++] = '0';
			base->acc--;
			n -= (int)n;
		}
		if (base->temp > 0 && base->minus)
			while (base->temp--)
				str[i++] = ' ';
		while (base->acc-- > 0)
			str[i++] = '0';
	}
	str[i] = '\0';
	base->len_return += (ft_strlen(str));
	ft_putstr(str);
}

static int		prestr_maker(t_pf_list *base, char *str)
{
	int			i;

	i = 0;
	if ((base->plus || base->neg == 45) && base->nol)
		str[i++] = base->neg;
	if (base->temp > 0 && !base->minus)
	{
		if (base->nol != 0)
			while (base->temp > i)
				str[i++] = '0';
		if (base->temp > i)
			while (base->temp > i)
				str[i++] = ' ';
		return (i);
	}
	return (i);
}

static void		ft_convert_rest(char *str, long double n, t_pf_list *base, int dot)
{
	size_t		i;

	i = prestr_maker(base, str);
	if ((base->plus || base->neg == '-') && !base->nol)
		str[i++] = base->neg;
	n = acczero(n, base, dot);
	while (dot--)
	{
		n *= 10;
		str[i++] = (int)n + '0';
		n -= (int)n;
	}
	fstr_maker(str, base, i, n);
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
	ft_convert_rest(str, n, base, dot);
}

void			pf_ftoa(long double n, t_pf_list *base)
{
	char		*str;
	int			l;
	int			sign;
	long double	t;

	t = n;
	sign = 0;
	if (base->space && base->plus)
		base->space = 0;
	if (base->nol && base->minus)
		base->nol = 0;
	if (t < 0)
	{
		t *= -1;
		sign = 1;
	}
	l = facc(t, base, sign);
	str = (char *)malloc(sizeof(str) * (l + 1));
	if (str)
		ft_convert(str, n, base);
	free(str);
}
