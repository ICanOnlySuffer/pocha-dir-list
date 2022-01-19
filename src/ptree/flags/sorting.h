# ifndef _FLAG_SORTING_
# define _FLAG_SORTING_

# include "../file.h"
# include "help.h"

s32 compare_alphanumerically (const nil * file_1, const nil * file_2) {
	return strcmp (
		(*(struct file **) file_1) -> name,
		(*(struct file **) file_2) -> name
	);
}

s32 compare_directories_first (const nil * file_1, const nil * file_2) {
	return (
		((*(struct file **) file_1) -> type == S_IFREG) -
		((*(struct file **) file_2) -> type == S_IFREG)
	);
}

struct vector * compare_functions = NULL;

nil flag_sorting (str * options) {
	switch (**options) {
	case 'a':
		if (not compare_functions) {
			compare_functions = vector_new (4);
		}
		vector_append (
			compare_functions,
			compare_alphanumerically
		);
		break;
	case 'd':
		if (not compare_functions) {
			compare_functions = vector_new (4);
		}
		vector_append (
			compare_functions,
			compare_directories_first
		);
		break;
	default:
		help (SORTING);
		exit (1);
	}
}

# endif // _FLAG_SORTING_

