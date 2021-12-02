
switch (*args [i]) {
case 'c': // colors
	ix1 * ls_colors = getenv ("LS_COLORS");
	
	if (ls_colors && ls_colors [0]) {
		e01 reading = true;
		ix1 buffer [256];
		ix1 * color;
		
		for (ux1 i = 0, j = 2; ; ls_colors++) {
			if (reading) {
				if (*ls_colors == '=') {
					reading = false;
					buffer [i] = 0;
					if (!strcmp (buffer, "di")) {
						color = di_color;
					} else if (!strcmp (buffer, "fi")) {
						color = fi_color;
					} else if (!strcmp (buffer, "ln")) {
						color = ln_color;
					} else if (!strcmp (buffer, "ex")) {
						color = ex_color;
					} else {
						color = buffer;
					}
					color [0] = '\e';
					color [1] = '[';
				} else {
					buffer [i++] = *ls_colors;
				}
			} else { // writing
				if (*ls_colors == ':') {
					reading = true;
					color [j] = 'm';
					i = 0;
					j = 2;
				} else if (!*ls_colors) {
					color [j] = 'm';
					break;
				} else {
					color [j++] = *ls_colors;
				}
			}
		}
	}
	break;
case 'l':
	loop = true;
	break;
case 'd':
	previous = current;
	current = NUMBER;
	number = &delay;
	break;
default:
	help (PRINTING);
	return;
}



