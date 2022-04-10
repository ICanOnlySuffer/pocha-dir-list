# include "option/listing.h"

struct listing listing = {
	false,
	false,
	true,
	true
};

nil option_listing (chr option) FUN
	SWI option DOS
	WHN 'd':
		IFF listing.hidden_regs DOS
			listing.hidden_regs = false;
		END
		listing.dirs = true;
		listing.regs = false;
		BRK;
	WHN 'r':
		IFF listing.hidden_dirs DOS
			listing.hidden_dirs = false;
		END
		listing.regs = true;
		listing.dirs = false;
		BRK;
	WHN 'h':
		listing.hidden_regs = true;
		listing.hidden_dirs = true;
		listing.regs = false;
		listing.dirs = false;
		BRK;
	WHN 'a':
		listing.hidden_regs = true;
		listing.hidden_dirs = true;
		listing.regs = true;
		listing.dirs = true;
		BRK;
	default:
		help (LISTING);
		QUT (1);
	END
END

