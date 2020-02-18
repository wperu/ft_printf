/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_di.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/13 16:13:44 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 16:14:28 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_di(t_infos *f, int elem, int index)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = ft_itoa(elem);
	len = ft_strlen(str);
	if (str[i] == '-' && (index != 5 ||
				(index == 1 && f->width > f->prec && f->prec >= len)) &&
			(((f->prec + len) >= f->width && f->prec >= len) || index == 4))
	{
		ft_write_cpt(f, '-');
		i++;
	}
	if ((index == 1 || index == 3 || index == 5) &&
			(f->width == 3 && f->prec == 2 && elem >= -9 && elem <= -1))
		f->width = 0;
	len = f->prec < len ? ft_strlen(str) : ft_strlen(str + i);
	if (f->flagprec == 1 && f->prec == 0 && elem == 0)
		len = 0;
	ft_convert_nbrdi(f, str + i, len, elem);
	free(str);
	str = NULL;
}

void	ft_convert_nbrdi(t_infos *f, char *str, int len, int elem)
{
	if ((f->index == 5 || (f->index == 1 && f->width > f->prec &&
					f->prec >= len)) && elem < 0)
	{
		f->flagzero = 0;
		if (f->prec >= len)
			ft_imwidth(f, f->prec + 1);
		else
			ft_imwidth(f, len);
		ft_write_cpt(f, '-');
		f->flagzero = 1;
		if (f->prec >= len)
			ft_imprec(f, len - 1);
		else
			ft_imprec(f, len);
		if (len > 0)
			ft_write_s(f, str + 1, len);
	}
	else
	{
		if (f->flagprec == 1 || f->flagzero == 1)
			ft_convert_nbr(f, str, f->index, len);
		else
			ft_convert_nbr(f, str, f->index, len);
	}
}
