# include "option/miscellaneous.h"

nil help (chr option) {
	switch (option) {
	case USAGE:
		PUT_ARR (
			LANG ("usage"), ": ptree [-Pcs] [-Ldrha] [-Sdn] [-Mcvh]\n",
			LANG ("options")
		);
		break;
	case PRINTING:
		PUT_ARR (
			"  -P    ", LANG ("printing"), "\n"
			"    -c    ", LANG ("printing.c"), "\n"
			"    -s    ", LANG ("printing.s")
		);
		break;
	case LISTING:
		PUT_ARR (
			"  -L    ", LANG ("listing"), "\n"
			"    -d    ", LANG ("listing.d"), "\n"
			"    -r    ", LANG ("listing.r"), "\n"
			"    -h    ", LANG ("listing.h"), "\n"
			"    -a    ", LANG ("listing.a")
		);
		break;
	case SORTING:
		PUT_ARR (
			"  -S    ", LANG ("sorting"), "\n"
			"    -d    ", LANG ("sorting.d"), "\n"
			"    -n    ", LANG ("sorting.n")
		);
		break;
	case MISCELLANEOUS:
		PUT_ARR (
			"  -M    ", LANG ("miscellaneous"), "\n"
			"    -c    ", LANG ("miscellaneous.c"), "\n"
			"    -v    ", LANG ("miscellaneous.v"), "\n"
			"    -h    ", LANG ("miscellaneous.h")
		);
		break;
	default:
		help (USAGE);
		help (PRINTING);
		help (LISTING);
		help (SORTING);
		help (MISCELLANEOUS);
		ret;
	}
	NEW_LNE ();
}

nil option_miscellaneous (chr option) {
	switch (option) {
	case 'v':
		PUT (
			"ptree " VERSION "\n"
			"* https://github.com/ICanOnlySuffer/ptree/releases/tag/"
			VERSION "\n"
		);
		break;
	case 'h':
		help ('0');
		break;
	case 'c':
		PUT_ARR (
			LANG ("developer"),
			": Piero Estéfano Rojas Effio (ICanOnlySuffer)\n",
			LANG ("based-on"),
			": https://gitlab.com/OldManProgrammer/unix-tree\n",
			LANG ("licence")
		);
		NEW_LNE ();
		break;
	default:
		help ('0');
		QUT (1);
	}
	QUT (0);
}

