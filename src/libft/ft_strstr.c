/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:01:31 by hharrold          #+#    #+#             */
/*   Updated: 2018/11/29 21:19:33 by hharrold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	if (needle[b] == '\0')
		return ((char*)&haystack[a]);
	while (haystack[a] != '\0' && needle[b] != '\0')
	{
		if (haystack[a] == needle[b])
		{
			c = a;
			while (haystack[c] == needle[b])
			{
				if (haystack[c++] == '\0' || needle[b++] == '\0')
					break ;
			}
			if (needle[b] == '\0')
				return ((char*)&haystack[a]);
			b = 0;
		}
		a++;
	}
	return ((char*)0);
}
