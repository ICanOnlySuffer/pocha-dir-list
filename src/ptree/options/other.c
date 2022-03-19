# include "other.h"

nil option_other (str * options) {
	cse (**options) {
	whn 'v':
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
		NEW_LNE ();
		break;
		
	default:
		help (OTHER);
	}
	exit (0);
}

