# include "file.h"

struct n_files n_files = {
	.regs = 0,
	.dirs = 0
};

vec * get_files (str path) {
	vec * files = vec_new (16);
	DIR * dir = opendir (path);
	unless (dir) {
		return files;
	}
	
	struct dirent * entry;
	struct stat info;
	
	chr subpath [PATH_SIZE];
	u08 is_hidden;
	str name;
	
	while (entry = readdir (dir)) {
		name = entry -> d_name;
		is_hidden = name [0] == '.';
		if (
			is_hidden and
			(not name [1] or (name [1] == '.' and not name [2]))
		) {
			continue;
		}
		STR_CPY (subpath, PATH_SIZE, path, "/", name);
		if (lstat (subpath, &info)) {
			continue;
		}
		
		struct file * file = malloc (sizeof (struct file));
		strncpy (file -> name, name, NAME_SIZE);
		file -> size = info.st_size;
		
		if (file -> is_link = S_ISLNK (info.st_mode)) {
			chr buffer [PATH_SIZE] = {0};
			readlink (subpath, buffer, PATH_SIZE);
			strncpy (file -> path, buffer, PATH_SIZE);
			lstat (file -> path, &info);
		} else {
			strncpy (file -> path, subpath, PATH_SIZE);
		}
		file -> mode = info.st_mode;
		
		switch (info.st_mode & S_IFMT) {
		case S_IFDIR:
			if (is_hidden ? listing.hidden_dirs : listing.dirs) {
				vec_append (files, file);
				n_files.dirs++;
			}
			break;
		default:
			if (is_hidden ? listing.hidden_regs : listing.regs) {
				vec_append (files, file);
				n_files.regs++;
			}
		}
	}
	
	closedir (dir);
	
	return files;
}

