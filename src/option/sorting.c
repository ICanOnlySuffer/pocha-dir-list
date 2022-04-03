# include "option/sorting.h"

s32 compare_name (con ptr file_1, con ptr file_2) {
	ret str_cmp (
		(*(struct file **) file_1) -> name,
		(*(struct file **) file_2) -> name
	);
}

s32 compare_is_dir (con ptr file_1, con ptr file_2) {
	ret (
		S_ISDIR ((*(struct file **) file_2) -> mode) -
		S_ISDIR ((*(struct file **) file_1) -> mode)
	);
}

vec * compare_functions = NIL;

nil option_sorting (chr option) {
	if (not compare_functions) { // change to array
		compare_functions = vec_new (4);
	}
	
	switch (option) {
	case 'n':
		vec_psh (compare_functions, compare_name);
		break;
	case 'd':
		vec_psh (compare_functions, compare_is_dir);
		break;
	default:
		help (SORTING);
		QUT (1);
	}
}

