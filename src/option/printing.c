# include "option/printing.h"

struct printing printing = {
	.colors = {"", "", "", "", ""},
	.size = false
};

nil str_frm_filesize (str buffer, u64 size) {
	if (size < 1000) {
		sprintf (buffer, "%3lluB", size);
	} else if (size < 1024 * 10) {
		sprintf (buffer, "%3.1fK", size / 1024.0);
	} else if (size < 1024 * 1000) {
		sprintf (buffer, "%3lluK", size / 1024);
	} else if (size < 1024 * 1024 * 10) {
		sprintf (buffer, "%3.1fM", size / 1024.0 / 1024);
	} else if (size < 1024 * 1000 * 1000) {
		sprintf (buffer, "%3lluM", size / 1024 / 1024);
	} else if (size < (u64) (1024 * 1024 * 1024) * 10) {
		sprintf (buffer, "%3.1fG", size / 1024.0 / 1024 / 1024);
	} else if (size < (u64) (1024) * 1000 * 1000 * 1000) {
		sprintf (buffer, "%3lluG", size / 1024 / 1024 / 1024);
	} else if (size < (u64) (1024) * 1024 * 1024 * 1024 * 10) {
		sprintf (buffer, "%3.1fT", size / 1024.0 / 1024 / 1024 / 1024);
	} else {
		sprintf (buffer, "%3lluT", size / 1024 * 1024 * 1024 * 1024);
	}
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
					
					if (STR_EQL (buffer, "di")) {
						color = printing.colors.di;
					} else if (STR_EQL (buffer, "fi")) {
						color = printing.colors.fi;
					} else if (STR_EQL (buffer, "ln")) {
						color = printing.colors.ln;
					} else if (STR_EQL (buffer, "ex")) {
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
		QUT (1);
	}
}

