/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_s.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 05:55:10 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 05:58:50 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_write_cpt(t_infos *f, char c)
{
	write(1, &c, 1);
	f->ret++;
}

void	ft_write_s(t_infos *f, char* str, int max)
{
	int i;

	i = 0;
	while (i < max)
	{
		ft_write_cpt(f, str[i]);
		i++;
	}
}

void convert_string(t_infos *f, char *str,int index)
{
	int len;
	char *lol;
	if(!str)
		lol = ft_strdup("(null)");
	else
		lol = ft_strdup(str);
	len = ft_strlen(lol);
	printf("len = %d index == %d\n",len,index);
	if(index == 0 || index == 4)
	{
		if(f->width > len)
			ft_imwidth(f,len);
		ft_write_s(f, lol, len);
	}
	if(index == 1)
	{
		if(f->width > f->prec)
			ft_imwidth(f,f->prec);
		if(f->prec < len)
			ft_write_s(f, lol, f->prec);
		else
			ft_write_s(f,lol,len);
	}
	if(index == 2)
	{
		ft_write_s(f, lol, len);
		if(f->width > len)
			ft_imwidth(f,len);
	}
	if(index == 3 || index == 5)
	{
		if(f->width > f->prec && index == 5)
			ft_imwidth(f,f->prec);
		if(f->prec < len)
			ft_write_s(f, lol, f->prec);
		else
			ft_write_s(f,lol,len);
		if(f->width > f->prec && index == 3)
			ft_imwidth(f,f->prec);
	}
	free(lol);
	lol = NULL;
}
