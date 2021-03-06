#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>

#define printDirHeader (!node->errNum && !node->isFile && ((node->next ||\
					   (node->prev && node->next == NULL))))
#define CANTOPEN 1
#define true 1
#define false 0

/**
 * struct file_list_s - struct that defines linked list of files
 * @fileName: file name
 * @info: file info
 * @last: last file in list?
 * @next: next file in list
 * @prev: prev file in list
 * @printed: printed
 */
typedef struct file_list_s
{
	char *fileName;
	int printed;
	int last;
	struct stat *info;
	struct file_list_s *next;
	struct file_list_s *prev;
} file_list_t;

/**
 * struct dir_list_s - struct that defines linked list of directories
 * @errNum: error number in case error out
 * @dirName: dirname
 * @fileList: linked list of files
 * @isFile: is it a file
 * @printed: printed
 * @numFiles: num files
 * @next: next dir in list
 * @prev: prev dir in list
 * @programName: av[0]
 */
typedef struct dir_list_s
{
	int errNum;
	int isFile;
	int printed;
	int numFiles;
	char *dirName;
	char *programName;
	file_list_t *fileList;
	struct dir_list_s *next;
	struct dir_list_s *prev;
} dir_list_t;

/**
 * struct ls_flags_s - struct that defines printing options
 * @newline: one file per line
 * @hidden: all hidden files
 * @almostAll: almost all hidden files
 * @longPrint: long format
 * @reverse: print reversed
 * @size: print by size
 * @time: print by time
 * @recursive: print recursively
 * @error: error
 * @dirAndFilePrint: are we printing files and dirs?
 * @exit: exit code
 * Return: int
 */
typedef struct ls_flags_s
{
	int exit;
	int newline;
	int hidden;
	int almostAll;
	int longPrint;
	int reverse;
	int size;
	int time;
	int recursive;
	int error;
	int dirAndFilePrint;
} ls_flags_t;

extern struct ls_flags_s flags;
char *buildPermissionString(mode_t st_mode);
void freeDirList(dir_list_t *head);
int _ls(int ac, char **av);
int findFlags(int ac, char **av);
int listDirContents(char *dirName);
void buildDirList(int ac, char **av, dir_list_t **node);
void printList(dir_list_t *dirs);
dir_list_t *dirListNodeCreate(char *program, char *dir);
int *printFilesFirst(dir_list_t *dirs);
void handleError(dir_list_t *node);
int canPrint(char *file);
void printLong(dir_list_t *node, file_list_t *file);

/* advanced */
void sortList(dir_list_t **node);
void reverseList(dir_list_t **head);



/* strings */
char *_strdup(char *src);
size_t _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
#endif /* HSH_H */
