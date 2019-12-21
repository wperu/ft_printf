/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 09:46:31 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 17:06:43 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	int 	i;
	t_infos	*f;
	int		index;


	i = 0;
	ft_initstruct(f);

	va_start(ap,format);
	while(format[i])
	{
		if(format[i] == '%')
		{
			i = i + ft_checkflag((char*)format + i,f);
			index = ft_index_bin(f);
			ft_convert(format, f);
		}
		ft_write_cpt(f, format[i]);
		i++;
	}
	printf("flagzero = %d\n",f->flagzero);
	printf("flagtiret = %d\n",f->flagtiret);
	printf("flagpoint = %d\n",f->flagpoint);
	printf("flagstar = %d\n",f->flagstar);
	printf("convt = %c\n",f->convt);
	printf("lchamp = %d\n",f->lchamp);
	va_end(ap);
	puts("");
	return (f->ret);
}
