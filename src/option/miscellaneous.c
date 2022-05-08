# include "../../inc/option/miscellaneous.h"
# include "../../inc/buffer.h"
# include "../../inc/lang.h"

nil help (chr option) {
	switch (option) {
	case USAGE:
		STR_CPY (
			BUFFER,
			LANG ('u', 's', 'e'),
			": ptv [", LANG ('O', 'P', 'T'), "]...\n",
			LANG ('o', 'p', 't'), ":"
		);
		break;
	case PRINTING:
		STR_CPY (
			BUFFER,
			"  -P    ", LANG ('p', 'u', 't'), "\n"
			"    -c    ", LANG ('p', 'u', 't', '.', 'c'), "\n"
			"    -s    ", LANG ('p', 'u', 't', '.', 's')
		);
		break;
	case LISTING:
		STR_CPY (
			BUFFER,
			"  -L    ", LANG ('l', 's', 't'), "\n"
			"    -d    ", LANG ('l', 's', 't', '.', 'd'), "\n"
			"    -r    ", LANG ('l', 's', 't', '.', 'r'), "\n"
			"    -h    ", LANG ('l', 's', 't', '.', 'h'), "\n"
			"    -a    ", LANG ('l', 's', 't', '.', 'a')
		);
		break;
	case SORTING:
		STR_CPY (
			BUFFER,
			"  -S    ", LANG ('s', 'r', 't'), "\n"
			"    -d    ", LANG ('s', 'r', 't', '.', 'd'), "\n"
			"    -n    ", LANG ('s', 'r', 't', '.', 'n')
		);
		break;
	case MISCELLANEOUS:
		STR_CPY (
			BUFFER,
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
	put (BUFFER);
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

