# include "../../inc/option/sorting.h"
# include <pocha/str.h>
# include <sys/stat.h>

static s32 cmp_name (file_t ** file_1, file_t ** file_2) {
	ret str_cmp (
		(*file_1) -> name,
		(*file_2) -> name
	);
}

static s32 cmp_dirs (file_t ** file_1, file_t ** file_2) {
	ret (
		S_ISDIR ((*file_2) -> mode) -
		S_ISDIR ((*file_1) -> mode)
	);
}

u08 n_cmp_functions = 0;
s32 (*cmp_functions [4]) (file_t **, file_t **);

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

