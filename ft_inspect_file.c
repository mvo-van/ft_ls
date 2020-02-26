#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../includes/ft_printf.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MODE "rwxrwxrwx"
#define TYPE "splcbd-"

typedef struct s_fichier
{
	char	*name;
	char	type;
	char	*mode;
	int		link;
	char	*prop;
	char	*group;
	int		taille;
	char	*time;
}				t_fichier;

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

int		main(int ac, char **av)
{
	struct stat 	dir;
	struct passwd	*pw;
	struct group	*gp;
	t_fichier		f;

	if (ac > 1)
	{
		if (stat(av[1], &dir) == 0)
		{
			f.name = av[1];
			f.mode = ft_get_mode(dir.st_mode);
			f.type = ft_get_type(dir.st_mode);
			f.link = (int)dir.st_nlink;
			pw = getpwuid(dir.st_uid);
			gp = getgrgid(dir.st_gid);
			f.prop = pw->pw_name;
			f.group = gp->gr_name;
			f.taille = (int)dir.st_size;
			f.time = ft_strsub(ctime(&dir.st_mtime), 4, 15);
			ft_printf("%c%s %2d %s	%s %6d %s %s\n", f.type, f.mode, f.link, f.prop, f.group, f.taille, f.time, f.name);
			ft_memdel((void**)&f.mode);
			ft_memdel((void**)&f.time);
		}
	}
}