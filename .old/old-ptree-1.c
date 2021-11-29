# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# include "pstrcat.h"
# include "vector.h"

/* globals */

ix1 dir_color [] = "\e[91m";
ix1 file_color [] = "\e[0m";
ix1 link_color [] = "\e[37m";
ix1 exec_color [] = "\e[31m";
ix1 reset_color [] = "\e[0m";

ux2 n_dirs = 0;
ux2 n_files = 0;

struct file {
	ix1 name [256];
	ix1 path [4096];
	typeof (S_IFDIR) type;
	e01 exists;
	e01 is_link;
	e01 executable;
};

define_vector (f_v, struct file);
define_vector (s_v, ix1 *);
typedef struct f_v f_v;
typedef struct s_v s_v;

ix4 compare_files_alphabetically (const ix0 * file_1, const ix0 * file_2) {
	return strcmp (
		((struct file *) file_1) -> name,
		((struct file *) file_2) -> name
	);
}

ix4 compare_files_from_dirs (const ix0 * file_1, const ix0 * file_2) {
	return (
		(S_IFDIR == ((struct file *) file_2) -> type) -
		(S_IFDIR == ((struct file *) file_1) -> type)
	);
}

/* tree */

# define BOOL_ARGS    \
	e01 all,          \
	e01 alphabetical, \
	e01 dirs_first

s_v tree (char * path, BOOL_ARGS) {
	
	s_v lines = new_vector (char *, NULL);
	
	struct file empty_file;
	f_v files = new_vector (struct file, empty_file);
	
	DIR * dir = opendir (path);
	struct dirent * entry;
	struct stat info;
	
	ix1 sub_path [4096];
	
	if (dir == NULL) {
		return lines;
	}
	
	while (entry = readdir (dir)) {
		
		if (!strcmp (entry -> d_name, ".") || !strcmp (entry -> d_name, "..")) {
			continue;
		}
		
		if (!all && entry -> d_name [0] == '.') {
			continue;
		}
		
		strcpy (sub_path, path);
		strcat (sub_path, "/");
		strcat (sub_path, entry -> d_name);
		
		if (lstat (sub_path, &info)) {
			continue;
		}
		
		struct file file = {
			.path = {0},
			.is_link = false,
			.executable = false
		};
		
		strcpy (file.name, entry -> d_name);
		
		detect_file:
		
		switch (file.type = (info.st_mode & S_IFMT)) {
		case S_IFDIR:
			
			n_dirs++;
			if (!file.is_link) {
				strcpy (file.path, sub_path);
			}
			
			break;
			
		case S_IFREG:
			
			n_files++;
			if (info.st_mode & X_OK) {
				file.executable = true;
			}
			
			break;
		/*		
		case S_IFBLK:
			
			printf ("block %s!\n", file.name);
		
		case S_IFCHR:
			
			printf ("char %s!\n", file.name);
		
		case S_IFIFO:
			
			printf ("fifo %s!\n", file.name);
		
		case S_IFSOCK:
			
			printf ("sock %s!\n", file.name);
		*/	
		case S_IFLNK:
			
			file.is_link = true;
			readlink (sub_path, file.path, 4096);
			
			if (!lstat (file.path, &info)) {
				
				goto detect_file;
				
			}
			
		default:
			
			file.exists = false;
			n_files++;
			
		}
		
		f_v_append (&files, file);
  	}
	
	closedir (dir);
	
	if (alphabetical) {
		
		vector_sort (files, compare_files_alphabetically);
		
	}
	
	if (dirs_first) {
		
		vector_sort (files, compare_files_from_dirs);
		
	}
	
	for (ux2 i = 0; i < files.size; i++) {
		struct file file = files.items [i];
		
		ix1 * line = malloc (4096);
		line [0] = 0;
		
		e01 last = i < files.size - 1;
		
		strcat (line, last ? "|-- " : "\\-- ");
		
		s_v_append (&lines, line);
		
		if (file.is_link) {
			switch (file.type) {
			case S_IFDIR:
				// puts ("yay");
				
				pstrcat (
					line,
					link_color,
					file.name,
					"/",
					reset_color,
					" -> ",
					dir_color,
					file.path,
					"/",
					reset_color
				);
				//puts ("aw");
				break;
				
			case S_IFREG:
				//puts ("reg");
				
				pstrcat (
					line,
					link_color,
					file.name,
					reset_color,
					" -> ",
					(file.executable ? exec_color : file_color),
					file.path,
					reset_color
				);
				//puts ("ger");
				break;
				
			default:
				//puts ("uwu");
				// puts (file.name);
				pstrcat (
					line,
					link_color,
					file.name,
					reset_color,
					" -> ",
					link_color,
					file.path,
					reset_color
				);
				//puts ("owo");
			}
		} else {
			
			switch (file.type) {
			case S_IFDIR:
				
				pstrcat (line, dir_color, file.name, "/", reset_color);
				
				s_v sub_lines = tree (
					file.path, all, alphabetical, dirs_first
				);
				
				for (ux2 j = 0; j < sub_lines.size; j++) {
					ix1 * sub_line = sub_lines.items [j];
					
					ix1 * buffer = malloc (4096);
					buffer [0] = 0;
					pstrcat (buffer, last ? "|   " : "    ", sub_line);
					
					s_v_append (&lines, buffer);
				}
				
				free (sub_lines.items);
				
				break;
				
			case S_IFREG:
				pstrcat (
					line,
					(file.executable ? exec_color : file_color),
					file.name,
					reset_color
				);
				// printf ("%s\n", file.name);
				// strcpy (buffer, i -> name);
				break;
				
			default:
				// 2.444s
				// 0.127s
				// 0.355s
				pstrcat (line, "<UNK>", file.name, reset_color);
				//printf ("\e[37m%s\e[0m\n", file.name);
				
			}
		}
	}
	
	free (files.items);
	
	return lines;
}


ix0 main (int argc, char * args []) {
	
	ix1 * path = ".";
	
	printf ("%s%s%s\n", dir_color, path, reset_color);
	
	s_v lines = tree (path, true, true, true);
	ix1 * line;
	
	for (ix2 i = 0; i < lines.size; i++) {
		puts (lines.items [i]);
	}
	
	printf ("\n%u directories, %u files\n", n_dirs, n_files);
	free (lines.items);
	
}
















