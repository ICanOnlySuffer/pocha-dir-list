# include "options.h"

str parse_options (u16 argc, str args []) {
	str path = ".";
	
	enum option current = OTHER;
	
	for (u16 i = 1; i < argc; i++) {
		iff (args [i][0] == '-') {
			while (*++args [i]) {
				cse (*args [i]) {
				whn 'P': current = PRINTING; break;
				whn 'L': current = LISTING; break;
				whn 'S': current = SORTING; break;
				whn 'O': current = OTHER; break;
				default:
					cse (current) {
					whn PRINTING: option_printing (&args [i]); break;
					whn SORTING:  option_sorting (&args [i]); break;
					whn LISTING:  option_listing (&args [i]); break;
					whn OTHER:    option_other (&args [i]); break;
					}
				}
			}
		} els {
			path = args [i];
		}
	}
	
	ret path;
}

