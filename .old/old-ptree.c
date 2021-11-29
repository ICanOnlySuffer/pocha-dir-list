# include <sys/stat.h>
# include <stdbool.h>
# include <dirent.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

# include "vector.h"

/* globals */

char color [] = "\e[91m";

struct file {
	char name [64];
	char path [512];
	bool is_dir;
	bool is_link;
};

define_vector (file_vector, struct file *);
typedef struct file_vector file_vector;

define_vector (string_vector, char *);
typedef struct string_vector string_vector;

int compare_files (const void * file_1, const void * file_2) {
	return strcmp (
		(* (struct file **) file_1) -> name,
		(* (struct file **) file_2) -> name
	);
}

/* tree */

string_vector tree (char * base_path) {
	string_vector lines;
	file_vector files;
	file_vector dirs;
	
	DIR * dir = opendir (base_path);
	struct dirent * dirent;
	struct stat info;
	
	char path [512];
	
	if (dir == NULL) {
		lines.size = 0;
		return lines;
	}
	
	files = (file_vector) new_vector (struct file *, NULL);
	dirs = (file_vector) new_vector (struct file *, NULL);
	
	while ((dirent = readdir (dir)) != NULL) {
		# define filename dirent -> d_name
		if (!strcmp (filename, ".") || !strcmp (filename, "..")) {
			continue;
		}
		
		strcpy (path, base_path);
		strcat (path, "/");
		strcat (path, filename);
		
		if (lstat (path, &info)) {
			continue;
		}
		
		struct file * file = malloc (sizeof (struct file));
		strcpy (file -> name, filename);
		
		if (S_ISLNK (info.st_mode)) {
			
			file -> is_link = true;
			
			readlink (path, file -> path, 256);
			lstat (file -> path, &info);
			
			if (S_ISREG (info.st_mode)) {
				file_vector_append (&files, file);
				file -> is_dir = false;
			} else {
				file_vector_append (&dirs, file);
				file -> is_dir = true;
			}
			
		} else if (S_ISREG (info.st_mode)) {
			
			file -> is_link = false;
			file -> is_dir = false;
			file_vector_append (&files, file);
			
		} else if (S_ISDIR (info.st_mode)) {
			
			strcpy (file -> path, path);
			file -> is_link = false;
			file -> is_dir = true;
			file_vector_append (&dirs, file);
			
		}
  	}
	
	closedir (dir);
	
	vector_sort (dirs, compare_files);
	vector_sort (files, compare_files);
	
	file_vector_append_array (&dirs, files.size, files.items);
	
	lines = (string_vector) new_vector (char *, NULL);
	
	for_each (i, dirs,
		char * line = malloc (512);
		string_vector_append (&lines, line);
		
		bool last = _ < dirs.size - 1;
		sprintf (line, last ? "|-- " : "\\-- ");
		
		char buffer [512];
		if (i -> is_dir) {
			if (i -> is_link) {
				sprintf (
					buffer, "%s%s/ -> %s/\e[0m", color, i -> name, i -> path
				);
			} else {
				sprintf (buffer, "%s%s/\e[0m", color, i -> name);
				string_vector sub_lines = tree (i -> path);
				
				for_each (j, sub_lines,
					char * sub_line = malloc (512);
					strcpy (sub_line, last ? "|   " : "    ");
					strcat (sub_line, j);
					
					string_vector_append (&lines, sub_line);
				);
				
				free (sub_lines.items);
			}
		} else {
			if (i -> is_link) {
				sprintf (buffer, "%s -> %s", i -> name, i -> path);
			} else {
				strcpy (buffer, i -> name);
			}
		}
		
		strcat (line, buffer);
	);
	
	free (files.items);
	free (dirs.items);
	
	
	return lines;
}

int main (int argc, char * args []) {
	
	char path [] = ".";
	
	string_vector lines = tree (path);
	
	for_each (line, lines,
		puts (line);
	);
	
	free (lines.items);
}
















