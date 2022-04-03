
# ifndef PTREE_OPTION_LISTING_H
# define PTREE_OPTION_LISTING_H

# include "miscellaneous.h"

struct listing {
	u08 hidden_regs;
	u08 hidden_dirs;
	u08 regs;
	u08 dirs;
};

ext struct listing listing;
ext nil option_listing (chr option);

# endif // PTREE_OPTION_LISTING_H

