# include "../../inc/option/misc.h"
# include "../../inc/buffer.h"
# include "../../inc/lang.h"
# include <pocha/ver.h>
# include <pocha/ioe.h>
# include <stdlib.h>

# if LIBPOCHA_VERSION_MAYOR != 0 or LIBPOCHA_VERSION_MINOR != 8
# error `libpocha` version must be 0.8.x
# endif

nil help (chr option) {
	switch (option) {
	case USAGE:
		STR_COPY (
			BUFFER,
			LANG_USE, ": pdt [", LANG_OPT, "]...\n",
			LANG_OPTS, ":"
		);
		break;
	case PRINTING:
		STR_COPY (
			BUFFER,
			"-P (", LANG_PUT, "):\n"
			"  -c  ", LANG_PUT_C, "\n"
			"  -s  ", LANG_PUT_S
		);
		break;
	case LISTING:
		STR_COPY (
			BUFFER,
			"-L (", LANG_LST, "):\n"
			"  -d  ", LANG_LST_D, "\n"
			"  -r  ", LANG_LST_R, "\n"
			"  -h  ", LANG_LST_H, "\n"
			"  -a  ", LANG_LST_A
		);
		break;
	case SORTING:
		STR_COPY (
			BUFFER,
			"-S (", LANG_SRT, "):\n"
			"  -d  ", LANG_SRT_D, "\n"
			"  -n  ", LANG_SRT_N
		);
		break;
	case MISC:
		STR_COPY (
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
	put_chr ('\n');
}

nil option_misc (chr option) {
	switch (option) {
	case 'v':
		put (
			"Pocha Dir List v1.7.1\n"
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

