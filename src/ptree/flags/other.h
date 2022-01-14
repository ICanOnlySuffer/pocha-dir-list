# include "../help.h"
# define VERSION "1.0.0"
# pragma once

nil version () {
	pputs (
		"ptree v", VERSION, " - ICanOnlySuffer (Piero Rojas)\n",
		LANG ("credits"), "\n" \
		"  Steve Baker,\n"    \
		"  Thomas Moore\n"    \
		"  Francesc Rocher\n" \
		"  Florian Sesser\n"  \
		"  Kyosuke Tokoro",
		LANG ("copyright")
	);
}

nil flag_other (str *options) {
	switch (**options) {
	case 'v':
		version ();
		exit (0);
	default:
		help (OTHER);
		exit (0);
	}
}







