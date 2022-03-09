# include "printing.h"

struct printing printing = {
	.alternative = false,
	.colors = {"", "", "", ""},
	.delay = 10,
	.loop = false,
	.size = false
};

nil parse_colors () {
	str env_colors = getenv ("LS_COLORS");
	
	if (env_colors and *env_colors) {
		u08 reading = true;
		chr buffer [16];
		str color;
		
		for (u08 i = 0, j = 2; ; env_colors++) {
			if (reading) {	
				if (*env_colors == '=') {
					reading = false;
					buffer [i] = 0;
					
					if (streql (buffer, "di")) {
						color = printing.colors.di;
					} else if (streql (buffer, "fi")) {
						color = printing.colors.fi;
					} else if (streql (buffer, "ln")) {
						color = printing.colors.ln;
					} else if (streql (buffer, "ex")) {
						color = printing.colors.ex;
					} else {
						color = buffer;
					}
					
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

nil option_printing (str * args) {
	switch (**args) {
	case 'd': printing.delay = parse_number (args); break;
	case 'a': printing.alternative = true; break;
	case 'l': printing.loop = true; break;
	case 's': printing.size = true; break;
	case 'c': parse_colors (); break;
	default:
		help (PRINTING);
		exit (1);
	}
}

