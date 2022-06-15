
# ifndef PDT_OPTION_SORTING_H
# define PDT_OPTION_SORTING_H

# include "misc.h"
# include "../file.h"

ext u08 n_cmp_functions;
ext s32 (*cmp_functions [4]) (file_t ** file_1, file_t ** file_2);
ext nil option_sorting (chr option);

# endif // PDT_OPTION_SORTING_H

