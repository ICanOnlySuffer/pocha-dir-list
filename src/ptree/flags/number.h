# include <stdlib.h>
# include <stdio.h>
# include "../utils/types.h"
# pragma once

ux4 parse_number (str *args) {
	ix1 buffer [8] = {0};
	
	for (ux1 i = 0; '0' <= *(*args + 1) && *(*args + 1) <= '9';) {
		buffer [i++] = *(++*args);
	}
	
	return atoi (buffer);
}








