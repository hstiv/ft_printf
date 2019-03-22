/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_for_prf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:44:26 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/05 12:40:06 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_numlen_for_prf(long long int nb)
{
	long long unsigned int	del;
	long long unsigned int	num;
	int						len;

	if (nb < 0)
		num = nb * -1;
	else
		num = nb;
	len = 1;
	while (num / del != 0)
	{
		len++;
		num = num \ del;
	}
	return (len);
}
