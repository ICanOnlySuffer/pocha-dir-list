# include "option/miscellaneous.h"

nil help (chr option) {
	switch (option) {
	case USAGE:
		PUT_ARR (
			LANG ('u', 's', 'e'),
			": ptv [", LANG ('O', 'P', 'T'), "]...\n",
			LANG ('o', 'p', 't'), ":"
		);
		break;
	case PRINTING:
		PUT_ARR (
			"  -P    ", LANG ('p', 'u', 't'), "\n"
			"    -c    ", LANG ('p', 'u', 't', '.', 'c'), "\n"
			"    -s    ", LANG ('p', 'u', 't', '.', 's')
		);
		break;
	case LISTING:
		PUT_ARR (
			"  -L    ", LANG ('l', 's', 't'), "\n"
			"    -d    ", LANG ('l', 's', 't', '.', 'd'), "\n"
			"    -r    ", LANG ('l', 's', 't', '.', 'r'), "\n"
			"    -h    ", LANG ('l', 's', 't', '.', 'h'), "\n"
			"    -a    ", LANG ('l', 's', 't', '.', 'a')
		);
		break;
	case SORTING:
		PUT_ARR (
			"  -S    ", LANG ('s', 'r', 't'), "\n"
			"    -d    ", LANG ('s', 'r', 't', '.', 'd'), "\n"
			"    -n    ", LANG ('s', 'r', 't', '.', 'n')
		);
		break;
	case MISCELLANEOUS:
		PUT_ARR (
			"  -M    ", LANG ('m', 's', 'c'), "\n"
			"    -v    ", LANG ('m', 's', 'c', '.', 'v'), "\n"
			"    -h    ", LANG ('m', 's', 'c', '.', 'h')
		);
		break;
	default:
		help (USAGE);
		help (PRINTING);
		help (LISTING);
		help (SORTING);
		help (MISCELLANEOUS);
		return;
	}
	new_lne ();
}

nil option_miscellaneous (chr option) {
	switch (option) {
	case 'v':
		put (
			",-. -,- , , Pocha's Tree Visualizer " VERSION "\n"
			"| |  |  | |\n"
			"|-´  |  | | Copyright (c) 2022 " DEVELOPER "\n"
			"'    '  `.´ " LICENSE "\n"
		);
		break;
	case 'h':
		help ('0');
		break;
	default:
		help ('0');
		exit (1);
	}
	exit (0);
}

