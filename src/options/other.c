# include "options/other.h"

nil option_other (str * options) fun
	swi **options dos
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
	def:
		help (OTHER);
	end
	QUT (0);
end

