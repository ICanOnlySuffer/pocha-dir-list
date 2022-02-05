# ifndef _OPTION_NUMBER_
# define _OPTION_NUMBER_

# include <stdlib.h>
# include "help.h"

u32 parse_number (str *args) {
	chr buffer [8] = {0};
	
	for (u08 i = 0; '0' <= *(*args + 1) && *(*args + 1) <= '9';) {
		buffer [i++] = *(++*args);
	}
	
	return atoi (buffer);
}

# endif // _OPTION_NUMBER_
