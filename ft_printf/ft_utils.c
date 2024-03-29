/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utils.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 10:55:42 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 16:15:29 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_checkflag(char *str, t_infos *f)
{
	int i;

	i = 1;
	while (str[i] == '-' || str[i] == '*' || str[i] == '.'
			|| (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			f->flagtiret = 1;
		if (str[i] == '0')
			f->flagzero = 1;
		if (str[i] == '*' && f->flagprec != 1)
			f->width = va_arg(f->arglist, int);
		if (str[i] > '0' && str[i] <= '9')
		{
			f->width = ft_atoi(str + i);
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			i--;
		}
		if (str[i] == '.')
			i = i + ft_flagprec(str + i, f);
		i++;
	}
	return (i + ft_checkflag2(str + i, f));
}

void	ft_initstruct(t_infos *f)
{
	f->flagzero = 0;
	f->flagtiret = 0;
	f->flagprec = 0;
	f->flagwidth = 1;
	f->convt = '0';
	f->width = 0;
	f->prec = 0;
	f->index = 0;
}

void	ft_imwidth(t_infos *f, int len)
{
	f->width = f->width - len;
	if (f->flagzero == 1)
	{
		while (f->width > 0)
		{
			ft_write_cpt(f, '0');
			f->width--;
		}
	}
	else
	{
		while (f->width > 0)
		{
			ft_write_cpt(f, ' ');
			f->width--;
		}
	}
}

int		ft_checkflag2(char *str, t_infos *f)
{
	int	i;

	i = 0;
	if (ft_strchr("cdsxXpui%", str[i]) == 1)
		f->convt = str[i++];
	if (f->width < 0)
	{
		f->flagtiret = 1;
		f->width = f->width * -1;
	}
	if (f->flagzero == 1 && f->flagtiret == 1)
		f->flagzero = 0;
	return (i);
}

int		ft_flagprec(char *str, t_infos *f)
{
	int i;

	i = 0;
	f->flagprec = 1;
	if (str[i + 1] == '*')
	{
		f->prec = va_arg(f->arglist, int);
		i++;
	}
	else
	{
		i++;
		f->prec = ft_atoi(str + i);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		i--;
	}
	if (f->prec < 0)
	{
		f->prec = 0;
		f->flagprec = 0;
	}
	return (i);
}
