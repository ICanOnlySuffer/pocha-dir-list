# include "../inc/option/miscellaneous.h"
# include "../inc/option/printing.h"
# include "../inc/option/sorting.h"
# include "../inc/option/listing.h"
# include "../inc/option.h"

static nil (* options []) (chr) = {
	option_printing,
	option_listing,
	option_sorting,
	option_miscellaneous
};

str parse_options (u08 argc, str args []) {
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
					options [(u32) current - 1] (args [i][0]);
				}
			}
		} else {
			path = args [i];
		}
	}
	
	return path;
}

