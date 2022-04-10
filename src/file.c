# include "file.h"

u32 n_regs = 0;
u32 n_dirs = 0;

vec get_files (str path) FUN
	DIR * dir = opendir (path);
	IFF not dir DOS
		RET VEC_NEW (0);
	END
	
	vec files = VEC_NEW (32);
	struct dirent * entry;
	struct stat info;
	
	chr subpath [PATH_SIZE];
	
	WHL entry = readdir (dir) DOS
		str name = entry -> d_name;
		u08 is_hidden = name [0] == '.';
		
		IFF
			is_hidden and
			(not name [1] or (name [1] == '.' and not name [2]))
		DOS
			continue;
		END
		STR_CPY (subpath, path, "/", name);
		IFF lstat (subpath, &info) DOS
			continue;
		END
		
		fil * file = malloc (sizeof (fil));
		STR_CPY (file -> name, name);
		file -> size = info.st_size;
		
		IFF file -> is_link = S_ISLNK (info.st_mode) DOS
			chr buffer [PATH_SIZE] = {0};
			readlink (subpath, buffer, PATH_SIZE);
			STR_CPY (file -> path, buffer);
			lstat (file -> path, &info);
		ELS
			STR_CPY (file -> path, subpath);
		END
		file -> mode = info.st_mode;
		SWI info.st_mode & S_IFMT DOS
		WHN S_IFDIR:
			IFF is_hidden ? listing.hidden_dirs : listing.dirs DOS
				vec_psh (&files, file);
				n_dirs++;
			END
			BRK;
		default:
			IFF is_hidden ? listing.hidden_regs : listing.regs DOS
				vec_psh (&files, file);
				n_regs++;
			END
		END
	END
	closedir (dir);
	
	RET files;
END

