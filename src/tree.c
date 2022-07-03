# include "../inc/option/printing.h"
# include "../inc/option/sorting.h"
# include "../inc/buffer.h"
# include "../inc/file.h"
# include "../inc/tree.h"
# include "../inc/lang.h"
# include <pocha/ioe.h>
# include <pocha/vec.h>
# include <sys/stat.h>
# include <unistd.h>

static chr PADDING [128] = "";
static str padding = PADDING;
static str buffer;

# define BFF_CPY(...) \
	STR_COPY (buffer, __VA_ARGS__)

nil tree (str path) {
	vec files = get_files (path);
	
	if (not files.capacity) {
		STR_COPY (BUFFER, PADDING, "`-- [", LANG_ERR_FIL, "]\n");
		put (BUFFER);
		ret;
	}
	
	for (u08 i = 0; i < n_cmp_functions; i++) {
		vec_sort (&files, (prc_cmp) cmp_functions [i]);
	}
	
	for (u16 i = 0; i < files.size; i++) {
		file_t * file = files.items [i];
		u08 is_last = i < files.size - 1;
		
		buffer = STR_COPY (BUFFER, PADDING, is_last ? "|-- " : "`-- ");
		
		if (printing.size) {
			str_frm_size (buffer, file -> size);
			buffer += 8;
		}
		if (file -> is_link) {
			buffer = BFF_CPY (
				LN_COLOR, file -> name, NO_COLOR, " -> "
			);
		}
		
		switch (file -> mode & S_IFMT) {
		case S_IFDIR:
			if (file -> is_link) {
				BFF_CPY (DI_COLOR, file -> path, NO_COLOR, "\n");
				put (BUFFER);
			} else {
				BFF_CPY (DI_COLOR, file -> name, "/", NO_COLOR, "\n");
				put (BUFFER);
				STR_COPY (padding, is_last ? "|   " : "    ");
				padding += 4;
				tree (file -> path);
				*(padding -= 4) = 0;
			}
			break;
		case S_IFREG:
			BFF_CPY (
				file -> mode & X_OK ? EX_COLOR : FI_COLOR,
				file -> is_link ? file -> path : file -> name,
				NO_COLOR, "\n"
			);
			put (BUFFER);
			break;
		case S_IFLNK:
			BFF_CPY (file -> path, "\n");
			put (BUFFER);
			break;
		default:
			BFF_CPY (file -> name, "\n");
			put (BUFFER);
		}
	}
	
	vec_for_all (&files, free);
	vec_free (&files);
}

