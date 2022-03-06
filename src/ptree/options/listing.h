
# ifndef _PTREE_OPTIONS_LISTING_
# define _PTREE_OPTIONS_LISTING_

# include "../../putils/extra.h"

extern struct {
	u08 hidden_regs;
	u08 hidden_dirs;
	u08 regs;
	u08 dirs;
} listing;

extern nil option_listing (str * args);

# endif // _PTREE_OPTIONS_LISTING_

