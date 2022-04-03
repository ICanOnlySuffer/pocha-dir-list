
# ifndef PTREE_OPTION_SORTING_H
# define PTREE_OPTIONS_SORTING_H

# include <pul/str.h>
# include <pul/vec.h>
# include "miscellaneous.h"
# include "../file.h"

ext s32 compare_name (con ptr file_1, con ptr file_2);
ext s32 compare_is_dir (con ptr file_1, con ptr file_2);

ext vec * compare_functions;
ext nil option_sorting (chr options);

# endif // PTREE_OPTION_SORTING_H

