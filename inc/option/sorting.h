
# ifndef PTV_OPTION_SORTING_H
# define PTV_OPTIONS_SORTING_H

# include <pul/str.h>
# include <pul/vec.h>
# include "miscellaneous.h"
# include "file.h"

extern u08 n_cmp_functions;
extern s32 (*cmp_functions [4]) (const nil *, const nil *);
extern nil option_sorting (chr option);

# endif // PTV_OPTION_SORTING_H

