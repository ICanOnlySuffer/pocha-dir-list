# ifndef _FLAGS_
# define _FLAGS_

# include "flags/printing.h"
# include "flags/sorting.h"
# include "flags/listing.h"
# include "flags/number.h"
# include "flags/other.h"

str parse_flags (ux1 argc, str args []) {
	str path = ".";
	
	enum flag current = OTHER;
	
	for (ux1 i = 1; i < argc; i++) {
		if (args [i][0] == '-') {
			while (*++args [i]) {
				switch (*args [i]) {
				case 'P': current = PRINTING; break;
				case 'L': current = LISTING; break;
				case 'S': current = SORTING; break;
				case 'O': current = OTHER; break;
				default:
					switch (current) {
					case PRINTING: flag_printing (&args [i]); break;
					case SORTING:  flag_sorting (&args [i]); break;
					case LISTING:  flag_listing (&args [i]); break;
					case OTHER:    flag_other (&args [i]); break;
					}
				}
			}
		} else {
			path = args [i];
		}
	}
	
	return path;
}

# endif // _FLAGS_






