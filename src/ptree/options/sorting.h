
# ifndef _OPTION_SORTING_
# define _OPTION_SORTING_

# include "../../putils/extra.h"
# include "../../putils/vec.h"

extern s32 compare_name (con nil * file_1, con nil * file_2);
extern s32 compare_is_dir (con nil * file_1, con nil * file_2);

extern vec * compare_functions;
extern nil option_sorting (str * options);

# endif // _OPTION_SORTING_

