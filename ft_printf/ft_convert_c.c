/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_c.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 08:34:11 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 11:28:02 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_char(t_infos *f, char c, int index)
{
	if (index == 0 || index == 1 || index == 5 || index == 4)
	{
		if (f->width > 1)
			ft_imwidth(f, 1);
		ft_write_cpt(f, c);
	}
	if (index == 2 || index == 3)
	{
		ft_write_cpt(f, c);
		if (f->width > 1)
			ft_imwidth(f, 1);
	}
}
