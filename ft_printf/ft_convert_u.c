/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_u.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 15:06:58 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 15:58:00 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_u(t_infos *f, unsigned int elem, int index)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	str = ft_utoa(elem);
	len = ft_strlen(str);
	if (f->flagprec == 1 && f->prec == 0 && elem == 0)
		len = 0;
	ft_convert_nbr(f, str + i, index, len);
	free(str);
	str = NULL;
}

void	ft_imprec(t_infos *f, int len)
{
	int i;

	i = f->prec - len;
	while (i > 0)
	{
		ft_write_cpt(f, '0');
		i--;
	}
}

void	ft_convert_nbr(t_infos *f, char *str, int index, int len)
{
	if (index == 5)
		index = 1;
	if (index == 1)
		f->flagzero = 0;
	if (f->flagtiret == 0 && f->prec <= len && f->width > len)
		ft_imwidth(f, len);
	if ((index == 1 || index == 3) && f->prec >= len)
	{
		if (index == 1)
			ft_imwidth(f, f->prec);
		f->flagzero = 1;
		ft_imprec(f, len);
	}
	if (len > 0)
		ft_write_s(f, str, len);
	if (index == 2 && f->width > len)
		ft_imwidth(f, len);
	if (index == 3 && f->width > len && f->width > f->prec)
	{
		f->flagzero = 0;
		if (f->prec <= len)
			ft_imwidth(f, len);
		else
			ft_imwidth(f, f->prec);
	}
}
