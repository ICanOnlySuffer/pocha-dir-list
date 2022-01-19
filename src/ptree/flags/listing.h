# ifndef _FLAG_LISTING_
# define _FLAG_LISTING_

# include "help.h"

struct {
	u08 hidden_regs;
	u08 hidden_dirs;
	u08 regs;
	u08 dirs;
} listing = {
	false,
	false,
	true,
	true
};

nil flag_listing (str *args) {
	switch (**args) {
	case 'd':
		if (listing.hidden_regs) {
			listing.hidden_regs = false;
		}
		listing.dirs = true;
		listing.regs = false;
		break;
		
	case 'r':
		if (listing.hidden_dirs) {
			listing.hidden_dirs = false;
		}
		listing.regs = true;
		listing.dirs = false;
		break;
		
	case 'h':
		listing.hidden_regs = true;
		listing.hidden_dirs = true;
		listing.regs = false;
		listing.dirs = false;
		break;
		
	case 'a':
		listing.hidden_regs = true;
		listing.hidden_dirs = true;
		listing.regs = true;
		listing.dirs = true;
		break;
		
	default:
		help (LISTING);
		exit (1);
	}
}

# endif // _FLAG_LISTING_




