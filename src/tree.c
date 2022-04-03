# include "tree.h"

nil tree (str padding, str path) {
	chr sub_padding [PATH_SIZE];
	vec * files = get_files (path);
	
	IFF not files THN // couldn't open
		ret;
	END
	
	if (compare_functions) { // replace with array
		for (u16 i = 0; i < compare_functions -> size; i++) {
			VEC_SRT (files, compare_functions -> items [i]);
		}
	}
	
	for (u16 i = 0; i < files -> size; i++) {
		struct file * file = files -> items [i];
		u08 is_last = i < files -> size - 1;
		
		PUT_ARR (padding, is_last ? "|-- " : "`-- ");
		if (printing.size) {
			chr size_buffer [8] = "[     ] ";
			str_frm_filesize (size_buffer + 1, file -> size);
			write (STD_OUT, size_buffer, 8);
		}
		if (file -> is_link) {
			PUT_ARR (LN_COLOR, file -> name, NO_COLOR, " -> ");
		}
		
		switch (file -> mode & S_IFMT) {
		case S_IFDIR:
			if (file -> is_link) {
				PUT_ARR (DI_COLOR, file -> path, NO_COLOR, "\n");
			} else {
				PUT_ARR (DI_COLOR, file -> name, "/", NO_COLOR, "\n");
				STR_CPY (sub_padding, padding, is_last ? "|   " : "    ");
				tree (sub_padding, file -> path);
			}
			break;
		case S_IFREG:
			PUT_ARR (
				file -> mode & X_OK ? EX_COLOR : FI_COLOR,
				file -> is_link ? file -> path : file -> name,
				NO_COLOR, "\n"
			);
			break;
		case S_IFLNK:
			PUT (file -> path);
			NEW_LNE ();
			break;
		default:
			PUT (file -> name);
			NEW_LNE ();
		}
	}
	
	VEC_DEL (files);
}

