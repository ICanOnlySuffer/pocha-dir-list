# include "file.h"

struct n_files n_files = {
	.regs = 0,
	.dirs = 0
};

vec * get_files (str path) {
	DIR * dir = opendir (path);
	if (not dir) {
		ret NIL;
	}
	
	vec * files = vec_new (16);
	struct dirent * entry;
	struct stat info;
	
	chr subpath [PATH_SIZE];
	
	while (entry = readdir (dir)) {
		str name = entry -> d_name;
		u08 is_hidden = name [0] == '.';
		
		if (
			is_hidden and
			(not name [1] or (name [1] == '.' and not name [2]))
		) {
			continue;
		}
		STR_CPY (subpath, path, "/", name);
		if (lstat (subpath, &info)) {
			continue;
		}
		
		struct file * file = malloc (sizeof (struct file));
		STR_CPY (file -> name, name);
		file -> size = info.st_size;
		
		if (file -> is_link = S_ISLNK (info.st_mode)) {
			chr buffer [PATH_SIZE] = {0};
			readlink (subpath, buffer, PATH_SIZE);
			STR_CPY (file -> path, buffer);
			lstat (file -> path, &info);
		} else {
			STR_CPY (file -> path, subpath);
		}
		file -> mode = info.st_mode;
		
		switch (info.st_mode & S_IFMT) {
		case S_IFDIR:
			if (is_hidden ? listing.hidden_dirs : listing.dirs) {
				vec_psh (files, file);
				n_files.dirs++;
			}
			break;
		default:
			if (is_hidden ? listing.hidden_regs : listing.regs) {
				vec_psh (files, file);
				n_files.regs++;
			}
		}
	}
	closedir (dir);
	
	ret files;
}

