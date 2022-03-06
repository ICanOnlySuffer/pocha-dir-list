# include "options/printing.h"
# include "options/sorting.h"

# include "../putils/str-cpy.h"
# include "../putils/print.h"
# include "../putils/vec.h"
# include "../putils/ioe.h"
# include "file.h"
# include "size.h"

# define PATH_SIZE 1024

nil tree (str padding, str path) {
	chr sub_padding [PATH_SIZE];
	vec * files = get_files (path);
	
	if (compare_functions) {
		for (u16 i = 0; i < compare_functions -> size; i++) {
			vec_sort (files, compare_functions -> items [i]);
		}
	}
	
	for (u16 i = 0; i < files -> size; i++) {
		struct file * file = files -> items [i];
		u08 is_last = i < files -> size - 1;
		
		print_many (padding, is_last ? "|-- " : "`-- ");
		if (printing.size) {
			print_size (file -> size);
		}
		if (file -> is_link) {
			print_many (ln_color, file -> name, reset_color, " -> ");
		}
		
		switch (file -> mode & S_IFMT) {
		case S_IFDIR:
			if (file -> is_link) {
				print_many (di_color, file -> path, reset_color "\n");
			} else {
				print_many (di_color, file -> name, "/" reset_color "\n");
				str_cpy (
					sub_padding, PATH_SIZE, padding,
					is_last ? "|   " : "    "
				);
				tree (sub_padding, file -> path);
			}
			break;
		case S_IFREG:
			print_many (
				file -> mode & X_OK ? ex_color : fi_color,
				file -> is_link ? file -> path : file -> name,
				reset_color "\n"
			);
			break;
		case S_IFLNK:
			print (file -> path);
			put_chr ('\n');
			break;
		default:
			print (file -> name);
			put_chr ('\n');
		}
	}
	
	vec_free (files);
}

