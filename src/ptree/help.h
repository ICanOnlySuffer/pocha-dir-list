# include "utils/pstdio.h"
# include "flags/flags.h"
# include "lang.h"
# pragma once

nil help (enum flag flag) {
	switch (flag) {
	case LISTING:
		pputs (
			"  -L           ", LANG ("listing"),
			"\n    -d           ", LANG ("listing(d)"),
			"\n    -r           ", LANG ("listing(r)"),
			"\n    -h           ", LANG ("listing(h)"),
			"\n    -a           ", LANG ("listing(a)")
		);
		break;
		
	case PRINTING:
		pputs (
			"  -P           ", LANG ("printing"),
			"\n    -a           ", LANG ("printing(a)"),
			"\n    -c           ", LANG ("printing(c)"),
			"\n    -d(DELAY)    ", LANG ("printing(d)"),
			"\n    -l           ", LANG ("printing(l)")
		);
		break;
		
	case SORTING:
		pputs (
			"  -S           ", LANG ("sorting"),
			"\n    -d           ", LANG ("sorting(d)"),
			"\n    -a           ", LANG ("sorting(a)")
		);
		break;
		
	case OTHER:
		pputs (LANG ("usage"), ": ptree [-Ldrha] [-Pacl] [-Sda]");
		help (PRINTING);
		help (SORTING);
		help (LISTING);
	}
}



















