
enum flag current = OTHER;
enum flag previous = OTHER;

ix1 number_buffer [8] = "0";
ux1 number_buffer_index = 0;
ux4 * number;

for (ux1 i = 1; i < argc; i++) {
	if (args [i][0] == '-') {
		while (*++args [i]) {
			switch (*args [i]) {
			case 'P':
				current = PRINTING;
				break;
			case 'L':
				current = LISTING;
				break;
			case 'S':
				current = SORTING;
				break;
			case 'O':
				current = OTHER;
				break;
			default:
				switch (current) {
				case PRINTING:
					# include "flags/printing.h"
					break;
				case SORTING:
					# include "flags/sorting.h"
					break;
				case LISTING:
					# include "flags/listing.h"
					break;
				case NUMBER:
					# include "flags/number.h"
					break;
				case OTHER:
					# include "flags/other.h"
					break;
				}
			}
		}
	} else {
		path = args [i];
	}
}

if (current == NUMBER) {
	*number = atoi (number_buffer);
}









