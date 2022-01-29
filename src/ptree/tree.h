# ifndef _TREE_
# define _TREE_

# include "flags/printing.h"
# include "size.h"

# define putf(...) \
	pputs (__VA_ARGS__, reset_color)

nil tree (str padding, str path) {
	chr sub_padding [MAX_PATH_SIZE];
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
		
		pprint (padding, is_last ? "|-- " : "`-- ");
		if (printing.size) {
			print_size (file -> size);
		}
		
		switch (file -> type) {
		case S_IFDIR:
			if (file -> is_link) {
				putf (
					ln_color, file -> name, "/", reset_color, " -> ",
					di_color, file -> path
				);
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
			if (file -> is_link) {
				if (file -> exists) {
					putf (
						ln_color, file -> name, reset_color, " -> ",
						file -> is_exe ? ex_color : fi_color, file -> path
					);
				} else {
					putf (
						ln_color, file -> name, reset_color, " -> ",
						ln_color, file -> path
					);
				}
			} else {
				putf (file -> is_exe ? ex_color : fi_color, file -> name);
			}
		}
	}
	
	vector_free (files);
}

# endif // _TREE_












