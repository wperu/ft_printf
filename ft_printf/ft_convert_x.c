/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_x.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 14:08:09 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/26 01:55:02 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_x(t_infos *f, unsigned long elem, int index)
{
	char	*str;
	int		len;

	str = (f->convt == 'x') ? ft_itoa_base(elem, 16, "0123456789abcdef") :
		ft_itoa_base(elem, 16, "0123456789ABCDEF");
	len = ft_strlen(str);
	if (f->flagprec == 1 && f->prec == 0 && elem == 0)
		len = 0;
	ft_convert_nbr(f, str, index, len);
	free(str);
	str = NULL;
}
