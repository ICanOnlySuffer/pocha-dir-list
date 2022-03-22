
# ifndef PTREE_OPTIONS_SORTING_H
# define PTREE_OPTIONS_SORTING_H

# include <putils/str.h>
# include <putils/vec.h>
# include "../file.h"
# include "help.h"

ext s32 compare_name (con ptr file_1, con ptr file_2);
ext s32 compare_is_dir (con ptr file_1, con ptr file_2);

ext vec * compare_functions;
ext nil option_sorting (str * options);

# endif // PTREE_OPTIONS_SORTING_H

