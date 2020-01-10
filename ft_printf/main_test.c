/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_test.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/13 16:51:57 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 09:13:40 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include<stdio.h>
#include "ft_printf.h"

int main()
{
//	char c = 'l';
//	char *s = "";
	char c ='\0';
//	float  a = 12.356;
//	char *s = "coucou";
//	printf("le message de s est %s\n",NULL);
//	ft_printf("le message de s est %s\n",NULL);
	printf("vrai le message de s est %-0*.2c lol \n",4,c);
	ft_printf("faux le message de s est %-0*.2c lol \n",4,c);
//	printf("le message de c est %05s\n",s);
//	printf("le message de c est %-s\n",s);
//	printf("le message de c est %-5s\n",s);
//	printf("le message de c est %-05s\n",s);
//	printf("le message de c est %.*s\n",s);*/
//	printf("le message de c est %12s\n",s);
	return(0);
}
