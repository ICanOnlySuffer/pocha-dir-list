# ifndef PREFIX
# error "PREFIX not defined: OS not suported"
# endif

# include "option.h"
# include "lang.h"
# include "tree.h"

# include <stdio.h>

chr main (s32 argc, str args []) FUN
	str lang_path = PREFIX "/share/ptv/lang/";
	lang_load_env (lang_path, "es", 1024);
	
	IFF not dictionary THN
		PUT_ERR_ARR (lang_path, ": ", LANG ("cannot_open_file"));
		NEW_LNE_ERR ();
		ret 2;
	END
	
	str path = parse_options (argc, args);
	DIR * dir = opendir (path);
	
	IFF not dir DOS
		PUT_ERR_ARR (path, ": ", LANG ("cannot_open_file"));
		NEW_LNE_ERR ();
		ret 2;
	END
	closedir (dir);
	
	str lang_n_dirs [] = {
		LANG ("directories.0"),
		LANG ("directories.1"),
		LANG ("directories.2"),
		LANG ("directories.+")
	};
	
	str lang_n_regs [] = {
		LANG ("regular-ones.0"),
		LANG ("regular-ones.1"),
		LANG ("regular-ones.2"),
		LANG ("regular-ones.+")
	};
	chr buffer [2][32];
	
	PUT_ARR (DI_COLOR, path, NO_COLOR, "\n");
	tree ("", path);
	
	str_frm_u64 (buffer [0], n_files.dirs);
	str_frm_u64 (buffer [1], n_files.regs);
	
	NEW_LNE ();
	PUT_ARR (
		buffer [0], " ",
		lang_n_dirs [n_files.dirs > 3 ? 3 : n_files.dirs],
		", ",
		buffer [1], " ",
		lang_n_regs [n_files.regs > 3 ? 3 : n_files.regs]
	);
	NEW_LNE ();
}

