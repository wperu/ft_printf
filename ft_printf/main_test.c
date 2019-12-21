/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 16:51:57 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 17:38:31 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include<stdio.h>
#include "ft_printf.h"

int main()
{
	int d = 42;
	char *s = "coucou";
	printf("le message de c est %.s\n",s);
	printf("le message de c est %*.4s\n",10,s);
	printf("le message de c est %-*s\n",10,s);
	/*printf("le message de c est %0s\n",s);
	printf("le message de c est %05s\n",s);
	printf("le message de c est %-s\n",s);
	printf("le message de c est %-5s\n",s);
	printf("le message de c est %-05s\n",s);
	printf("le message de c est %.*s\n",s);*/
	printf("le message de c est %12s\n",s);
	return(0);
}
