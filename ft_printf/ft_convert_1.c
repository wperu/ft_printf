/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_1.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:31:51 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 17:55:11 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void convert(char *str, t_info f,int index)
{
	if (f->convert == 's')
		convert_string(index,va_arg(char*));
	if (f->convert == 'c')
		convert_char(index,f,va_arg(char));
	if (f->convert == 'd' || f->convert == 'i');
		convert_int(index,f,va_arg(int);
	if (f->convert == 'u')
		convert_uint(index,f,va_arg(unsigned int));
	if (f->convert == 'x')
		convert_hexa(index,f,va_arg(long);
	if (f->convert == 'X')
		convert_thexa(index,f,va_arg(long);
	if (f->convert == 'p')
		convert_ptr(index,f,va_arg(*));
}

void ft_write_cpt(t_info f, char c)
{
	write(1, &c, 1);
	f->ret++;
}

void	ft_write_s(t_info f, char* str, int max)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		ft_write_cpt(f, str[i]);
		i++;
	}
}

void convert_string(int index, t_info f, char *str)
{
	if(index == 0)
		ft_write_s(f, str);
	if(index == 1)
	{
		while (f->lchamp-- > 0)
			ft_write_cpt(f, ' ');
		ft_write_s(f, str, ft_strlen(str);
	}
	if(index = 2)
	{
		if(va_arg(int) > ft_strlen(str))
		{
			while(i++ > int - ft_strlen(str))
					ft_write_cpt(f, ' ');
		}
		ft_write_s(f, str, ft_strlen(str));
	}
//	if(index == 3) pas realisable
	if(index == 4 || index ==  5)
		ft_write_s(f, str, f->lchamp);
	if(index == 6 || index == 7)
	{
		if(va_arg(int) > ft_strlen(str))
		{
			while(i++ > int - ft_strlen(str))
					ft_write_cpt(f, ' ');
		}
	}	
}
int ft_index_bin(t_info f)
{
	int tab[5];
	int index

	tab[5] = {0};
	tab[0] = f->flagzero;
	tab[1] = f->flagtiret;
	tab[2] = f->flagpoint;
	tab[3] = f->flagstar;
	if (f->lchamp > 0)
		tab[4] = 1;
	index = tab[0] * 16 + tab[1] * 8 + tab[2] * 4 + tab[3] * 2 + tab[4];
	return (index);
}
