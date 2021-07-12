#include "hsh.h"
int openDirectory(char *dirName);
char *buildPermissionString(mode_t st_mode);

/**
 * main - entry point
 * @ac: arg count
 * @av: args
 * Return: int
 */
int main(int ac, char **av)
{

	if (ac != 2)
		return (openDirectory("."));

	return (openDirectory(av[1]));
}

int openDirectory(char *dirName)
{
	char *time;
	char *perms;
	struct stat buf;
	struct group *grp;
	struct passwd *usr;
	struct dirent *read;
	DIR *dir = opendir(dirName);

	while ((read = readdir(dir)) != NULL)
	{
		lstat(read->d_name, &buf);
		time = strtok(ctime(&(buf.st_mtime)), "\n");
		perms = buildPermissionString(buf.st_mode);
		usr = getpwuid(buf.st_uid);
		grp = getgrgid(buf.st_gid);
		printf("%s %d %s %s %d %s %s\n", perms, (int)buf.st_nlink, usr->pw_name, grp->gr_name, (int)buf.st_size, time, read->d_name);
		free(perms);
	}

	closedir(dir);
	return (0);
}

char *buildPermissionString(mode_t st_mode)
{
	char *permString = malloc(sizeof(char) * 11);

	permString[0] = (S_ISREG(st_mode)) ? '-' : 'd';
	permString[1] = (S_IRUSR & st_mode) ? 'r' : '-';
	permString[2] = (S_IWUSR & st_mode) ? 'w' : '-';
	permString[3] = (S_IXUSR & st_mode) ? 'x' : '-';
	permString[4] = (S_IRGRP & st_mode) ? 'r' : '-';
	permString[5] = (S_IWGRP & st_mode) ? 'w' : '-';
	permString[6] = (S_IXGRP & st_mode) ? 'x' : '-';
	permString[7] = (S_IROTH & st_mode) ? 'r' : '-';
	permString[8] = (S_IWOTH & st_mode) ? 'w' : '-';
	permString[9] = (S_IXOTH & st_mode) ? 'x' : '-';
	permString[10] = '\0';

	return (permString);
}