# ifndef _FLAG_OTHER_
# define _FLAG_OTHER_

# include "help.h"
# define VERSION "1.0.3"

nil version () {
	pputs (
		"ptree v" VERSION " - ICanOnlySuffer (Piero Rojas)\n",
		LANG ("credits"), "\n" \
		"  Steve Baker\n"    \
		"  Thomas Moore\n"    \
		"  Francesc Rocher\n" \
		"  Florian Sesser\n"  \
		"  Kyosuke Tokoro\n",
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

# endif // _FLAG_OTHER_






