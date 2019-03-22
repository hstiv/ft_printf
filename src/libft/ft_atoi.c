/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:44:19 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/07 14:21:52 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int							z;
	int							a;
	long long unsigned int		nb;
	long long unsigned int		nb2;

	a = 0;
	z = 1;
	nb = 0;
	nb2 = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == ' ')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a++] == '-')
			z = -1;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		nb = nb * 10 + ((str[a++] - '0'));
		if (nb > 9223372036854775807 || nb / 10 != nb2)
			return (z > 0 ? -1 : 0);
		nb2 = nb;
	}
	nb = (long long int)nb * z;
	return (nb);
}
