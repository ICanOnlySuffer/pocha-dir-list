# include "../inc/option/printing.h"
# include "../inc/option/sorting.h"
# include "../inc/buffer.h"
# include "../inc/file.h"
# include "../inc/tree.h"
# include "../inc/lang.h"
# include <sys/stat.h>
# include <pul/put.h>
# include <pul/vec.h>
# include <unistd.h>

nil tree (str padding, str path) {
	vec files = get_files (path);
	
	if (not files.capacity) {
		STR_CPY (
			BUFFER,
			padding,
			"`-- [",
			LANG ('e', 'r', 'r', '.', 'f', 'i', 'l'),
			"]\n"
		);
		put (BUFFER);
		return;
	}

	for (u08 i = 0; i < n_cmp_functions; i++) {
		vec_srt (&files, cmp_functions [i]);
	}
	
	for (u16 i = 0; i < files.size; i++) {
		file_t * file = files.items [i];
		u08 is_last = i < files.size - 1;
		
		STR_CPY (BUFFER, padding, is_last ? "|-- " : "`-- ");
		
		if (printing.size) {
			chr size_buffer [9] = "[     ] ";
			str_frm_filesize (size_buffer + 1, file -> size);
			str_cat (BUFFER, size_buffer);
		}
		if (file -> is_link) {
			STR_CAT (
				BUFFER,
				LN_COLOR,
				file -> name,
				NO_COLOR,
				" -> "
			);
		}
		
		switch (file -> mode & S_IFMT) {
		case S_IFDIR:
			if (file -> is_link) {
				STR_CAT (
					BUFFER,
					DI_COLOR,
					file -> path,
					NO_COLOR,
					"\n"
				);
				put (BUFFER);
			} else {
				chr sub_padding [128];
				STR_CAT (
					BUFFER,
					DI_COLOR,
					file -> name,
					"/",
					NO_COLOR,
					"\n"
				);
				put (BUFFER);
				STR_CPY (
					sub_padding,
					padding,
					is_last ? "|   " : "    "
				);
				tree (sub_padding, file -> path);
			}
			break;
		case S_IFREG:
			STR_CAT (
				BUFFER,
				file -> mode & X_OK ? EX_COLOR : FI_COLOR,
				file -> is_link ? file -> path : file -> name,
				NO_COLOR, "\n"
			);
			put (BUFFER);
			break;
		case S_IFLNK:
			STR_CAT (BUFFER, file -> path, "\n");
			put (BUFFER);
			break;
		default:
			STR_CAT (BUFFER, file -> name, "\n");
			put (BUFFER);
		}
	}
	
	vec_for_all (&files, free);
}

