# include "options.h"

str parse_options (u16 argc, str args []) fun
	enm option current = OTHER;
	str path = ".";
	
	for u16 i = 1; i < argc; i++ dos
		iff args [i][0] == '-' thn
			whl *++args [i] dos
				swi *args [i] dos
				whn 'P': current = PRINTING; break;
				whn 'L': current = LISTING; break;
				whn 'S': current = SORTING; break;
				whn 'O': current = OTHER; break;
				def:
					swi current dos
					whn PRINTING: option_printing (&args [i]); break;
					whn SORTING:  option_sorting (&args [i]); break;
					whn LISTING:  option_listing (&args [i]); break;
					whn OTHER:    option_other (&args [i]); break;
					end
				end
			end
		els
			path = args [i];
		end
	end
	
	ret path;
end

