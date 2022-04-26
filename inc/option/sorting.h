
# ifndef PTV_OPTION_SORTING_H
# define PTV_OPTIONS_SORTING_H

# include <pul/str.h>
# include <pul/vec.h>
# include "miscellaneous.h"
# include "file.h"

EXT u08 n_cmp_functions;
EXT s32 (*cmp_functions [4]) (con nil *, con nil *);
EXT nil option_sorting (chr option);

# endif // PTV_OPTION_SORTING_H

