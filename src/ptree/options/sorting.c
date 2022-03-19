# include "sorting.h"

s32 compare_name (con nil * file_1, con nil * file_2) {
	ret str_cmp (
		(*(struct file **) file_1) -> name,
		(*(struct file **) file_2) -> name
	);
}

s32 compare_is_dir (con nil * file_1, con nil * file_2) {
	ret (
		S_ISDIR ((*(struct file**) file_2) -> mode) -
		S_ISDIR ((*(struct file**) file_1) -> mode)
	);
}

vec * compare_functions = NIL;

nil option_sorting (str * options) {
	unl (compare_functions) {
		compare_functions = vec_new (4);
	}
	
	cse (**options) {
	whn 'n':
		vec_psh (
			compare_functions,
			compare_name
		);
		break;
	whn 'd':
		vec_psh (
			compare_functions,
			compare_is_dir
		);
		break;
	default:
		help (SORTING);
		exit (1);
	}
}

