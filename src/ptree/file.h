# ifndef _FILE_
# define _FILE_

# include <putils/string.h>
# include <putils/vector.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>

# include "flags/listing.h"

# define PATH_SIZE 1024
# define NAME_SIZE 256

struct file {
	chr name [NAME_SIZE];
	chr path [PATH_SIZE];
	u08 is_link;
	u08 is_exe;
	u08 exists;
	s32 type;
	u32 size;
};

struct file * file_new (str name, str path, s32 mode) {
	struct file * file = malloc (sizeof (struct file));
	
	strncpy (file -> name, name, NAME_SIZE);
	strncpy (file -> path, path, PATH_SIZE);
	
	file -> is_link = false;
	file -> exists = true;
	file -> is_exe = mode & X_OK;
	file -> type = mode & S_IFMT;
	
	return file;
}

struct {
	u32 regs;
	u32 dirs;
} n_files = {
	.regs = 0,
	.dirs = 0
};

vec * get_files (str path) {
	vec * files = vector_new (16);
	DIR * dir = opendir (path);
	if (not dir) {
		return files;
	}
	
	struct dirent * entry;
	struct stat info;
	
	chr subpath [PATH_SIZE];
	chr buffer [PATH_SIZE];
	u08 is_hidden;
	str name;
	
	while (entry = readdir (dir)) {
		name = entry -> d_name;
		if (is_hidden = name [0] == '.') {
			if (
				(name [1] == 0) or
				(name [1] == '.' and name [2] == 0)
			) {
				continue;
			}
		}
		
		pstrcpy (subpath, PATH_SIZE, path, "/", entry -> d_name);
		if (lstat (subpath, &info)) {
			continue;
		}
		
		struct file * file = file_new (name, subpath, info.st_mode);
		
		type_switch:
		switch (file -> type) {
		case S_IFREG:
			if (is_hidden ? listing.hidden_regs : listing.regs) {
				vector_append (files, file);
				n_files.regs++;
			}
			break;
		case S_IFDIR:
			if (is_hidden ? listing.hidden_dirs : listing.dirs) {
				vector_append (files, file);
				n_files.dirs++;
			}
			break;
		case S_IFLNK:
			readlink (subpath, buffer, PATH_SIZE);
			file -> is_link = true;
			
			if (lstat (file -> path, &info)) {
				file -> type = info.st_mode & S_IFMT;
			} else {
				file -> exists = false;
				file -> type = S_IFREG;
			}
			
			goto type_switch; // forgive me
		default:
			free (file);
		}
	}
	
	closedir (dir);
	
	return files;
}

# endif // _FILE_







