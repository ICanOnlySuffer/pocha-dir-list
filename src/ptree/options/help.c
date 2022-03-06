# include "../../putils/str-cpy.h"
# include "../../putils/print.h"
# include "../../putils/extra.h"
# include "../../putils/ioe.h"
# include "../lang.h"

enum option {
	USAGE,
	PRINTING,
	SORTING,
	LISTING,
	NUMBER,
	OTHER
};

nil help (enum option option) {
	switch (option) {
	case USAGE:
		print_many (
			LANG ("usage"), ": ptree [-Pacdls] [-Ldrha] [-Sdn]\n",
			LANG ("options")
		);
		break;
	case PRINTING:
		print_many (
			"  -P        ", LANG ("printing"), "\n"
			"    -a        ", LANG ("printing(a)"), "\n"
			"    -c        ", LANG ("printing(c)"), "\n"
			"    -d(DELAY) ", LANG ("printing(d)"), "\n"
			"    -l        ", LANG ("printing(l)"), "\n"
			"    -s        ", LANG ("printing(s)")
		);
		break;
	case LISTING:
		print_many (
			"  -L        ", LANG ("listing"), "\n"
			"    -d        ", LANG ("listing(d)"), "\n"
			"    -r        ", LANG ("listing(r)"), "\n"
			"    -h        ", LANG ("listing(h)"), "\n"
			"    -a        ", LANG ("listing(a)")
		);
		break;
	case SORTING:
		print_many (
			"  -S        ", LANG ("sorting"), "\n"
			"    -d        ", LANG ("sorting(d)"), "\n"
			"    -n        ", LANG ("sorting(n)")
		);
		break;
	case OTHER:
		help (USAGE);
		help (PRINTING);
		help (LISTING);
		help (SORTING);
	}
	put_chr ('\n');
}

