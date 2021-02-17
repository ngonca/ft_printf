/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musoufi <musoufi@student.le-101.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:26:57 by amonteli          #+#    #+#             */
/*   Updated: 2020/03/04 13:25:04 by musoufi          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	printf("__________________________________________________________________\n");
	printf("\t\t\t\t1. - %%s\n");

	ft_printf("[%s]", "Salut");
	printf("\n");
	printf("[%s]", "Salut");

	printf("\n");
	printf("\n");

	ft_printf("[%15s]", "Salut");
	printf("\n");
	printf("[%15s]", "Salut");

	printf("\n");
	printf("\n");

	ft_printf("[%20.3s]", "Salut");
	printf("\n");
	printf("[%20.3s]", "Salut");

	printf("\n");
	printf("\n");

	ft_printf("[%20.10s]", "Salut");
	printf("\n");
	printf("[%20.10s]", "Salut");

	printf("\n");
	printf("\n");

	ft_printf("[%20.10s]", NULL);
	printf("\n");
	printf("[%20.10s]", NULL);

	printf("\n");
	printf("\n");

	ft_printf("[%.4s]", NULL);
	printf("\n");
	printf("[%.4s]", NULL);

	printf("\n");
	printf("\n");

	ft_printf("[%-5.*s]", 2, "minused");
	printf("\n");
	printf("[%-5.*s]", 2, "minused");

	printf("\n");
	printf("\n");

	ft_printf("[%-*.*s]", 5, 2, "salut");
	printf("\n");
	printf("[%-*.*s]", 5, 2, "salut");

	printf("\n");
	printf("\n");

	ft_printf("[%*s]", -15, "minused");
	printf("\n");
	printf("[%*s]", -15, "minused");

	printf("\n");
	printf("\n");

	ft_printf("[%*s]", -5, "minused");
	printf("\n");
	printf("[%*s]", -5, "minused");

	printf("\n");
	printf("\n");

	ft_printf("[%.*s]", -15, "nega-tive");
	printf("\n");
	printf("[%.*s]", -15, "nega-tive");

	printf("\n");
	printf("\n");

	ft_printf("[%.*s]", -0, "pas vu");
	printf("\n");
	printf("[%.*s]", -0, "pas vu");

	printf("\n");
	printf("\n");

	ft_printf("|%20s|\n", "zwTJwkwl8dQ0pNVtnhzRlRXP27Pn6vyNDQXylDE97llkb6JMRQtPHW");
	printf("\n");
	printf("|%20s|\n", "zwTJwkwl8dQ0pNVtnhzRlRXP27Pn6vyNDQXylDE97llkb6JMRQtPHW");

	printf("\n");
	printf("\n");

	ft_printf("|%20s|\n", "fnpQahfk7LxmxCK7");
	printf("\n");
	printf("|%20s|\n", "fnpQahfk7LxmxCK7");

	printf("\n");
	printf("\n");

	ft_printf("[%*.*s]", -5, 0, "Hello");
	printf("\n");
	printf("[%*.*s]", -5, 0, "Hello");

	printf("\n");
	printf("\n");

	ft_printf("[%*s]", -4, "???e?");
	printf("\n");
	printf("[%*s]", -4, "???e?");

	printf("\n");
	printf("\n");

	ft_printf("[%.*s]", -3, "Hello");
	printf("\n");
	printf("[%.*s]", -3, "Hello");

	printf("\n");
	printf("\n");

	ft_printf("[%.s]", "42");
	printf("\n");
	printf("[%.s]", "42");

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t1.5 - %%s mixed\n");

	ft_printf("[%-*.*s] [%.2s] [%20.3s] [%-10.5s] [%*s]", 5, 2, "salut", NULL, "encore", "toi", -4, "?????");
	printf("\n");
	printf("[%-*.*s] [%.2s] [%20.3s] [%-10.5s] [%*s]", 5, 2, "salut", NULL, "encore", "toi", -4, "?????");

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t3 - %%c\n");

	ft_printf("[%c]", 'a');
	printf("\n");
	printf("[%c]", 'a');

	printf("\n");
	printf("\n");

	ft_printf("[%-5c]", 'z');
	printf("\n");
	printf("[%-5c]", 'z');

	printf("\n");
	printf("\n");

	ft_printf("[%5c]", 'c');
	printf("\n");
	printf("[%5c]", 'c');

	printf("\n");
	printf("\n");

	ft_printf("[%c]", '\0');
	printf("\n");
	printf("[%c]", '\0');

	printf("\n");
	printf("\n");

	ft_printf("[%c]", '\t');
	printf("\n");
	printf("[%c]", '\t');

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t4 - %%%%\n");

	ft_printf("[%% salut]");
	printf("\n");
	printf("[%% salut]");

	printf("\n");
	printf("\n");

	ft_printf("[%%]");
	printf("\n");
	printf("[%%]");

	printf("\n");
	printf("\n");

	ft_printf("[%% %-%]");
	printf("\n");
	printf("[%% %-%]");

	printf("\n");
	printf("\n");

	ft_printf("[%10%]");
	printf("\n");
	printf("[%10%]");

	printf("\n");
	printf("\n");

	ft_printf("[%-10%]");
	printf("\n");
	printf("[%-10%]");

	printf("\n");
	printf("\n");

	ft_printf("[%.%]");
	printf("\n");
	printf("[%.%]");

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t%%d\n");

	ft_printf("[%d]", 0);
	printf("\n");
	printf("[%d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%d]", -0);
	printf("\n");
	printf("[%d]", -0);

	printf("\n");
	printf("\n");

	ft_printf("[%d]", 1);
	printf("\n");
	printf("[%d]", 1);

	printf("\n");
	printf("\n");

	ft_printf("[%d]", -1);
	printf("\n");
	printf("[%d]", -1);

	printf("\n");
	printf("\n");

	ft_printf("[%7d]", 250);
	printf("\n");
	printf("[%7d]", 250);

	printf("\n");
	printf("\n");

	ft_printf("[%-7d]minused", 251);
	printf("\n");
	printf("[%-7d]minused", 251);

	printf("\n");
	printf("\n");

	ft_printf("[%-.7d]minused", 251);
	printf("\n");
	printf("[%-.7d]minused", 251);

	printf("\n");
	printf("\n");

	ft_printf("[%.5d]", 500);
	printf("\n");
	printf("[%.5d]", 500);

	printf("\n");
	printf("\n");

	ft_printf("[%.1d]", 500);
	printf("\n");
	printf("[%.1d]", 500);

	printf("\n");
	printf("\n");

	ft_printf("[%-.5d]", 1000);
	printf("\n");
	printf("[%-.5d]", 1000);

	printf("\n");
	printf("\n");

	ft_printf("[%0.54d]", 430);
	printf("\n");
	printf("[%0.54d]", 430);

	printf("\n");
	printf("\n");

	ft_printf("[%d]", 2147483647 + 1);
	printf("\n");
	printf("[%d]", 2147483647 + 1);

	printf("\n");
	printf("\n");

	ft_printf("[%0.54d]", -27627);
	printf("\n");
	printf("[%0.54d]", -27627);

	printf("\n");
	printf("\n");

	ft_printf("[%54.0d]", -644927);
	printf("\n");
	printf("[%54.0d]", -644927);

	printf("\n");
	printf("\n");

	ft_printf("precision[%.*d]", 10, -123);
	printf("\n");
	printf("precision[%.*d]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("width[%*d]", 10, -123);
	printf("\n");
	printf("width[%*d]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("twice[%*.5d]", 10, -123);
	printf("\n");
	printf("twice[%*.5d]", 10, -123);

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t%%d - MINUSED\n");

	ft_printf("precision[%-.*d]", 10, -123);
	printf("\n");
	printf("precision[%-.*d]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("width[%-*d]", 10, -123);
	printf("\n");
	printf("width[%-*d]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("[%-9.0d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%-9.0d]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("twice[%----*.5d]", 10, -123);
	printf("\n");
	printf("twice[%----*.5d]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("-17.10d[%-17.10d]", -1700000);
	printf("\n");
	printf("-17.10d[%-17.10d]", -1700000);

	printf("\n");
	printf("\n");

	ft_printf("-17.10d[%-17.10d]", INT32_MIN);
	printf("\n");
	printf("-17.10d[%-17.10d]", INT32_MIN);

	printf("\n");
	printf("\n");

	ft_printf("[%-1.0d]", 0);
	printf("\n");
	printf("[%-1.0d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%-2.0d]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%-2.0d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%-3.0d]", -1);
	dprintf(1, "\n");
	dprintf(1, "[%-3.0d]", -1);

	printf("\n");
	printf("\n");

	ft_printf("1[%-1.0d]", -1);
	dprintf(1, "\n");
	dprintf(1, "1[%-1.0d]", -1);

	printf("\n");
	printf("\n");

	ft_printf("[%-10.2d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%-10.2d]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%-11.2d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%-11.2d]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%-11.0d]", 10000);
	dprintf(1, "\n");
	dprintf(1,"[%-11.0d]", 10000);

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t%%d\n");

	ft_printf("precision[%.*d]", 10, -123);
	printf("\n");
	printf("precision[%.*d]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("width[%*d]", 10, -123);
	printf("\n");
	printf("width[%*d]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("[%9.0d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%9.0d]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("twice[%*.5d]", 10, -123);
	printf("\n");
	printf("twice[%*.5d]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("-17.10d[%17.10d]", -1700000);
	printf("\n");
	printf("-17.10d[%17.10d]", -1700000);

	printf("\n");
	printf("\n");

	ft_printf("-17.10d[%17.10d]", INT32_MIN);
	printf("\n");
	printf("-17.10d[%17.10d]", INT32_MIN);

	printf("\n");
	printf("\n");

	ft_printf("[%1.0d]", 0);
	printf("\n");
	printf("[%1.0d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%2.0d]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%2.0d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%3.0d]", -1);
	dprintf(1, "\n");
	dprintf(1, "[%3.0d]", -1);

	printf("\n");
	printf("\n");

	ft_printf("1[%1.0d]", -1);
	dprintf(1, "\n");
	dprintf(1, "1[%1.0d]", -1);

	printf("\n");
	printf("\n");

	ft_printf("[%10.2d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%10.2d]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%11.2d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%11.2d]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%11.0d]", 10000);
	dprintf(1, "\n");
	dprintf(1,"[%11.0d]", 10000);

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t%%d - 0\n");

	ft_printf("[%02d]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%02d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%010d]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%010d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%03d]", -1);
	dprintf(1, "\n");
	dprintf(1,"[%03d]", -1);

	printf("\n");
	printf("\n");

	ft_printf("[%05d]", -1);
	dprintf(1, "\n");
	dprintf(1,"[%05d]", -1);

	printf("\n");
	printf("\n");

	ft_printf("[%011d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%011d]", INT32_MAX);

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t%%d - 0.\n");

	ft_printf("[%02.1d]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%02.1d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%010.1d]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%010.1d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%010.2d]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%010.2d]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%03.0d]", -1);
	dprintf(1, "\n");
	dprintf(1,"[%03.0d]", -1);

	printf("\n");
	printf("\n");

	ft_printf("[%03.1d]", -1);
	dprintf(1, "\n");
	dprintf(1,"[%03.1d]", -1);

	printf("\n");
	printf("\n");

	ft_printf("[%011.0d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%011.0d]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%011.1d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%011.1d]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%011.2d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%011.2d]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%011.10d]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%011.10d]", INT32_MAX);

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t%%p\n");

	ft_printf("[%p]", (void *)32);
	dprintf(1, "\n");
	dprintf(1,"[%p]", (void *)32);

	printf("\n");
	printf("\n");

	ft_printf("[%p]", (void *)-1);
	dprintf(1, "\n");
	dprintf(1,"[%p]", (void *)-1);

	printf("\n");
	printf("\n");

	ft_printf("[%p]", (void *)1000);
	dprintf(1, "\n");
	dprintf(1,"[%p]", (void *)1000);

	printf("\n");
	printf("\n");

	ft_printf("[%p]", (void *)ULONG_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%p]", (void *)ULONG_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%p]", (void *)32);
	dprintf(1, "\n");
	dprintf(1,"[%p]", (void *)32);

	printf("\n");
	printf("\n");

	ft_printf("[%5p]", (void *)32);
	dprintf(1, "\n");
	dprintf(1,"[%5p]", (void *)32);

	printf("\n");
	printf("\n");

	ft_printf("[%4p]", (void *)32);
	dprintf(1, "\n");
	dprintf(1,"[%4p]", (void *)32);

	printf("\n");
	printf("\n");

	ft_printf("[%-5p]", (void *)32);
	dprintf(1, "\n");
	dprintf(1,"[%-5p]", (void *)32);

	printf("\n");
	printf("\n");

	ft_printf("[%1p]", (void *)42);
	dprintf(1, "\n");
	dprintf(1,"[%1p]", (void *)42);

	printf("\n");
	printf("\n");

	ft_printf("[%.p]", (void *)0);
	dprintf(1, "\n");
	dprintf(1,"[%.p]", (void *)0);

	printf("\n");
	printf("\n");

	ft_printf("[%.p]", (void *)70);
	dprintf(1, "\n");
	dprintf(1,"[%.p]", (void *)70);

	printf("\n");
	printf("\n");

	ft_printf("[%9.p]", (void *)0);
	dprintf(1, "\n");
	dprintf(1,"[%9.p]", (void *)0);

	printf("\n");
	printf("\n");

	ft_printf("[%8.p]", (void *)6969);
	dprintf(1, "\n");
	dprintf(1,"[%8.p]", (void *)6969);

	printf("\n");
	printf("\n");

	ft_printf("[%-8.p]", (void *)6969);
	dprintf(1, "\n");
	dprintf(1,"[%-8.p]", (void *)6969);

	printf("\n");
	printf("\n");

	ft_printf("[%-9.p]", (void *)0);
	dprintf(1, "\n");
	dprintf(1,"[%-9.p]", (void *)0);

	printf("\n");

	printf("__________________________________________________________________\n");
	printf("\t\t\t\t%%x\n");

	ft_printf("[%x]", 1694);
	dprintf(1, "\n");
	dprintf(1,"[%x]", 1694);

	printf("\n");
	printf("\n");

	ft_printf("[%X]", 1694);
	dprintf(1, "\n");
	dprintf(1,"[%X]", 1694);

	printf("\n");
	printf("\n");

	ft_printf("precision[%.*x]", 10, -123);
	printf("\n");
	printf("precision[%.*x]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("width[%*x]", 10, -123);
	printf("\n");
	printf("width[%*x]", 10, -123);

	printf("\n");
	printf("\n");

	ft_printf("2.x[%0.2x]", 0);
	dprintf(1, "\n");
	dprintf(1,"2.x[%0.2x]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%2.1x]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%2.1x]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%010.1x]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%010.1x]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%010.2x]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%010.2x]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%03.0x]", -1);
	dprintf(1, "\n");
	dprintf(1,"[%03.0x]", -1);

	printf("\n");
	printf("\n");

	ft_printf("[%03.1x]", -1);
	dprintf(1, "\n");
	dprintf(1,"[%03.1x]", -1);

	printf("\n");
	printf("\n");

	ft_printf("[%11.0x]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%11.0x]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%11.1x]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%11.1x]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%11.02x]", INT32_MAX);
	dprintf(1, "\n");
	dprintf(1,"[%11.02x]", INT32_MAX);

	printf("\n");
	printf("\n");

	ft_printf("[%-3.0x]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%-3.0x]", 0);

	printf("\n");
	printf("\n");

	ft_printf("[%-10.0x]", 0);
	dprintf(1, "\n");
	dprintf(1,"[%-10.0x]", 0);

	printf("\n");
	printf("\n");

	ft_printf("|%.046d|", 45);
	dprintf(1, "\n");
	dprintf(1,"|%.046d|", 45);

	printf("\n");
	printf("\n");

	ft_printf("|%.015s|", "bonjour");
	dprintf(1, "\n");
	dprintf(1,"|%.015s|", "bonjour");

	printf("\n");
}