/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_1.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:31:51 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 04:51:22 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(t_infos *f)
{
	f->index = ft_index_bin(f);
	if (f->convt == 's')
		convert_string(f, va_arg(f->arglist, char*), f->index);
	if (f->convt == '%')
		convert_char(f, 37, f->index);
	if (f->convt == 'c')
		convert_char(f, (char)va_arg(f->arglist, int), f->index);
	if (f->convt == 'd' || f->convt == 'i')
		ft_convert_di(f, va_arg(f->arglist, int), f->index);
	if (f->convt == 'u')
		ft_convert_u(f, va_arg(f->arglist, unsigned long), f->index);
	if (f->convt == 'x' || f->convt == 'X')
		ft_convert_x(f, (unsigned long)va_arg(f->arglist, int), f->index);
	if (f->convt == 'p')
		ft_convert_p(f, va_arg(f->arglist, unsigned long), f->index);
}

int		ft_index_bin(t_infos *f)
{
	int tab[3];
	int index;

	tab[0] = f->flagzero;
	tab[1] = f->flagtiret;
	tab[2] = f->flagprec;
	index = tab[0] * 4 + tab[1] * 2 + tab[2];
	return (index);
}
