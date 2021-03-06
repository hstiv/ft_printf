/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:48:22 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/01 15:48:24 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strclen(char *str, char c)
{
	int		len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}
