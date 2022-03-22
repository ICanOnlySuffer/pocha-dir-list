
# ifndef PTREE_OPTIONS_LISTING_H
# define PTREE_OPTIONS_LISTING_H

# include "help.h"

struct listing {
	u08 hidden_regs;
	u08 hidden_dirs;
	u08 regs;
	u08 dirs;
};

ext struct listing listing;
ext nil option_listing (str * args);

# endif // PTREE_OPTIONS_LISTING_H

