# include "option.h"

str parse_options (u16 argc, str args []) {
	chr current = MISCELLANEOUS;
	str path = ".";
	
	for (u16 i = 1; i < argc; i++) {
		if (args [i][0] == '-') {
			while (*++args [i]) {
				switch (*args [i]) {
				case 'P': current = PRINTING; break;
				case 'L': current = LISTING; break;
				case 'S': current = SORTING; break;
				case 'M': current = MISCELLANEOUS; break;
				default:
					switch (current) {
					case PRINTING:
						option_printing (args [i][0]);
						break;
					case SORTING:
						option_sorting (args [i][0]);
						break;
					case LISTING:
						option_listing (args [i][0]);
						break;
					case MISCELLANEOUS:
						option_miscellaneous (args [i][0]);
						break;
					}
				}
			}
		} else {
			path = args [i];
		}
	}
	
	return path;
}

