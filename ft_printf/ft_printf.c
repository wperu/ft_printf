/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 09:46:31 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 15:54:16 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int 	i;
	t_infos	*f;
	int		index;


	i = 0;
	f = malloc(sizeof(*f));
	if(!f)
		return(-1);
	va_start(f->arglist,format);
//	printf("taille format =%d\n", ft_strlen((char*)format));
	while(format[i])
	{
		if(format[i] == '%')
		{
			ft_initstruct(f);
			i = i + ft_checkflag((char*)format + i,f);
		//	printf("i= %d\n",i);
			index = ft_index_bin(f);
		//	printf("index = %d\n",index);
			ft_convert(f,index);
		}
	//	printf("i = %d\n",i);
		if(format[i] !='\0')
		{
			ft_write_cpt(f, format[i]);
			i++;
		}
	}
	/*
	printf("flagzero = %d\n",f->flagzero);
	printf("flagtiret = %d\n",f->flagtiret);
	printf("flagpoint = %d\n",f->flagpoint);
	printf("flagstar = %d\n",f->flagstar);
	printf("convt = %c\n",f->convt);
	printf("lchamp = %d\n",f->lchamp);*/
	va_end(f->arglist);
	i = f->ret;
	free(f);
	return (i);
}
