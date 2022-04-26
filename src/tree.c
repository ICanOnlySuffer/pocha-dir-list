# include "tree.h"

nil tree (str padding, str path) {
	vec files = get_files (path);
	
	IFF not files.capacity THN // couldn't open
		PUT_ARR (
			padding, "`-- [",
			LANG ('e', 'r', 'r', '.', 'f', 'i', 'l'),
			"]\n"
		);
		RET;
	END
	
	FOR u08 i = 0; i < n_cmp_functions; i++ DOS
		VEC_SRT (&files, cmp_functions [i]);
	END
	
	FOR u16 i = 0; i < files.size; i++ DOS
		fil * file = files.items [i];
		u08 is_last = i < files.size - 1;
		
		PUT_ARR (padding, is_last ? "|-- " : "`-- ");
		IFF printing.size DOS
			chr size_buffer [8] = "[     ] ";
			str_frm_filesize (size_buffer + 1, file -> size);
			write (STD_OUT, size_buffer, 8);
		END
		IFF file -> is_link DOS
			PUT_ARR (LN_COLOR, file -> name, NO_COLOR, " -> ");
		END
		
		SWI file -> mode & S_IFMT DOS
		WHN S_IFDIR:
			IFF file -> is_link THN
				PUT_ARR (DI_COLOR, file -> path, NO_COLOR, "\n");
			ELS
				chr sub_padding [128];
				PUT_ARR (DI_COLOR, file -> name, "/", NO_COLOR, "\n");
				STR_CPY (
					sub_padding, padding, is_last ? "|   " : "    "
				);
				tree (sub_padding, file -> path);
			END
			BRK;
		WHN S_IFREG:
			PUT_ARR (
				file -> mode & X_OK ? EX_COLOR : FI_COLOR,
				file -> is_link ? file -> path : file -> name,
				NO_COLOR, "\n"
			);
			BRK;
		WHN S_IFLNK:
			PUT (file -> path);
			NEW_LNE ();
			BRK;
		default:
			PUT (file -> name);
			NEW_LNE ();
		END
	END
	
	vec_clr (&files);
END

