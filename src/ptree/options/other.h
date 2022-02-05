# ifndef _OPTION_OTHER_
# define _OPTION_OTHER_

# include "version.h"
# include "help.h"

nil option_other (str *options) {
	switch (**options) {
	case 'v':
		version ();
		break;
	default:
		help (OTHER);
	}
	exit (0);
}

# endif // _OPTION_OTHER_






