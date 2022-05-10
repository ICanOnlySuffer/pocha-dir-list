# include "../../inc/option/listing.h"
# include <stdlib.h>

struct listing listing = {
	false,
	false,
	true,
	true
};

nil option_listing (chr option) {
	switch (option) {
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
		help (USAGE);
		help (LISTING);
		exit (1);
	}
}

