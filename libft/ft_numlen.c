/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:44:26 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/17 07:27:01 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_numlen(int nb)
{
	long long unsigned int	del;
	unsigned int			num;
	int						len;

	if (nb < 0)
		num = nb * -1;
	else
		num = nb;
	del = 10;
	len = 1;
	while (num / del != 0)
	{
		len++;
		del = del * 10;
	}
	return (len);
}
