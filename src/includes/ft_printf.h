/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:12:52 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/19 18:25:01 by hstiv            ###   ########.fr       */
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
	int						len_return;
	int						len_flag;
	int						f;
	int						neg;
	int						temp;
	int						d;
	int						ld;
	long int				num_l;
	long long int			num_ll;
	int				num_h;
	char					num_hh;
}							t_pf_list;

long double		acnzero(long double n, t_pf_list *base);
int				acczero(char c);
size_t			facc(long double n, t_pf_list *base, int sign);
int				ft_point_flags_f_d_i(const char *format, va_list ap,int *i,
														t_pf_list *base);
int				ft_printf(const char *format, ...);
int				ft_parsing_prnt(const char *format, va_list ap);
void			pf_ftoa(long double n, t_pf_list *base);
int				ft_strclen(char *str, char c);
void			ft_spaces_nol(t_pf_list *base);
int				ft_pars_flag(t_pf_list *base, const char *format);
int				ft_type_f(const char *format, va_list ap, t_pf_list *base);
int				ft_type_s(const char *format, va_list ap, int i,
														t_pf_list *base);
int				ft_type_d(va_list ap, t_pf_list *base);
void			ft_putnbr_prntf(int n);
int				ft_numlen_for_prf(long long int nb);
t_pf_list		*ft_create_pf_list();
#endif