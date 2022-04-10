# include "option.h"

str parse_options (u16 argc, str args []) FUN
	chr current = MISCELLANEOUS;
	str path = ".";
	
	FOR u16 i = 1; i < argc; i++ DOS
		IFF args [i][0] == '-' THN
			WHL *++args [i] DOS
				SWI *args [i] DOS
				WHN 'P': current = PRINTING; BRK;
				WHN 'L': current = LISTING; BRK;
				WHN 'S': current = SORTING; BRK;
				WHN 'M': current = MISCELLANEOUS; BRK;
				default:
					SWI current DOS
					WHN PRINTING:
						option_printing (args [i][0]);
						BRK;
					WHN SORTING:
						option_sorting (args [i][0]);
						BRK;
					WHN LISTING:
						option_listing (args [i][0]);
						BRK;
					WHN MISCELLANEOUS:
						option_miscellaneous (args [i][0]);
						BRK;
					END
				END
			END
		ELS
			path = args [i];
		END
	END
	
	RET path;
END

