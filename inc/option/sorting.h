
# ifndef PTV_OPTION_SORTING_H
# define PTV_OPTION_SORTING_H

# include "miscellaneous.h"
# include "../file.h"

ext u08 n_cmp_functions;
ext s32 (*cmp_functions [4]) (const nil *, const nil *);
ext nil option_sorting (chr option);

# endif // PTV_OPTION_SORTING_H

