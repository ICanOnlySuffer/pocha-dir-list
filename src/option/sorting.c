# include "option/sorting.h"

s32 cmp_name (con nil * file_1, con nil * file_2) FUN
	RET str_cmp (
		(*(fil **) file_1) -> name,
		(*(fil **) file_2) -> name
	);
END

s32 cmp_dirs (con nil * file_1, con nil * file_2) FUN
	RET (
		S_ISDIR ((*(fil **) file_2) -> mode) -
		S_ISDIR ((*(fil **) file_1) -> mode)
	);
END

u08 n_cmp_functions = 0;
s32 (*cmp_functions [4]) (con nil *, con nil *);

nil option_sorting (chr option) FUN
	SWI option DOS
	WHN 'n':
		cmp_functions [n_cmp_functions++] = cmp_name;
		BRK;
	WHN 'd':
		cmp_functions [n_cmp_functions++] = cmp_dirs;
		BRK;
	default:
		help (SORTING);
		QUT (1);
	END
END

