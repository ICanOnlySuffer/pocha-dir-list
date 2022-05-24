# include "../../inc/option/sorting.h"
# include "../../inc/file.h"
# include <sys/stat.h>
# include <pul/str.h>

s32 cmp_name (ptr file_1, ptr file_2) {
	return str_cmp (
		(*(file_t **) file_1) -> name,
		(*(file_t **) file_2) -> name
	);
}

s32 cmp_dirs (ptr file_1, ptr file_2) {
	return (
		S_ISDIR ((*(file_t **) file_2) -> mode) -
		S_ISDIR ((*(file_t **) file_1) -> mode)
	);
}

u08 n_cmp_functions = 0;
s32 (*cmp_functions [4]) (ptr, ptr);

nil option_sorting (chr option) {
	switch (option) {
	case 'n':
		cmp_functions [n_cmp_functions++] = cmp_name;
		break;
	case 'd':
		cmp_functions [n_cmp_functions++] = cmp_dirs;
		break;
	default:
		help (USAGE);
		help (SORTING);
		exit (1);
	}
}

