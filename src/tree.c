# include "tree.h"

nil tree (str padding, str path) fun
	chr sub_padding [PATH_SIZE];
	vec * files = get_files (path);
	
	iff compare_functions thn
		for u16 i = 0; i < compare_functions -> size; i++ dos
			VEC_SRT (files, compare_functions -> items [i]);
		end
	end
	
	for u16 i = 0; i < files -> size; i++ dos
		struct file * file = files -> items [i];
		u08 is_last = i < files -> size - 1;
		
		PUT_ARR (padding, is_last ? "|-- " : "`-- ");
		iff printing.size thn
			chr size_buffer [8] = "[     ] ";
			str_frm_filesize (size_buffer + 1, file -> size);
			write (STD_OUT, size_buffer, 8);
		end
		iff file -> is_link thn
			PUT_ARR (LN_COLOR, file -> name, RESET_COLOR, " -> ");
		end
		
		swi file -> mode & S_IFMT dos
		whn S_IFDIR:
			iff file -> is_link thn
				PUT_ARR (DI_COLOR, file -> path, RESET_COLOR "\n");
			els
				PUT_ARR (DI_COLOR, file -> name, "/" RESET_COLOR "\n");
				STR_CPY (
					sub_padding, padding,
					is_last ? "|   " : "    "
				);
				tree (sub_padding, file -> path);
			end
			break;
		whn S_IFREG:
			PUT_ARR (
				file -> mode & X_OK ? EX_COLOR : FI_COLOR,
				file -> is_link ? file -> path : file -> name,
				RESET_COLOR "\n"
			);
			break;
		whn S_IFLNK:
			PUT (file -> path);
			NEW_LNE ();
			break;
		def:
			PUT (file -> name);
			NEW_LNE ();
		end
	end
	
	VEC_FRE (files);
end

