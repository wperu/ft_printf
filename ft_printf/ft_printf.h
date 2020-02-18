/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wperu <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 09:53:39 by wperu        #+#   ##    ##    #+#       */
/*   Updated: 2020/02/05 16:00:20 by wperu       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_infos
{
	int		flagzero;
	int		flagtiret;
	int		flagprec;
	int		flagwidth;
	int		ret;
	int		width;
	int		prec;
	int		index;
	char	convt;
	va_list	arglist;
}				t_infos;

int				ft_printf(const char *format,
				...) __attribute__((format(printf,1,2)));
int				ft_checkflag(char *str, t_infos *f);
int				ft_checkflag2(char *str, t_infos *f);
int				ft_flagprec(char *str, t_infos *f);
int				ft_index_bin(t_infos *f);
void			ft_initstruct(t_infos *f);
void			ft_write_cpt(t_infos *f, char c);
void			ft_write_s(t_infos *f, char *str, int max);
void			ft_convert(t_infos *f);
void			ft_convert_nbrdi(t_infos *f, char *str, int len, int elem);
void			ft_convert_nbr(t_infos *f, char *str, int index, int len);
void			convert_string(t_infos *f, char *str, int index);
void			convert_char(t_infos *f, char c, int index);
void			ft_convert_di(t_infos *f, int elem, int index);
void			ft_convert_x(t_infos *f, unsigned long elem, int index);
void			ft_convert_u(t_infos *f, unsigned int elem, int index);
void			ft_convert_p(t_infos *f, unsigned long elem, int index);
void			ft_imwidth(t_infos *f, int len);
void			ft_imprec(t_infos *f, int len);
char			*ft_ltoa(unsigned long value, char *tab_base);
#endif
