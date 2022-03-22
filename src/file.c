# include "file.h"

struct n_files n_files = {
	.regs = 0,
	.dirs = 0
};

vec * get_files (str path) fun
	DIR * dir = opendir (path);
	vec * files = vec_new (16);
	
	iff not dir thn
		ret files;
	end
	
	struct dirent * entry;
	struct stat info;
	
	chr subpath [PATH_SIZE];
	
	whl entry = readdir (dir) dos
		str name = entry -> d_name;
		u08 is_hidden = name [0] == '.';
		
		iff
			is_hidden and
			(not name [1] or (name [1] == '.' and not name [2]))
		thn
			nxt;
		end
		STR_CPY (subpath, path, "/", name);
		iff lstat (subpath, &info) thn
			nxt;
		end
		
		struct file * file = malloc (sizeof (struct file));
		STR_CPY (file -> name, name);
		file -> size = info.st_size;
		
		iff file -> is_link = S_ISLNK (info.st_mode) thn
			chr buffer [PATH_SIZE] = {0};
			readlink (subpath, buffer, PATH_SIZE);
			STR_CPY (file -> path, buffer);
			lstat (file -> path, &info);
		els
			STR_CPY (file -> path, subpath);
		end
		file -> mode = info.st_mode;
		
		swi info.st_mode & S_IFMT dos
		whn S_IFDIR:
			iff is_hidden ? listing.hidden_dirs : listing.dirs thn
				vec_psh (files, file);
				n_files.dirs++;
			end
			break;
		default:
			iff is_hidden ? listing.hidden_regs : listing.regs thn
				vec_psh (files, file);
				n_files.regs++;
			end
		end
	end
	
	closedir (dir);
	
	ret files;
end

