# include "../help.h"
# pragma once

struct {
	tof hidden_regs;
	tof hidden_dirs;
	tof regs;
	tof dirs;
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
		break;
		
	case 'r':
		if (listing.hidden_dirs) {
			listing.hidden_dirs = false;
		}
		listing.regs = true;
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






