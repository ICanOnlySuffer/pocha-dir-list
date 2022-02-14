# ifndef _OPTION_VERSION_
# define _OPTION_VERSION_
# define VERSION "1.1.4"
# include "../lang.h"

nil version () {
	puts ("ptree v" VERSION " - Piero Estéfano Rojas Effio");
	puts ("* https://github.com/ICanOnlySuffer/ptree");
	puts (LANG ("credits"));
	puts (
		"  Steve Baker\n"
		"  Thomas Moore\n"
		"  Francesc Rocher\n"
		"  Florian Sesser\n"
		"  Kyosuke Tokoro"
	);
	puts (LANG ("copyright"));
}

# endif // _OPTION_VERSION_

