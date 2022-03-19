
# ifndef _PTREE_OPTIONS_HELP_
# define _PTREE_OPTIONS_HELP_

# include "../../putils/put.h"
# include "../lang.h"
# include <stdlib.h>

enum option {
	USAGE,
	PRINTING,
	SORTING,
	LISTING,
	NUMBER,
	OTHER
};

extern nil help (enum option option);

# endif // _PTREE_OPTIONS_HELP_

