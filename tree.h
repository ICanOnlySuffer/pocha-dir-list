# include "file.h"
# pragma once

/* globals */

ix1 reset_color [] = "\e[0m";

ix1 di_color [16] = "";
ix1 fi_color [16] = "";
ix1 ln_color [16] = "";
ix1 ex_color [16] = "";

ix4 (* file_compare_functions [16]) (const ix0 *, const ix0 *);
ux1 n_file_compare_functions = 0;


ix0 tree (char * padding, ix1 * path) {
	
	f_v files = get_files (path);
	
	for (ux1 i = 0; i < n_file_compare_functions; i++) {
		vector_sort (files, file_compare_functions [i]);
	}
	
	for (ux2 i = 0; i < files.size; i++) {
		struct file file = files.items [i];
		
		e01 last = i < files.size - 1;
		
		printf (padding);
		printf (last ? "|-- " : "`-- ");
		
		if (file.is_link) {
			if (file.exists) {
				if (file.is_regular) {
					pputs (
						ln_color,
						file.name,
						reset_color,
						" -> ",
						(file.is_executable ? ex_color : fi_color),
						file.path,
						reset_color
					);
				} else {
					pputs (
						ln_color,
						file.name,
						"/",
						reset_color,
						" -> ",
						di_color,
						file.path,
						reset_color
					);
				}
			} else {
				pputs (
					ln_color,
					file.name,
					reset_color,
					" -> ",
					ln_color,
					file.path,
					reset_color
				);
			}
		} else {
			if (file.is_regular) {
				pputs (
					(file.is_executable ? ex_color : fi_color),
					file.name,
					reset_color
				);
			} else {
				pputs (
					di_color,
					file.name,
					"/",
					reset_color
				);
				
				ix1 sub_padding [MAX_PATH_LENGTH];
				strcpy (sub_padding, padding);
				
				tree (
					strcat (sub_padding, last ? "|   " : "    "),
					file.path
				);
			}
		}
	}
	
	free (files.items);
}















