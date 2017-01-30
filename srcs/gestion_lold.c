
#include "../includes/ft_ls.h"

void	print_perms(struct stat *sb)
{
	ft_printf( (S_ISDIR(sb->st_mode)) ? "d" : "-");
	ft_printf( (sb->st_mode & S_IRUSR) ? "r" : "-");
	ft_printf( (sb->st_mode & S_IWUSR) ? "w" : "-");
	ft_printf( (sb->st_mode & S_IXUSR) ? "x" : "-");
	ft_printf( (sb->st_mode & S_IRGRP) ? "r" : "-");
	ft_printf( (sb->st_mode & S_IWGRP) ? "w" : "-");
	ft_printf( (sb->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf( (sb->st_mode & S_IROTH) ? "r" : "-");
	ft_printf( (sb->st_mode & S_IWOTH) ? "w" : "-");
	ft_printf( (sb->st_mode & S_IXOTH) ? "x" : "-");
}

void	printspaces(int nb)
{
	while (nb > 0)
	{
		ft_putchar(' ');
		nb--;
	}
}

void	print_user_group(gid_t gid)
{
	struct	group *gr;

	gr = getgrgid(gid);
	ft_printf("  %s", gr->gr_name);
}

void	print_user_info(t_data *data, uid_t uid)
{
	struct passwd *pwd;

	(void)data;
	pwd = getpwuid(uid);
	ft_printf(" %s", pwd->pw_name);
	print_user_group(pwd->pw_gid);
}

void	print_time(time_t time)
{
	char *oktime;

	oktime = ft_strnew(ft_strlen(ctime(&time)) - 10);
	oktime = ft_strsub(ctime(&time), 4, ft_strlen(ctime(&time)) - 13);
	ft_printf(" %s", oktime);
}

void	no_option(char *path, t_data *data)
{
	DIR			*d;
	struct dirent *dir;
	struct stat sb;
	int max_l_name;
	int max_l_size;
	int max_l_links;

	max_l_name = 0;
	max_l_size = 0;
	max_l_links = 0;
	if (path == NULL)
		path = "./";
	d = opendir(path);
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			stat(ft_strjoin_sep(path, "/", dir->d_name), &sb);
			if (ft_strlen(dir->d_name) > max_l_name)
				max_l_name = ft_strlen(dir->d_name);
			if (ft_nblen(sb.st_size) > max_l_size)
				max_l_size = ft_nblen(sb.st_size);
			if (ft_nblen(sb.st_nlink) > max_l_links)
				max_l_links = ft_nblen(sb.st_nlink);
		}
		d = opendir(path);
		while ((dir = readdir(d)) != NULL)
		{

			if (dir->d_name[0] == '.' && data->has_a == FALSE)
			{
			}
			else
			{
				if (data->has_l == TRUE)
				{
					if (stat(ft_strjoin_sep(path, "/", dir->d_name), &sb) == -1)
					{
						ft_printf("\n\nERROR \n\n File : %s", dir->d_name);
					}
					if (check_dir(dir->d_name) == 1)
						ft_printf("d");
					print_perms(&sb);
					if (ft_nblen(sb.st_nlink) > 1)
						printspaces(5 - ft_nblen(sb.st_nlink));
					else
						ft_printf("    ");
					ft_printf("%d", sb.st_nlink);
					print_user_info(data, sb.st_uid);
					printspaces((max_l_size + 2) - ft_nblen(sb.st_size));
					ft_printf("%lld", sb.st_size);
					print_time(sb.st_mtime);
					if (check_dir(dir->d_name) == 1)
						ft_printf(" {:lcyan}%s {:reset}\n", dir->d_name);
					else
						ft_printf("{:red} %s{:reset}\n", dir->d_name);
				}
				else
				{
					if (check_dir(dir->d_name) == 1)
						ft_printf("{:lcyan}%s {:reset}\n", dir->d_name);
					else
						ft_printf("%s\n", dir->d_name);
				}
			}

		}
		closedir(d);
	}
	else
		ft_printf("ft_ls: %s: No such file or directory\n", path);
}
