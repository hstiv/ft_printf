/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:44:50 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/17 03:25:43 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{

//	char	str[10] = "12345";
//	printf("%d", ft_printf("\n!!!! %7.5d   !!!!\n", 5));
//	   printf("%d", printf("\n!!!! %-+14.5d   !!!!\n", 5));
	
//	ft_printf("\n%s\n", "75545");

//	ft_printf("%% 12345\n%s\n%d\nPU%s %s LU%s\n", "fu", 586, "PA", "i", "PA");
//	printf ("%d", ft_printf("\n\n*** -22.33d ***\n\n"));
//	printf("%d", printf("\n\n*** -22.33d ***\n\n"));
//	printf("12345\n %%ss \n%s \ndsad asd \n", "fuf");
//	printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", str);
	printf( "%f\n", 2.5326364573756);
	// printf( "%0*.*f\n", 8, 4, 2.5 );
	// printf( "%0*.*f\n", 0, 4, 2.5 );
	// printf( "%0*f\n", 0, 2.5 );
//	ft_ftoa(2.24, 10);
	return(0);
}

// %[флаги -+ #0 ][ширина][.точность][размер]тип

// %-+ #0*.*s
