/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvo-van- <mvo-van-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:50:39 by mvo-van-          #+#    #+#             */
/*   Updated: 2020/02/26 17:00:16 by mvo-van-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_mode(int mode)
{
	char	*str;
	int	i;
	int j;

	i = 0;
	j = 8;
	str = ft_strnew(9);
	if (str == NULL)
		return (NULL);
	while (i < 9)
	{
		if (mode & (1 << i))
			str[j] = MODE[j];
		else
			str[j] = '-';
		j--;
		i++;
	}
	return (str);
}

char	ft_get_type(int mode)
{
	char	c;
	int		i;

	i = 0;
	while (i < 6 && !(mode & (1 << (i + 9))))
		i++;
	c = TYPE[i];
	return (c);
}

int		ft_erreur_option(int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac && av[i][0] == '-')
	{
		j = 0;
		while (av[i][++j])
		{
			if (av[i][j] != 'l' && av[i][j] != 'R' && av[i][j] != 'a' &&
				av[i][j] != 'r' && av[i][j] != 't')
			{
				ft_printf("ft_ls: illegal option -- %c\n", av[i][j]);
				ft_printf("usage: ft_ls [-Ralrt] [file ...]\n");
				return (0);
			}
		}
	}
	return (0);
}

int		ft_parsing_op(int ac, char **av, int *option)
{
	int		i;
	int		j;

	*option = 0;
	i = 0;
	while (++i < ac && av[i][0] == '-')
	{
		j = 0;
		while (av[i][++j])
		{
			if (av[i][j] == 'l')
				*option |= FLAG_L;
			else if (av[i][j] == 'R')
				*option |= FLAG_REC;
			else if (av[i][j] == 'a')
				*option |= FLAG_A;
			else if (av[i][j] == 'r')
				*option |= FLAG_REV;
			else if (av[i][j] == 't')
				*option |= FLAG_T;
			else
				return (ft_erreur_option(ac, av));
		}
	}
	return (i);
}

t_file	*ft_get_stat(char *file)
{
	struct stat		dir;
	struct passwd	*pw;
	struct group	*gp;
	t_file			*lst;

	if (!(lst = (t_file*)malloc(sizeof(t_file) * 1)))
		return (NULL);
	lst->name = file;
	if (stat(file, &dir) == 0)
	{
		lst->i_mode = dir.st_mode;
		lst->mode = ft_get_mode(dir.st_mode);
		lst->type = ft_get_type(dir.st_mode);
		lst->link = (int)dir.st_nlink;
		pw = getpwuid(dir.st_uid);
		gp = getgrgid(dir.st_gid);
		lst->prop = pw->pw_name;
		lst->group = gp->gr_name;
		lst->taille = (int)dir.st_size;
		lst->i_time = dir.st_mtime;
		lst->time = ft_strsub(ctime(&dir.st_mtime), 4, 15);
		lst->sup = NULL;
		lst->inf = NULL;
	}
	else
	{
		lst->type = 'E';
		lst->sup = NULL;
		lst->inf = NULL;
	}
	return (lst);
}

void	ft_arbre(t_file **lst, t_file *ptr, int flag)
{
	t_file	*parcour;
	int		i;
	int		cmp;

	i = 0;
	parcour = *lst;
	if ((*lst) == NULL)
		*lst = ptr;
	if (parcour && flag & FLAG_T)
	{
		while (parcour && i == 0)
			if (parcour->i_time > ptr->i_time && parcour->sup)
				parcour = parcour->sup;
			else if (parcour->i_time > ptr->i_time)
			{
				parcour->sup = ptr;
				i = 1;
			}
			else if (parcour->i_time <= ptr->i_time && parcour->inf)
				parcour = parcour->inf;
			else
			{
				parcour->inf = ptr;
				i = 1;
			}
	}
	else if (parcour)
	{
		while (i == 0)
		{
			cmp = ft_strcmp(parcour->name, ptr->name);
			if (cmp < 0 && parcour->sup)
				parcour = parcour->sup;
			else if (cmp < 0)
			{
				parcour->sup = ptr;
				i = 1;
			}
			else if (cmp >= 0 && parcour->inf)
				parcour = parcour->inf;
			else
			{
				parcour->inf = ptr;
				i = 1;
			}
		}
	}
}

void	ft_print_invalide(t_file *lst)
{
	if (lst && lst->inf)
		ft_print_invalide(lst->inf);
	if (lst)
		ft_printf("ls: %s: No such file or directory\n", lst->name);
	if (lst && lst->sup)
		ft_print_invalide(lst->sup);
	if (lst)
		free(lst);
}

void	ft_print_valide(t_file *lst, int option)
{
	if (!(option & FLAG_REV) && lst && lst->inf)
		ft_print_valide(lst->inf, option);
	else if ((option & FLAG_REV) && lst && lst->sup)
		ft_print_valide(lst->sup, option);
	if (lst && option & FLAG_L)
		ft_printf("%c%s %2d %s	%s %6d %s %s\n", lst->type, lst->mode, lst->link, lst->prop, lst->group, lst->taille, lst->time, lst->name);
	else if (lst)
		ft_printf("%s\n", lst->name);
	if (!(option & FLAG_REV) && lst && lst->sup)
		ft_print_valide(lst->sup, option);
	else if ((option & FLAG_REV) && lst && lst->inf)
		ft_print_valide(lst->inf, option);
	if (lst)
	{
		ft_memdel((void**)&lst->mode);
		ft_memdel((void**)&lst->time);
		free(lst);
	}
}

t_file	*ft_parsing_file(int ac, int i, int option, char **av)
{
	t_file	*lst_invalide;
	t_file	*lst;
	t_file	*ptr;
	t_file	*lst_file;

	ptr = NULL;
	lst_invalide = NULL;
	lst = NULL;
	lst_file = NULL;
	if (i == ac)
		lst = ft_get_stat(".");
	while (i < ac)
	{
		ptr = ft_get_stat(av[i]);
		if (ptr->type == 'E')
			ft_arbre(&lst_invalide, ptr, 0);
		else if (ptr->type != 'd')
			ft_arbre(&lst_file, ptr, option);
		else
			ft_arbre(&lst, ptr, option);
		i++;
	}
	ft_print_invalide(lst_invalide);
	ft_print_valide(lst_file, option);
	return (lst);
}

void	ft_get_sous_d(t_file *lst, int option)
{
	struct dirent 	*dir;
	DIR				*fd;
option = 0;
	while (lst)
	{
		fd = opendir(lst->name);
		//ft_printf("%d\n",fd);
		if (fd)
		{
			while ((dir = readdir(fd)))
			{
				if (dir->d_name[0] && dir->d_name[0]!='.')
					ft_printf("%s\n",dir->d_name);
			}
			closedir(fd);
		}
		else
		{
			ft_printf("ls: %s: Permission denied", lst->name);
		}
		
	}
}

int		main(int ac, char **av)
{
	int		option;
	t_file	*lst;
	int		i;

	if (!(i = ft_parsing_op(ac, av, &option)))
		return (0);
	lst = ft_parsing_file(ac, i, option, av);
	ft_get_sous_d(lst, option);
	//ft_print_valide(lst, option);
	return (0);
}
