/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 09:53:39 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 17:02:06 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
typedef struct	s_infos
{
	int		flagzero;
	int		flagtiret;
	int		flagpoint;
	int		flagstar;
	int		lchamp;
	char	convt;
	int		ret;
	int		istar;
}				t_infos;

int		ft_printf(const char *format, ...);
int		ft_checkflag(char *str, t_infos *f);
void	ft_initstruct(t_infos *f);

#endif
