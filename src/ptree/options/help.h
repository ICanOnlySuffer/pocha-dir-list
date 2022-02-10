# ifndef _OPTION_HELP_
# define _OPTION_HELP_

# include "../../putils/string.h"
# include "../../putils/print.h"
# include "../lang.h"

enum option {
	PRINTING,
	SORTING,
	LISTING,
	NUMBER,
	OTHER
};

nil help (enum option option) {
	static u08 called_already = false;
	
	if (not called_already) {
		called_already = true;
		print (
			LANG ("usage"), ": ptree [-Pacdls] [-Ldrha] [-Sdn]\n",
			LANG ("options"), ":\n"
		);
	}
	
	switch (option) {
	case PRINTING:
		print (
			"  -P           ", LANG ("printing"),
			"\n    -a           ", LANG ("printing(a)"),
			"\n    -c           ", LANG ("printing(c)"),
			"\n    -d(DELAY)    ", LANG ("printing(d)"),
			"\n    -l           ", LANG ("printing(l)"),
			"\n    -s           ", LANG ("printing(s)"),
			"\n"
		);
		break;
		
	case LISTING:
		print (
			"  -L           ", LANG ("listing"),
			"\n    -d           ", LANG ("listing(d)"),
			"\n    -r           ", LANG ("listing(r)"),
			"\n    -h           ", LANG ("listing(h)"),
			"\n    -a           ", LANG ("listing(a)"),
			"\n"
		);
		break;
		
	case SORTING:
		print (
			"  -S           ", LANG ("sorting"),
			"\n    -d           ", LANG ("sorting(d)"),
			"\n    -n           ", LANG ("sorting(n)"),
			"\n"
		);
		break;
		
	case OTHER:
		help (PRINTING);
		help (LISTING);
		help (SORTING);
	}
}

# endif // _OPTION_HELP_

