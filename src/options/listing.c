# include "options/listing.h"

struct listing listing = {
	false,
	false,
	true,
	true
};

nil option_listing (str * args) fun
	swi **args dos
	whn 'd':
		iff listing.hidden_regs thn
			listing.hidden_regs = false;
		end
		listing.dirs = true;
		listing.regs = false;
		break;
	whn 'r':
		iff listing.hidden_dirs thn
			listing.hidden_dirs = false;
		end
		listing.regs = true;
		listing.dirs = false;
		break;
	whn 'h':
		listing.hidden_regs = true;
		listing.hidden_dirs = true;
		listing.regs = false;
		listing.dirs = false;
		break;
	whn 'a':
		listing.hidden_regs = true;
		listing.hidden_dirs = true;
		listing.regs = true;
		listing.dirs = true;
		break;
	def:
		help (LISTING);
		QUT (1);
	end
end

