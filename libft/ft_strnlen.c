/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:13:41 by hharrold          #+#    #+#             */
/*   Updated: 2018/12/05 16:20:16 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0' && len < maxlen)
		len++;
	return (len);
}
