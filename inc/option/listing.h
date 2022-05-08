
# ifndef PTV_OPTION_LISTING_H
# define PTV_OPTION_LISTING_H

# include "miscellaneous.h"

ext struct listing {
	u08 hidden_regs;
	u08 hidden_dirs;
	u08 regs;
	u08 dirs;
} listing;
ext nil option_listing (chr option);

# endif // PTV_OPTION_LISTING_H

