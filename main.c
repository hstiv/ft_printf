/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hharrold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:44:50 by hharrold          #+#    #+#             */
/*   Updated: 2019/03/28 06:12:37 by hstiv            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
#include <stdio.h>
//#include <project.h>
//#include <limits.h>
//#include <stdlib.h>
//#include <wchar.h>
//# include <stddef.h>
#include "ft_printf.h"

int		main()
{ 	
	char c;

	// printf("\n\nTYPE S and s\n");
	// printf("\n('{%%s}', 0)\n\n");
	// printf("\nour %d\n", ft_printf("{%s}", 0));
	// printf("\nsys %d\n", printf("{%s}", 0));
	// printf("\n");
	// printf("\n'{%% S}', L'(null)\\n'\n\n'");
	printf("\nour - %d\n", ft_printf("*%*.*G* %d", 0, 0, 35542313.1244526563, 10));
	printf("\nsys - %d\n", printf("*%*.*G* %d", 0, 0, 35542313.1244526563, 10));
	// printf("\n");
	
	// printf("\nsys - %d\n", ft_printf("{%f}{%F}", 1.42, 1.42));
	// printf("\nsys - %d\n", printf("{%f}{%F}", 1.42, 1.42));
	//ft_printf("\nour{%030S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");
	//printf("\nsys{%030S}\n", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B");

	// printf("\n'{%%s}', ''\n\n");
	// printf("\nour - %d\n", ft_printf("{%s}", ""));
	// printf("\nsys - %d\n", printf("{%s}", ""));
	// printf("\n");

	// printf("\n\nTYPE all\n");
	// printf("\n'%%s%%d%%p%%%%%%S%%D%%i%%o%%O%%u%%U%%x%%X%%c%%C','bonjour', 42, &c, L'暖炉', LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'\\n\n\n");
	// printf("\nour %d\n", ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
	//printf("\nsys %d\n", printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
	// printf("\n");

	//printf("\n%d\n", printf("%S", L"米"));
	// printf("\n%d\n", printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	// L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	// L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L""));
	//printf("\n%d\n", printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
 
	  /*/ -922075808
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
//	ft_printf("\n");
//	ft_printf("%%\n");
//	ft_printf("%d\n", 42);
//	ft_printf("%d%d\n", 42, 41);
//	ft_printf("%d%d%d\n", 42, 43, 44);
//	ft_printf("%ld\n", 2147483647);
//	ft_printf("%lld\n", 9223372036854775807);
//	ft_printf("%x\n", 505);
//	ft_printf("%X\n", 505);
//	ft_printf("%p\n", &ft_printf);
//	ft_printf("%20.15d\n", 54321);
//	ft_printf("%-10d\n", 3);
//	ft_printf("% d\n", 3);
//	ft_printf("%+d\n", 3);
//	ft_printf("%010d\n", 1);
//	ft_printf("%hhd\n", 0);
//	ft_printf("%jd\\n", 9223372036854775807);
//	ft_printf("%zd\\n", 4294967295);
//	ft_printf("%\n");
//	ft_printf("%U\n", 4294967295);
//	ft_printf("%u\n", 4294967295);
//	ft_printf("%o\n", 40);
//	ft_printf("%%#08x\n", 42);
//	ft_printf("%x\n", 1000);
//	ft_printf("%#X\n", 1000);
//	ft_printf("%s\n", NULL);
//	ft_printf("%S\n", L"ݗݜशব");
//	ft_printf("%s%s\n", "test", "test");
//	ft_printf("%s%s%s\n", "test", "test", "test");
// %[флаги -+ #0 ][ширина][.точность][размер]тип

// %-+ #0*.*s */
	return(0);
}

