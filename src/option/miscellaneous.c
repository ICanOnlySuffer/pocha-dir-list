# include "../../inc/option/miscellaneous.h"
# include "../../inc/buffer.h"
# include "../../inc/lang.h"
# include <pul/ver.h>
# include <stdlib.h>

# if PUL_VERSION_MAYOR != 0 or PUL_VERSION_MINOR != 6
# error `libpul` version must be 0.6.x
# endif

nil help (chr option) {
	switch (option) {
	case USAGE:
		STR_CPY (
			BUFFER,
			LANG_USE, ": ptv [", LANG_OPT, "]...\n",
			LANG_OPTS, ":"
		);
		break;
	case PRINTING:
		STR_CPY (
			BUFFER,
			"-P (", LANG_PUT, "):\n"
			"  -c  ", LANG_PUT_C, "\n"
			"  -s  ", LANG_PUT_S
		);
		break;
	case LISTING:
		STR_CPY (
			BUFFER,
			"-L (", LANG_LST, "):\n"
			"  -d  ", LANG_LST_D, "\n"
			"  -r  ", LANG_LST_R, "\n"
			"  -h  ", LANG_LST_H, "\n"
			"  -a  ", LANG_LST_A
		);
		break;
	case SORTING:
		STR_CPY (
			BUFFER,
			"-S (", LANG_SRT, "):\n"
			"  -d  ", LANG_SRT_D, "\n"
			"  -n  ", LANG_SRT_N
		);
		break;
	case MISCELLANEOUS:
		STR_CPY (
			BUFFER,
			"-M (", LANG_MSC, "):\n"
			"  -v  ", LANG_MSC_V, "\n"
			"  -h  ", LANG_MSC_H
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
		help (USAGE);
		help (MISCELLANEOUS);
		exit (1);
	}
	exit (0);
}

