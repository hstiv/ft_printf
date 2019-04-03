/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:12:52 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/28 03:08:38 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

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
	int						k;
	int						ld;
	long int				num_l;
	long long int			num_ll;
	unsigned long long int	num_ull;
	int						num_h;
	int						g_e;
	char					*num_hh;
}							t_pf_list;

int					inffin(long double n, t_pf_list *base);
void				ft_type_e(long double nb, t_pf_list *base);
int					ft_type_b_e(const char *format, va_list ap,
							int i, t_pf_list *base);
int					ft_type_g(const char *format, va_list ap,
							int i, t_pf_list *base);
long double			acnzero(long double n, t_pf_list *base);
int					acczero(char c);
int					ft_puter(char *s, t_pf_list *base, int l);
size_t				facc(long double n, t_pf_list *base);
int					ft_point_flags_f_d_i(const char *format, va_list ap, int *i,
												t_pf_list *base);
int					ft_point_flags_x_o(const char *format, va_list ap, int *i,
							t_pf_list *base);
int					ft_printf(const char *format, ...);
int					ft_parsing_prnt(const char *format, va_list ap);
int					ft_fill_flag(t_pf_list *base, const char *format,
							va_list ap);
void				pf_ftoa(long double n, t_pf_list *base);
int					ft_strclen(char *str, char c);
void				ft_spaces_nol(t_pf_list *base);
int					ft_pars_flag(t_pf_list *base, const char *format);
int					ft_type_f(const char *format, va_list ap, t_pf_list *base);
int					ft_type_s(const char *format, va_list ap, int i,
														t_pf_list *base);
int					ft_point_flags_u(const char *format, va_list ap, int *i,
														t_pf_list *base);
long long int		ft_va_arg_for_d(va_list ap, t_pf_list *base);
void				ft_magic_base(t_pf_list *base, int diff,
								long long int num, int len_num);
int					print_hex(long long int nb, t_pf_list *base);
void				ft_type_r(va_list ap, t_pf_list *base);
int					ft_type_d(va_list ap, t_pf_list *base);
void				ft_putnbr_prntf(unsigned long long int n);
int					ft_numlen_for_prf(long long int nb);
void				ft_for_base_num(uintmax_t num, t_pf_list *base);
t_pf_list			*ft_create_pf_list();
#endif
