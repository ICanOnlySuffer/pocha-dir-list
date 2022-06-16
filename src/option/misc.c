# include "../../inc/option/misc.h"
# include "../../inc/buffer.h"
# include "../../inc/lang.h"
# include <pocha/ver.h>
# include <stdlib.h>

# if LIBPOCHA_VERSION_MAYOR != 0 or LIBPOCHA_VERSION_MINOR != 7
# error `libpocha` version must be 0.7.x
# endif

nil help (chr option) {
	switch (option) {
	case USAGE:
		STR_CPY (
			BUFFER,
			LANG_USE, ": pdt [", LANG_OPT, "]...\n",
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
	case MISC:
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
		help (MISC);
		ret;
	}
	put (BUFFER);
	new_lne ();
}

nil option_misc (chr option) {
	switch (option) {
	case 'v':
		put (
			"Pocha Dir List v1.7.0\n"
			"Copyright (c) 2022 Piero Rojas\n"
			"GNU General Public License v3.0\n"
		);
		break;
	case 'h':
		help ('0');
		break;
	default:
		help (USAGE);
		help (MISC);
		exit (1);
	}
	exit (0);
}

