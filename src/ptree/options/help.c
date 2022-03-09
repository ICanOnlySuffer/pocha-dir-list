# include "help.h"

nil help (enum option option) {
	switch (option) {
	case USAGE:
		PUT_ARR (
			LANG ("usage"), ": ptree [-Pacdls] [-Ldrha] [-Sdn]\n",
			LANG ("options")
		);
		break;
	case PRINTING:
		PUT_ARR (
			"  -P        ", LANG ("printing"), "\n"
			"    -a        ", LANG ("printing(a)"), "\n"
			"    -c        ", LANG ("printing(c)"), "\n"
			"    -d(DELAY) ", LANG ("printing(d)"), "\n"
			"    -l        ", LANG ("printing(l)"), "\n"
			"    -s        ", LANG ("printing(s)")
		);
		break;
	case LISTING:
		PUT_ARR (
			"  -L        ", LANG ("listing"), "\n"
			"    -d        ", LANG ("listing(d)"), "\n"
			"    -r        ", LANG ("listing(r)"), "\n"
			"    -h        ", LANG ("listing(h)"), "\n"
			"    -a        ", LANG ("listing(a)")
		);
		break;
	case SORTING:
		PUT_ARR (
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
	put_chr (STD_OUT, '\n');
}

