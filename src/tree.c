# include "tree.h"

nil tree (str padding, str path) {
	vec files = get_files (path);
	
	if (not files.capacity) {
		PUT_ARR (
			padding, "`-- [",
			LANG ('e', 'r', 'r', '.', 'f', 'i', 'l'),
			"]\n"
		);
		return;
	}
	
	for (u08 i = 0; i < n_cmp_functions; i++) {
		vec_srt (&files, cmp_functions [i]);
	}
	
	for (u16 i = 0; i < files.size; i++) {
		fil * file = files.items [i];
		u08 is_last = i < files.size - 1;
		
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
				chr sub_padding [128];
				PUT_ARR (DI_COLOR, file -> name, "/", NO_COLOR, "\n");
				STR_CPY (
					sub_padding, padding, is_last ? "|   " : "    "
				);
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
			put (file -> path);
			new_lne ();
			break;
		default:
			put (file -> name);
			new_lne ();
		}
	}
	
	vec_clr (&files);
}

