/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_1.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:31:51 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 09:07:40 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_convert(t_infos *f,int index)
{
	if (f->convt == 's')
		convert_string(f,va_arg(f->arglist,char*), index);
	if (f->convt == 'c')
		convert_char(f,(char)va_arg(f->arglist,int), index);
	/*	if (f->convert == 'd' || f->convert == 'i');
		convert_int(f,va_arg(int);
		if (f->convert == 'u')
		convert_uint(f,va_arg(unsigned int));
		if (f->convert == 'x')
		convert_hexa(f,va_arg(long);
		if (f->convert == 'X')
		convert_thexa(f,va_arg(long);
		if (f->convert == 'p')
		convert_ptr(f,va_arg(void*));*/
		
}

int ft_index_bin(t_infos *f)
{
	int tab[3];
	int index;

	tab[0] = f->flagzero;
	tab[1] = f->flagtiret;
	tab[2] = f->flagprec;
	//	tab[3] = f->flagwidth;
	index = tab[0] * 4 + tab[1] * 2 + tab[2] ;
	return (index);
}
