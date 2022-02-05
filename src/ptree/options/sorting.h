# ifndef _OPTION_SORTING_
# define _OPTION_SORTING_

# include "../file.h"
# include "help.h"

s32 compare_name (const nil* file_1, const nil* file_2) {
	return strcmp (
		(*(struct file **) file_1) -> name,
		(*(struct file **) file_2) -> name
	);
}

s32 compare_is_dir (const nil* file_1, const nil* file_2) {
	return (
		S_ISDIR ((*(struct file**) file_2) -> mode) -
		S_ISDIR ((*(struct file**) file_1) -> mode)
	);
}

vec * compare_functions = NULL;

nil option_sorting (str * options) {
	switch (**options) {
	case 'n':
		if (not compare_functions) {
			compare_functions = vector_new (4);
		}
		vector_append (
			compare_functions,
			compare_name
		);
		break;
	case 'd':
		if (not compare_functions) {
			compare_functions = vector_new (4);
		}
		vector_append (
			compare_functions,
			compare_is_dir
		);
		break;
	default:
		help (SORTING);
		exit (1);
	}
}

# endif // _OPTION_SORTING_

