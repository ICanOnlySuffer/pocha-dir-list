# include "../file.h"
# include "../help.h"
# pragma once

struct vector file_compare_functions = {.size = 0, .capacity = 0};

nil flag_sorting (str *options) {
	switch (**options) {
	case 'a':
		vector_append (
			&file_compare_functions,
			&file_compare_alphanumerically
		);
		break;
		
	case 'd':
		vector_append (
			&file_compare_functions,
			&file_compare_directories_first
		);
		break;
		
	default:
		help (SORTING);
		exit (1);
	}
}


