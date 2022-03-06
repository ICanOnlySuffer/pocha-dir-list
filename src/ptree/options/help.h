
# ifndef _PTREE_OPTIONS_HELP_
# define _PTREE_OPTIONS_HELP_

# include "../../putils/extra.h"
# include <stdlib.h>

enum option {
	PRINTING,
	SORTING,
	LISTING,
	NUMBER,
	OTHER
};

extern nil help (enum option option);

# endif // _PTREE_OPTIONS_HELP_

