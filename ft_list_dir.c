#include <dirent.h>
#include "../includes/ft_printf.h"

int		main(int ac, char **av)
{
	struct dirent 	*dir;
	DIR				*fd;

	if (ac > 1)
	{
		fd = opendir(av[1]);
		ft_printf("%d\n",fd);
		if (fd)
		{
			while ((dir = readdir(fd)))
			{
				if (dir->d_name[0] && dir->d_name[0]!='.')
					ft_printf("%s\n",dir->d_name);
			}
			closedir(fd);
		}
	}
}
