# include "help.h"

# define VERSION "1.1.5"

nil option_other (str * options) {
	switch (**options) {
	case 'v':
		PUT_ARR (
			"ptree v" VERSION " - Piero Estéfano Rojas Effio\n"
			"* https://github.com/ICanOnlySuffer/ptree\n",
			LANG ("credits"), "\n"
			"  Steve Baker\n"
			"  Thomas Moore\n"
			"  Francesc Rocher\n"
			"  Florian Sesser\n"
			"  Kyosuke Tokoro\n",
			LANG ("copyright")
		);
		put_chr (STD_OUT, '\n');
		break;
		
	default:
		help (OTHER);
	}
	exit (0);
}

