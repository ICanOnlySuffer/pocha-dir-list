# include "option.h"

str parse_options (u16 argc, str args []) FUN
	chr current = MISCELLANEOUS;
	str path = ".";
	
	FOR u16 i = 1; i < argc; i++ DOS
		IFF args [i][0] == '-' THN
			WHL *++args [i] DOS
				SWI *args [i] DOS
				WHN 'P': current = PRINTING; break;
				WHN 'L': current = LISTING; break;
				WHN 'S': current = SORTING; break;
				WHN 'M': current = MISCELLANEOUS; break;
				default:
					SWI current DOS
					WHN PRINTING:
						option_printing (args [i][0]);
						break;
					WHN SORTING:
						option_sorting (args [i][0]);
						break;
					WHN LISTING:
						option_listing (args [i][0]);
						break;
					WHN MISCELLANEOUS:
						option_miscellaneous (args [i][0]);
						break;
					END
				END
			END
		ELS
			path = args [i];
		END
	END
	
	ret path;
END

