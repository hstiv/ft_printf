/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:44:50 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/19 16:50:23 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{
//	char	str[10] = "12345";
//	printf("%d\n", ft_printf("\n!!!!%*.*i!!!!\n", 8, 3, 12));
//	printf("our- %d\n", ft_printf("\n*%g*\n", 6645555555555555555576575679845677986455555555555554568.123456));
//	printf("sys- %d\n", printf("\n*%g*\n", 6644555555555465253674572534534564564566354675237645672354675236754762537642368.123456));
//	printf("%d\n", printf("\n!!!!%f!!!!\n", 300.87));
//	printf("%d\n", printf("\n!!!!%*.*lo!!!!\n", 8, 3, 3147483647));55
//	printf("%d\n", ft_printf("\n*%bs*\n",2));
//	printf("%d\n", printf("\n%s\n","ДРАТУТЕ"));
	printf("%d", ft_printf("\n!!!!%S!!!!\n", "П"));
	   printf("%d", printf("\n!!!!%s!!!!\n", "П"));
//	ft_printf("\n%s\n", "75545");

//	ft_printf("%% 12345\n%s\n%d\nPU%s %s LU%s\n", "fu", 586, "PA", "i", "PA");
//	printf ("%d", ft_printf("\n\n***%.10d ***\n\n", 555));
//	printf("%d", printf("\n\n****%+.10d ***\n\n", 555));
//	printf("12345\n %%ss \n%s \ndsad asd \n", "fuf");
//	printf("Le fichier{cyan}%s{eoc} contient : {red}%s{eoc}", "filename", str);
//	fprintf( "%.*f", 3, 2.5);
//	 printf("%*.*lf\n", 8, 4, 2.43 );
	//  printf("\n%d\n", printf("\n*%+*.*f*\n", 15, 5, 2.43));
	//  printf("\n%d\n", ft_printf("\n*%+*.*f*\n", 15, 5, 2.43));
//	printf("*%f*\n", 2.56789);
//	ft_printf("\n*%f*\n", 2.5789);
//	ft_ftoa(2.24, 10);
	return(0);
}
// %[флаги -+ #0 ][ширина][.точность][размер]тип

// %-+ #0*.*s
