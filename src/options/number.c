# include "options/number.h"

u32 parse_number (str * args) fun
	chr buffer [8] = {0};
	
	for u08 i = 0; '0' <= *(*args + 1) && *(*args + 1) <= '9'; dos
		buffer [i++] = *(++*args);
	end
	
	ret atoi (buffer);
end

