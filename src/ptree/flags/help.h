# ifndef _HELP_
# define _HELP_

# include "../utils/pstring.h"
# include "../utils/pstdio.h"
# include "../lang.h"

enum flag {
	PRINTING,
	SORTING,
	LISTING,
	NUMBER,
	OTHER
};

nil help (enum flag flag) {
	static tof called_already = false;
	
	if (not called_already) {
		called_already = true;
		pprint (
			LANG ("usage"), ": ptree [-Ldrha] [-Pacl] [-Sda]" \
			"\nOptions:\n"
		);
	}
	
	switch (flag) {
	case PRINTING:
		pputs (
			"  -P           ", LANG ("printing"),
			"\n    -a           ", LANG ("printing(a)"),
			"\n    -c           ", LANG ("printing(c)"),
			"\n    -d(DELAY)    ", LANG ("printing(d)"),
			"\n    -l           ", LANG ("printing(l)")
		);
		break;
	
	case LISTING:
		pputs (
			"  -L           ", LANG ("listing"),
			"\n    -d           ", LANG ("listing(d)"),
			"\n    -r           ", LANG ("listing(r)"),
			"\n    -h           ", LANG ("listing(h)"),
			"\n    -a           ", LANG ("listing(a)")
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
		help (PRINTING);
		help (LISTING);
		help (SORTING);
	}
}

# endif // _HELP_

















