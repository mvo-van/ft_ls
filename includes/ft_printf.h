/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 06:55:23 by mvo-van-          #+#    #+#             */
/*   Updated: 2019/04/13 00:44:42 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

# define FLAG_ZEROPAD   	(1U << 0U)
# define FLAG_LEFT      	(1U << 1U)
# define FLAG_PLUS      	(1U << 2U)
# define FLAG_SPACE     	(1U << 3U)
# define FLAG_HASH      	(1U << 4U)
# define FLAG_CHAR      	(1U << 5U)
# define FLAG_SHORT     	(1U << 6U)
# define FLAG_LONG      	(1U << 7U)
# define FLAG_LONGLONG  	(1U << 8U)
# define FLAG_PRECISION 	(1U << 9U)
# define FLAG_UPPERCASE 	(1U << 10U)
# define FLAG_WILD			(1U << 11U)
# define FLAG_LONGFLOAT 	(1U << 12U)
# define IS_DIGIT(c) 		((unsigned int) ((c - '0') < 10))
# define VALID_SPEFLAG 		" CcSsplhjlzbDdioOuUxXfF.0+*#-%"
# define VALID_NBOP			"bDdioOuUxXfF"
# define BUFFER_SIZE 		64

typedef	struct		s_lst_str
{
	char				c;
	struct s_lst_str	*next;
}					t_lst_str;

typedef struct		s_lst_args
{
	char			buf[BUFFER_SIZE];
	char			str[5];
	char			*ptr;
	unsigned int	flag;
	int				width;
	int				precision;
	int				base;
	int				len;
	int				swi;
	int				count_print;
	int				buflen;
	int				negatif;
	int				intlen;
	int				i;
	int				j;
	int				err;
	long double		plus;
	int				s_precision;
	long double		save;
	long double		value;
	unsigned int	temp;
	int				padf;
	int				tmp;
	t_lst_str		*first;
	t_lst_str		*list;
}					t_lst_args;

int					ft_wlen(wchar_t *str, t_lst_args *spe);
void				ft_printpad(t_lst_args *spe);
int					nanv(t_lst_args *spe, long double value);
void				ft_buffzerohach(t_lst_args *spe);
int					ft_testmaxw(const char **format, t_lst_args *spe
		, wchar_t wc);
void				ft_rpading(t_lst_args *spe);
int					ft_nulstring(const char **format, t_lst_args *spe
		, char *ptr);
int					ft_string(const char **format, t_lst_args *spe
		, va_list va);
int					ft_wstring(t_lst_args *spe, wchar_t *ptr);
int					ft_pawchar(wchar_t c, t_lst_args *spe, const char **format);
void				ptrnvalue(t_lst_args *spe);
int					ft_pastring(const char **format, t_lst_args *spe
		, char *ptr);
int					ft_putw(wchar_t *w, t_lst_args *spe);
int					ft_loopcheckvalidw(wchar_t *w, t_lst_args *spe);
int					ft_loopwlen(wchar_t *str, t_lst_args *spe);
void				ft_loopwlen2(wchar_t *str, t_lst_args *spe);
int					match_char(char *str, char c);
void				get_base(const char **format, t_lst_args *spe, va_list va);
int					get_precision(const char **format, t_lst_args *spe
		, va_list va);
void				get_wild(const char **format, t_lst_args *spe, va_list va);
void				ft_buffzerop(t_lst_args *spe);
int					ft_pwchar(wchar_t c, t_lst_args *spe);
void				ft_printwchar(char *str, t_lst_args *spe);
int					ft_padwchar(t_lst_args *spe, const char **format);
void				ft_buffhash(t_lst_args *spe);
void				ft_getsign(t_lst_args *spe);
void				ft_printbuff(t_lst_args *spe);
int					ft_nbrlong(t_lst_args *spe, va_list va);
int					ft_get_flags(const char **format, t_lst_args *spe
		, va_list va);
int					get_speflag(const char **format, t_lst_args *spe);
int					ft_print_char(const char **format, t_lst_args *spe
		, va_list va);
int					ft_long_long(t_lst_args *spe, unsigned long long value);
int					ft_nbr(const char **format, t_lst_args *spe, va_list va);
int					ft_printf(const char *format, ...);
int					ft_float(t_lst_args *spe, va_list va);
int					ft_buff_format(t_lst_args *spe);
t_lst_str			*ft_new_lststr(char c);
void				ft_free_lst(t_lst_args *spe);
void				ft_print_lst(t_lst_args *spe);
void				ft_lst_link(const char format, t_lst_args *spe);
#endif
