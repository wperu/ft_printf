/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 10:55:42 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 18:36:52 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_checkflag(char *str, t_infos *f)
{
	int i;

	i = 1;
	while (str[i] == '-' || str[i] == '0' || str[i] == '*' || str[i] == '.')
	{
		if (str[i] == '-')
			f->flagzero = 1;
		if (str[i] == '0' && f->flagtiret == 0)
			f->flagtiret = 1;
		if (str[i] == '*')
			f->flagstar = 1;
		if (str[i] == '.')
			f->flagpoint = 1;
		i++;
	}
	f->lchamp = ft_atoi(str + i);
	while(str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] <= 'z' && str[i] >= 'A')
	{
		f->convt = str[i];
		i++;
	}
	printf("i == %d\n",i);
	return (i);
}

void ft_initstruct(t_infos *f)
{
	f->flagzero = 0;
	f->flagtiret = 0;
	f->flagpoint = 0;
	f->flagstar = 0;
	f->lchamp = 0;
	f->convt = '0';
	f->ret = 0;
}
