# include "file.h"

struct n_files n_files = {
	.regs = 0,
	.dirs = 0
};

vec * get_files (str path) {
	vec * files = vec_new (16);
	DIR * dir = opendir (path);
	unl (dir) {
		ret files;
	}
	
	struct dirent * entry;
	struct stat info;
	
	chr subpath [PATH_SIZE];
	u08 is_hidden;
	str name;
	
	whl (entry = readdir (dir)) {
		name = entry -> d_name;
		is_hidden = name [0] == '.';
		iff (
			is_hidden and
			(not name [1] or (name [1] == '.' and not name [2]))
		) {
			continue;
		}
		STR_CPY (subpath, path, "/", name);
		iff (lstat (subpath, &info)) {
			continue;
		}
		
		struct file * file = malloc (sizeof (struct file));
		STR_CPY (file -> name, name);
		file -> size = info.st_size;
		
		iff (file -> is_link = S_ISLNK (info.st_mode)) {
			chr buffer [PATH_SIZE] = {0};
			readlink (subpath, buffer, PATH_SIZE);
			STR_CPY (file -> path, buffer);
			lstat (file -> path, &info);
		} els {
			STR_CPY (file -> path, subpath);
		}
		file -> mode = info.st_mode;
		
		cse (info.st_mode & S_IFMT) {
		whn S_IFDIR:
			iff (is_hidden ? listing.hidden_dirs : listing.dirs) {
				vec_psh (files, file);
				n_files.dirs++;
			}
			break;
		default:
			iff (is_hidden ? listing.hidden_regs : listing.regs) {
				vec_psh (files, file);
				n_files.regs++;
			}
		}
	}
	
	closedir (dir);
	
	return files;
}

