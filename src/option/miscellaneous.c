# include "option/miscellaneous.h"

nil help (chr option) FUN
	SWI option DOS
	WHN USAGE:
		PUT_ARR (
			LANG ('u', 's', 'e'),
			": ptv [-Pcs] [-Ldrha] [-Sdn] [-Mcvh]\n",
			LANG ('o', 'p', 't')
		);
		BRK;
	WHN PRINTING:
		PUT_ARR (
			"  -P    ", LANG ('p', 'u', 't'), "\n"
			"    -c    ", LANG ('p', 'u', 't', '.', 'c'), "\n"
			"    -s    ", LANG ('p', 'u', 't', '.', 's')
		);
		BRK;
	WHN LISTING:
		PUT_ARR (
			"  -L    ", LANG ('l', 's', 't'), "\n"
			"    -d    ", LANG ('l', 's', 't', '.', 'd'), "\n"
			"    -r    ", LANG ('l', 's', 't', '.', 'r'), "\n"
			"    -h    ", LANG ('l', 's', 't', '.', 'h'), "\n"
			"    -a    ", LANG ('l', 's', 't', '.', 'a')
		);
		BRK;
	WHN SORTING:
		PUT_ARR (
			"  -S    ", LANG ('s', 'r', 't'), "\n"
			"    -d    ", LANG ('s', 'r', 't', '.', 'd'), "\n"
			"    -n    ", LANG ('s', 'r', 't', '.', 'n')
		);
		BRK;
	WHN MISCELLANEOUS:
		PUT_ARR (
			"  -M    ", LANG ('m', 's', 'c'), "\n"
			"    -c    ", LANG ('m', 's', 'c', '.', 'c'), "\n"
			"    -v    ", LANG ('m', 's', 'c', '.', 'v'), "\n"
			"    -h    ", LANG ('m', 's', 'c', '.', 'h')
		);
		BRK;
	default:
		help (USAGE);
		help (PRINTING);
		help (LISTING);
		help (SORTING);
		help (MISCELLANEOUS);
		RET;
	END
	NEW_LNE ();
END

nil option_miscellaneous (chr option) FUN
	SWI option DOS
	WHN 'v':
		PUT (
			"ptree " VERSION "\n"
			"* https://github.com/ICanOnlySuffer/ptree/releases/tag/"
			VERSION "\n"
		);
		BRK;
	WHN 'h':
		help ('0');
		BRK;
	WHN 'c':
		PUT_ARR (
			LANG ('d', 'e', 'v'),
			": Piero Estéfano Rojas Effio (ICanOnlySuffer)\n",
			LANG ('o', 'm', 'p'),
			": https://gitlab.com/OldManProgrammer/unix-tree\n",
			LANG ('l', 'i', 'c')
		);
		NEW_LNE ();
		BRK;
	default:
		help ('0');
		QUT (1);
	END
	QUT (0);
END

