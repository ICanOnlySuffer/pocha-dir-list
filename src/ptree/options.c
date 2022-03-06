# include "options/printing.h"
# include "options/sorting.h"
# include "options/listing.h"
# include "options/number.h"
# include "options/other.h"
# include "options/help.h"

str parse_options (u16 argc, str args []) {
	str path = ".";
	
	enum option current = OTHER;
	
	for (u16 i = 1; i < argc; i++) {
		if (args [i][0] == '-') {
			while (*++args [i]) {
				switch (*args [i]) {
				case 'P': current = PRINTING; break;
				case 'L': current = LISTING; break;
				case 'S': current = SORTING; break;
				case 'O': current = OTHER; break;
				default:
					switch (current) {
					case PRINTING: option_printing (&args [i]); break;
					case SORTING:  option_sorting (&args [i]); break;
					case LISTING:  option_listing (&args [i]); break;
					case OTHER:    option_other (&args [i]); break;
					}
				}
			}
		} else {
			path = args [i];
		}
	}
	
	return path;
}

