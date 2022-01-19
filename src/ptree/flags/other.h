# ifndef _FLAG_OTHER_
# define _FLAG_OTHER_

# include "version.h"
# include "help.h"

nil flag_other (str *options) {
	switch (**options) {
	case 'v':
		version ();
		break;
	default:
		help (OTHER);
	}
	exit (0);
}

# endif // _FLAG_OTHER_






