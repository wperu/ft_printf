/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_s.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 05:55:10 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/26 01:55:55 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write_cpt(t_infos *f, char c)
{
	write(1, &c, 1);
	f->ret++;
}

void		ft_write_s(t_infos *f, char *str, int max)
{
	int i;

	i = 0;
	while (i < max && str[i] != '\0')
	{
		ft_write_cpt(f, str[i]);
		i++;
	}
}

static void	ft_help(t_infos *f, char *str)
{
	ft_write_s(f, str, f->prec);
	ft_imwidth(f, f->prec);
}

void		convert_string(t_infos *f, char *str, int index)
{
	int		len;
	char	*lol;

	lol = (!str) ? ft_strdup("(null)") : ft_strdup(str);
	len = ft_strlen(lol);
	if (index == 0 || (index == 1 && f->prec >= len))
	{
		ft_imwidth(f, len);
		ft_write_s(f, lol, len);
	}
	if (index == 1 && f->prec < len)
	{
		ft_imwidth(f, f->prec);
		ft_write_s(f, lol, f->prec);
	}
	if (index == 2 || (index == 3 && f->prec > len))
	{
		ft_write_s(f, lol, len);
		ft_imwidth(f, len);
	}
	if (index == 3 && f->prec <= len)
		ft_help(f, lol);
	free(lol);
	lol = NULL;
}
