# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include <string.h>

# include "pstrcat.h"
# include "vector.h"
# pragma once

# define MAX_NAME_LENGHT 256
# define MAX_PATH_LENGTH 1024

struct file {
	ix1 name [MAX_NAME_LENGHT];
	ix1 path [MAX_PATH_LENGTH]; // sorry uwu
	
	e01 is_executable;
	e01 is_regular;
	e01 is_link;
	
	e01 exists;
} NONE_FILE;


define_vector (f_v, struct file);
typedef struct f_v f_v;


ux2 n_directories = 0;
ux2 n_files = 0;

/* listing */

enum listing {
	DIRECTORIES_ONLY,
	FILES_ONLY,
	BOTH
} to_list = BOTH;

e01 list_hidden = false;

/* get files*/

f_v get_files (ix1 * path) {
	f_v files = new_vector (struct file, NONE_FILE);
	
	DIR * dir = opendir (path);
	if (!dir) {
		return files;
	}
	
	struct dirent * entry;
	struct stat info;
	
	while (entry = readdir (dir)) {
		ix1 sub_path [MAX_PATH_LENGTH] = {0};
		
		if (
			// not either "," or ".."
			!strcmp (entry -> d_name, ".") ||
			!strcmp (entry -> d_name, "..") ||
			// bool 'all' is false and the file is hidden
			(
				!list_hidden && entry -> d_name [0] == '.'
			) ||
			// lstat error 
			lstat (
				// sub_path
				pstrcat (
					sub_path,
					MAX_PATH_LENGTH,
					path,
					"/",
					entry -> d_name
				),
				&info
			)
		) {
			continue;
		}
		
		struct file file = {
			.path = {0},
			.exists = true,
			.is_link = false,
			.is_executable = info.st_mode & X_OK
		};
		
		strncpy (file.name, entry -> d_name, MAX_NAME_LENGHT);
		
		switch (info.st_mode & S_IFMT) {
		case S_IFDIR:
			if (to_list != FILES_ONLY) {
				n_directories++;
				file.is_regular = false;
				strncpy (file.path, sub_path, MAX_PATH_LENGTH);
				f_v_append (&files, file);
			}
			break;
			
		case S_IFREG:
			if (to_list != DIRECTORIES_ONLY) {
				n_files++;
				file.is_regular = true;
				f_v_append (&files, file);
			}
			break;
			
		case S_IFLNK:
			file.is_link = true;
			readlink (sub_path, file.path, MAX_PATH_LENGTH);
			
			if (!lstat (file.path, &info)) {
				switch (info.st_mode & S_IFMT) {
				case S_IFDIR:
					if (to_list != FILES_ONLY) {
						n_directories++;
						file.is_regular = false;
					}
					break;
				case S_IFREG:
					if (to_list != DIRECTORIES_ONLY) {
						n_files++;
						file.is_regular = true;
					}
				}
			} else {
				n_files++;
				file.exists = false;
			}
			
			f_v_append (&files, file);
		}
	}
	
	closedir (dir);
	
	return files;
}









