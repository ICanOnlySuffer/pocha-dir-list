# include "../../inc/option/printing.h"
# include <pul/str.h>
# include <stdlib.h>

struct printing printing = {
	.colors = {"", "", "", "", ""},
	.size = false
};

nil str_frm_filesize (str destine, u64 size) {
	chr character;
	if (size < 9999lu) {
		character = 'B';
	} else if (size < 9999lu * 1024) {
		character = 'K';
		size /= 1024;
	} else if (size < 9999lu * 1024 * 1024) {
		character = 'M';
		size /= 1024 * 1024;
	} else {
		character = 'G';
		size /= 1024 * 1024 * 1024;
	}
	u08 len = size < 10 ? 1 : size < 100 ? 2 : size < 1000 ? 3 : 4;
	str_frm_u64 (destine + 4 - len, size);
	destine [4] = character;
}

nil parse_colors () {
	str env_colors = getenv ("LS_COLORS");
	printing.colors.reset = "\e[0m";
	
	if (env_colors and *env_colors) {
		u08 reading = true;
		chr buffer [16];
		str color;
		
		for (u08 i = 0, j = 2; ; env_colors++) {
			if (reading) {
				if (*env_colors == '=') {
					reading = false;
					buffer [i] = 0;
					
					if (str_eql (buffer, "di")) {
						color = printing.colors.di;
					} else if (str_eql (buffer, "fi")) {
						color = printing.colors.fi;
					} else if (str_eql (buffer, "ln")) {
						color = printing.colors.ln;
					} else if (str_eql (buffer, "ex")) {
						color = printing.colors.ex;
					} else {
						color = buffer;
					} // add more here
					
					color [0] = '\e';
					color [1] = '[';
				} else {
					buffer [i++] = *env_colors;
				}
			} else { // writing
				if (*env_colors == ':') {
					reading = true;
					color [j] = 'm';
					i = 0;
					j = 2;
				} else if (not *env_colors) {
					color [j] = 'm';
					break;
				} else {
					color [j++] = *env_colors;
				}
			}
		}
	}
}

nil option_printing (chr option) {
	switch (option) {
	case 's': printing.size = true; break;
	case 'c': parse_colors (); break;
	default:
		help (PRINTING);
		exit (1);
	}
}

