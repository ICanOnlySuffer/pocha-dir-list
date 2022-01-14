# include "flags/printing.h"
# include "flags/listing.h"
# include "utils/pstring.h"
# include "utils/pstdio.h"
# include "file.h"
# pragma once

# define putf(...) \
	pputs (__VA_ARGS__, reset_color)

nil tree (str padding, str path) {
	struct vector files = get_files (path);
	ix1 sub_padding [MAX_PATH_LENGTH];
	tof is_last;
	
	for_index (i, file_compare_functions) {
		vector_sort (files, file_compare_functions.items [i]);
	}
	
	for_index (i, files) {
		struct file *file = files.items [i];
		is_last = i < files.size - 1;
		
		pprint (padding, is_last ? "|-- " : "`-- ");
		
		switch (file->type) {
		case S_IFDIR:
			if (file->is_link) {
				putf (
					ln_color, file->name, "/", reset_color, " -> ",
					di_color, file->path
				);
			} else {
				putf (di_color, file->name, "/");
				pstrcpy (
					sub_padding, PATH_SIZE, padding,
					is_last ? "|   " : "    "
				);
				tree (sub_padding, file->path);
			}
			break;
			
		case S_IFREG:
			if (file->is_link) {
				if (file->exists) {
					putf (
						ln_color, file->name, reset_color, " -> ",
						file->is_exe ? ex_color : fi_color, file->path
					);
				} else {
					putf (
						ln_color, file->name, reset_color, " -> ",
						ln_color, file->path
					);
				}
			} else {
				putf (file->is_exe ? ex_color : fi_color, file->name);
			}
		}
	}
	
	vector_free (&files);
}















