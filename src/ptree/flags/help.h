# ifndef _PTREE_HELP_
# define _PTREE_HELP_

# include <putils/string.h>
# include <putils/stdio.h>
# include "../lang.h"

enum flag {
	PRINTING,
	SORTING,
	LISTING,
	NUMBER,
	OTHER
};

nil help (enum flag flag) {
	static u08 called_already = false;
	
	if (not called_already) {
		called_already = true;
		pprint (
			LANG ("usage"), ": ptree [-Pacdl] [-Ldrha] [-Sdn]" \
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
			"\n    -l           ", LANG ("printing(l)"),
			"\n    -s           ", LANG ("printing(s)")
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
			"\n    -n           ", LANG ("sorting(n)")
		);
		break;
		
	case OTHER:
		help (PRINTING);
		help (LISTING);
		help (SORTING);
	}
}

# endif // _PTREE_HELP_

















