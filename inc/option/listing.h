
# ifndef PDL_OPTION_LISTING_H
# define PDL_OPTION_LISTING_H

# include "misc.h"

ext struct listing {
	u08 hidden_regs;
	u08 hidden_dirs;
	u08 regs;
	u08 dirs;
} listing;
ext nil option_listing (chr option);

# endif // PDL_OPTION_LISTING_H

