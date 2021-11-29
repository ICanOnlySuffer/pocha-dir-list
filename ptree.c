# include "pprint.h"
# include "file.h"
# include "lang.h"
# include "help.h"

/* globals */

ix1 reset_color [] = "\e[0m";

ix1 di_color [0xF] = "";
ix1 fi_color [0xF] = "";
ix1 ln_color [0xF] = "";
ix1 ex_color [0xF] = "";

/* sorting */

ix4 file_compare_alphanumerically (const ix0 * file_1, const ix0 * file_2) {
	return strcmp (
		((struct file *) file_1) -> name,
		((struct file *) file_2) -> name
	);
}

ix4 file_compare_directories_first (const ix0 * file_1, const ix0 * file_2) {
	return (
		((struct file *) file_1) -> is_regular -
		((struct file *) file_2) -> is_regular
	);
}

ix4 (* file_compare_functions [0xF]) (const ix0 *, const ix0 *);
ux1 n_file_compare_functions = 0;

/* ptree */

ix0 ptree (char * padding, ix1 * path) {
	f_v files = get_files (path);
	
	for (ux1 i = 0; i < n_file_compare_functions; i++) {
		vector_sort (files, file_compare_functions [i]);
	}
	
	for (ux2 i = 0; i < files.size; i++) {
		struct file file = files.items [i];
		
		e01 last = i < files.size - 1;
		
		printf (padding);
		printf (last ? "|-- " : "\\-- ");
		
		if (file.is_link) {
			if (file.exists) {
				if (file.is_regular) {
					pputs (
						ln_color,
						file.name,
						reset_color,
						" -> ",
						(file.is_executable ? ex_color : fi_color),
						file.path,
						reset_color
					);
				} else {
					pputs (
						ln_color,
						file.name,
						"/",
						reset_color,
						" -> ",
						di_color,
						file.path,
						"/",
						reset_color
					);
				}
			} else {
				pputs (
					ln_color,
					file.name,
					reset_color,
					" -> ",
					ln_color,
					file.path,
					reset_color
				);
			}
		} else {
			if (file.is_regular) {
				pputs (
					(file.is_executable ? ex_color : fi_color),
					file.name,
					reset_color
				);
			} else {
				pputs (di_color, file.name, "/", reset_color);
				
				ix1 sub_padding [MAX_PATH_LENGTH];
				strcpy (sub_padding, padding);
				
				ptree (strcat (sub_padding, last ? "|   " : "    "), file.path);
			}
		}
	}
	
	free (files.items);
}

ix0 main (ux1 argc, ix1 * args []) {
	ix1 * path = ".";
	
	set_lang ();
	
	enum option option = OTHER;
	
	// flags
	for (ux1 i = 1; i < argc; i++) {
		if (args [i][0] == '-') {
			while (*++args [i]) {
				switch (*args [i]) {
				case 'P':
					option = PRINTING;
					break;
				case 'L':
					option = LISTING;
					break;
				case 'S':
					option = SORTING;
					break;
				case 'O':
					option = OTHER;
					break;
				default:
					switch (option) {
					case PRINTING:
						# include "cases/printing.h"
						break;
					case SORTING:
						# include "cases/sorting.h"
						break;
					case LISTING:
						# include "cases/listing.h"
						break;
					case OTHER:
						# include "cases/other.h"
						break;
					}
				}
			}
		} else {
			path = args [i];
		}
	}
	
	// check dir
	DIR * dir = opendir (path);
	if (dir == NULL) {
		ix1 * error;
		switch (lang) {
		case EN:
			error = "Error: path '%s' doesn't exist.\n";
			break;
		case ES:
			error = "Error: camino '%s' no existe.\n";
		}
		printf (error, path);
		return;
	}
	closedir (dir);
	
	// path
	pputs (di_color, path, reset_color);
	
	// ls colors
	
	// ptree
	ptree ("", path);
	
	// directories and files count
	printf (
		"\n%u %s, %u %s\n",
		n_directories,
		n_directories - 1 ? "directories" : "directory",
		n_files,
		n_files - 1 ? "files" : "file"
	);
	
}
















