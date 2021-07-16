#include "hsh.h"

/**
 * printLong - prints long format
 * @file: file to print info about
 */
void printLong(file_list_t *file)
{
	struct group *grp;
	struct passwd *usr;
	char *time;
	char *permstring = buildPermissionString(file->info->st_mode);
	int i = 0;

	/* print perm string */
	printf("%s ", permstring);
	free(permstring);

	/* print hard links */
	printf("%d ", (int)file->info->st_nlink);

	/* print user */
	usr = getpwuid(file->info->st_uid);
	(usr) ? printf("%s ", usr->pw_name) : printf("%d ", (int)file->info->st_uid);

	/* print group */
	grp = getgrgid(file->info->st_gid);
	(grp) ? printf("%s ", grp->gr_name) : printf("%d ", (int)file->info->st_gid);

	/* print size */
	printf("%d ", (int)file->info->st_size);

	/* print time */
	time = ctime(&(file->info->st_mtime));
	while (time[i])
		if (time[++i] == '\n')
			time[i] = '\0';

	printf("%s ", time);
}
/**
 * buildPermissionString - builds Permission string
 * @st_mode: mode of file
 * Return: char *
 */
char *buildPermissionString(mode_t st_mode)
{
		char *permString = malloc(sizeof(char) * 11);

		permString[0] = (S_ISREG(st_mode)) ? '-' : 'd';
		if (S_ISLNK(st_mode))
			permString[0] = 'l';
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
