# define PATH_SIZE 1024
# define NAME_SIZE 256
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>
# include "flags/listing.h"
# include "utils/pstring.h"
# include "utils/vector.h"
# pragma once

struct file {
	ix1 name [NAME_SIZE];
	ix1 path [PATH_SIZE];
	tof is_link;
	tof is_exe;
	tof exists;
	ix4 type;
};

struct file *file_new (str name, str path, ix4 mode) {
	struct file *file = malloc (sizeof (struct file));
	strncpy (file->name, name, NAME_SIZE);
	strncpy (file->path, path, PATH_SIZE);
	
	file->exists = true;
	file->is_link = false;
	file->is_exe = mode & X_OK;
	file->type = mode & S_IFMT;
	
	return file;
}

ix4 file_compare_alphanumerically (con nil *file_1, con nil *file_2) {
	return strcmp (
		(*(struct file **) file_1)->name,
		(*(struct file **) file_2)->name
	);
}

ix4 file_compare_directories_first (con nil *file_1, con nil *file_2) {
	return (
		((*(struct file **) file_1)->type == S_IFREG) -
		((*(struct file **) file_2)->type == S_IFREG)
	);
}

struct vector file_compare_functions;

struct {
	ux4 regs;
	ux4 dirs;
} n_files = {
	.regs = 0,
	.dirs = 0
};

/* get files */

struct vector get_files (str path) {
	struct vector files = *vector_new (4);
	
	DIR *dir = opendir (path);
	if (not dir) {
		return files;
	}
	
	struct dirent *entry;
	struct stat info;
	
	while (entry = readdir (dir)) {
		ix1 subpath [PATH_SIZE] = {0};
		
		if (
			streql (entry->d_name, ".") or  // file is "."
			streql (entry->d_name, "..") or // file is ".."
			lstat (                         // lstat error
				pstrcpy (subpath, PATH_SIZE, path, "/", entry->d_name),
				&info
			)
		) {
			continue;
		}
		
		tof hidden = *(entry->d_name) == '.';
		
		struct file *file = file_new (entry->d_name, subpath, info.st_mode);
		
		switch (file->type) {
		case S_IFREG:
			if (hidden ? listing.hidden_regs : listing.regs) {
				n_files.regs++;
				vector_append (&files, file);
			}
			break;
			
		case S_IFDIR:
			if (hidden ? listing.hidden_dirs : listing.dirs) {
				n_files.dirs++;
				vector_append (&files, file);
			}
			break;
			
		case S_IFLNK:
			file->is_link = true;
			ix1 buffer [PATH_SIZE];
			readlink (subpath, buffer, PATH_SIZE);
			
			if (not lstat (file->path, &info)) {
				file->type = info.st_mode & S_IFMT;
				
				switch (file->type) {
				case S_IFREG:
					if (hidden ? listing.hidden_regs : listing.regs) {
						n_files.regs++;
						vector_append (&files, file);
					}
					break;
					
				case S_IFDIR:
					if (hidden ? listing.hidden_dirs : listing.dirs) {
						n_files.dirs++;
						vector_append (&files, file);
					}
				}
			} else if (hidden ? listing.hidden_regs : listing.regs) {
				file->exists = false;
				n_files.regs++;
				vector_append (&files, file);
			}
		}
	}
	
	closedir (dir);
	
	return files;
}









