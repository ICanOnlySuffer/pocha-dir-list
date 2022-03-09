# include "tree.h"

nil tree (str padding, str path) {
	chr sub_padding [PATH_SIZE];
	vec * files = get_files (path);
	
	if (compare_functions) {
		for (u16 i = 0; i < compare_functions -> size; i++) {
			VEC_SORT (files, compare_functions -> items [i]);
		}
	}
	
	for (u16 i = 0; i < files -> size; i++) {
		struct file * file = files -> items [i];
		u08 is_last = i < files -> size - 1;
		
		PUT_ARR (padding, is_last ? "|-- " : "`-- ");
		if (printing.size) {
			print_size (file -> size);
		}
		if (file -> is_link) {
			PUT_ARR (LN_COLOR, file -> name, RESET_COLOR, " -> ");
		}
		
		switch (file -> mode & S_IFMT) {
		case S_IFDIR:
			if (file -> is_link) {
				PUT_ARR (DI_COLOR, file -> path, RESET_COLOR "\n");
			} else {
				PUT_ARR (DI_COLOR, file -> name, "/" RESET_COLOR "\n");
				STR_CPY (
					sub_padding, PATH_SIZE, padding,
					is_last ? "|   " : "    "
				);
				tree (sub_padding, file -> path);
			}
			break;
		case S_IFREG:
			PUT_ARR (
				file -> mode & X_OK ? EX_COLOR : FI_COLOR,
				file -> is_link ? file -> path : file -> name,
				RESET_COLOR "\n"
			);
			break;
		case S_IFLNK:
			put (file -> path);
			put_chr (STD_OUT, '\n');
			break;
		default:
			put (file -> name);
			put_chr (STD_OUT, '\n');
		}
	}
	
	vec_free (files);
}

