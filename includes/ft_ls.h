/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/25 17:24:20 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_printf.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../includes/ft_printf.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

# define FLAG_L		1
# define FLAG_REC	2
# define FLAG_A		4
# define FLAG_REV	8
# define FLAG_T		16
# define MODE		"rwxrwxrwx"
# define TYPE 		"splcbd-"

typedef struct	s_file
{
	char				*name;
	char				type;
	int					i_mode;
	char				*mode;
	int					link;
	char				*prop;
	char				*group;
	int					taille;
	int					i_time;
	char				*time;
	struct s_file		*sous;
	struct s_file		*sup;
	struct s_file		*inf;
	
}				t_file;

#endif