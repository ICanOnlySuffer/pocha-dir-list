# include "sorting.h"

s32 compare_name (con nil * file_1, con nil * file_2) {
	return strcmp (
		(*(struct file **) file_1) -> name,
		(*(struct file **) file_2) -> name
	);
}

s32 compare_is_dir (con nil * file_1, con nil * file_2) {
	return (
		S_ISDIR ((*(struct file**) file_2) -> mode) -
		S_ISDIR ((*(struct file**) file_1) -> mode)
	);
}

vec * compare_functions = NIL;

nil option_sorting (str * options) {
	unless (compare_functions) {
		compare_functions = vec_new (4);
	}
	
	switch (**options) {
	case 'n':
		vec_append (
			compare_functions,
			compare_name
		);
		break;
	case 'd':
		vec_append (
			compare_functions,
			compare_is_dir
		);
		break;
	default:
		help (SORTING);
		exit (1);
	}
}

