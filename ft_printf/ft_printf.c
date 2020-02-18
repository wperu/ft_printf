/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 09:46:31 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/26 02:04:04 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	t_infos	*f;

	i = 0;
	f = malloc(sizeof(*f));
	if (!f)
		return (-1);
	f->ret = 0;
	va_start(f->arglist, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			ft_initstruct(f);
			i = i + ft_checkflag((char*)format + i, f);
			ft_convert(f);
		}
		if (format[i] != '\0' && format[i] != '%')
			ft_write_cpt(f, format[i++]);
	}
	va_end(f->arglist);
	i = f->ret;
	free(f);
	f = NULL;
	return (i);
}
