/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_p.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 16:42:04 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/03 09:34:23 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	difitcount(unsigned long nb)
{
	size_t	i;

	i = 0;
	while (nb)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

char			*ft_ltoa(unsigned long value, char *tab_hexa)
{
	char	*ret;
	int		taille;
	int		i;

	if (value == 0)
		return (ft_strdup("0"));
	taille = difitcount(value);
	ret = (char*)malloc(sizeof(char) * (taille + 1));
	i = 1;
	while (value != 0)
	{
		ret[taille - i++] = tab_hexa[value % 16];
		value /= 16;
	}
	ret[taille] = '\0';
	return (ret);
}

void			ft_convert_p(t_infos *f, unsigned long elem, int index)
{
	char	*str;
	int		len;

	str = ft_ltoa(elem, "0123456789abcdef");
	len = ft_strlen(str);
	if (index == 1 && elem == 0)
		len = len - 1;
	if (index == 0 || index == 1)
	{
		if (f->width > len)
			ft_imwidth(f, len + 2);
		ft_write_s(f, "0x", 2);
		if ((index == 1 && elem != 0) || index == 0)
			ft_write_s(f, str, len);
	}
	if (index == 2)
	{
		ft_write_s(f, "0x", 2);
		ft_write_s(f, str, len);
		if (f->width > len)
			ft_imwidth(f, len + 2);
	}
	free(str);
	str = NULL;
}
