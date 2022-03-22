
# ifndef PTREE_OPTIONS_HELP_H
# define PTREE_OPTIONS_HELP_H

# include <putils/put.h>
# include "../lang.h"

enm option {
	USAGE,
	PRINTING,
	SORTING,
	LISTING,
	NUMBER,
	OTHER
};

ext nil help (enm option option);

# endif // PTREE_OPTIONS_HELP_H

