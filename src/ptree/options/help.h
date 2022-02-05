# ifndef _OPTION_HELP_
# define _OPTION_HELP_

# include "../../putils/string.h"
# include "../../putils/stdio.h"
# include "../../putils/lang.h"

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
			lang_get ("usage"), ": ptree [-Pacdls] [-Ldrha] [-Sdn]" \
			"\nOptions:\n"
		);
	}
	
	switch (option) {
	case PRINTING:
		print (
			"  -P           ", lang_get ("printing"),
			"\n    -a           ", lang_get ("printing(a)"),
			"\n    -c           ", lang_get ("printing(c)"),
			"\n    -d(DELAY)    ", lang_get ("printing(d)"),
			"\n    -l           ", lang_get ("printing(l)"),
			"\n    -s           ", lang_get ("printing(s)"),
			"\n"
		);
		break;
		
	case LISTING:
		print (
			"  -L           ", lang_get ("listing"),
			"\n    -d           ", lang_get ("listing(d)"),
			"\n    -r           ", lang_get ("listing(r)"),
			"\n    -h           ", lang_get ("listing(h)"),
			"\n    -a           ", lang_get ("listing(a)"),
			"\n"
		);
		break;
		
	case SORTING:
		print (
			"  -S           ", lang_get ("sorting"),
			"\n    -d           ", lang_get ("sorting(d)"),
			"\n    -n           ", lang_get ("sorting(n)"),
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

