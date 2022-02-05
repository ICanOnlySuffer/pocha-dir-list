# ifndef _PTREE_TREE_
# define _PTREE_TREE_

# include "options/printing.h"
# include "size.h"

# define putf(...) \
	print (__VA_ARGS__, reset_color, "\n")

nil tree (str padding, str path) {
	chr sub_padding [PATH_SIZE];
	vec * files = get_files (path);
	u08 is_last;
	
	if (compare_functions) {
		for (u16 i = 0; i < compare_functions -> size; i++) {
			vector_sort (files, compare_functions -> items [i]);
		}
	}
	
	for (u16 i = 0; i < files -> size; i++) {
		struct file * file = files -> items [i];
		is_last = i < files -> size - 1;
		
		print (padding, is_last ? "|-- " : "`-- ");
		if (printing.size) {
			print_size (file -> size);
		}
		if (file -> is_link) {
			print (ln_color, file -> name, reset_color, " -> ");
		}
		
		switch (file -> mode & S_IFMT) {
		case S_IFDIR:
			if (file -> is_link) {
				putf (di_color, file -> path, "/");
			} else {
				putf (di_color, file -> name, "/");
				pstrcpy (
					sub_padding, PATH_SIZE, padding,
					is_last ? "|   " : "    "
				);
				tree (sub_padding, file -> path);
			}
			break;
			
		case S_IFREG:
			putf (
				file -> mode & X_OK ? ex_color : fi_color,
				file -> is_link ? file -> path : file -> name
			);
			break;
		case S_IFLNK:
			puts (file -> path);
			break;
		default:
			puts (file -> name);
		}
	}
	
	vector_free (files);
}

# endif // _PTREE_TREE_

