/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:12:52 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/17 03:09:01 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h> // PRINTF

typedef struct				s_pf_list
{
	int						hew;
	int						space;
	int						plus;
	int						minus;
	int						nol;
	int						width;
	int						wid_bool;
	int						acc_bool;
	int						acc;
	int						len;
	int						len_str;
}							t_pf_list;

int				ft_printf(const char *format, ...);
int    			 ft_parsing_prnt(const char *format, va_list ap, t_pf_list *base);
void			ft_ftoa(double n, int afterpoint);
int				ft_strclen(char *str, char c);
void			ft_spaces_nol(t_pf_list *base);
int     		ft_pars_flag(t_pf_list *base, const char *format);
int				ft_type_s(const char *format, va_list ap, int i, t_pf_list *base);
int				ft_type_d(const char *format, va_list ap, int i, t_pf_list *base);
t_pf_list		*ft_create_pf_list();
#endif
