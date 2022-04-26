# ifndef DIR_SHR
# error "DIR_SHR not defined: filesystem not suported"
# endif

# include "option.h"
# include "lang.h"
# include "tree.h"

chr main (s32 argc, str args []) FUN
	lang_load_env (DIR_SHR "/ptv/lang/", "es", 1024);
	str path = parse_options (argc, args);
	
	str lang_n_dirs [] = {
		LANG ('d', 'i', 'r', '.', '0'),
		LANG ('d', 'i', 'r', '.', '1'),
		LANG ('d', 'i', 'r', '.', '2'),
		LANG ('d', 'i', 'r', '.', '+')
	};
	
	str lang_n_regs [] = {
		LANG ('r', 'e', 'g', '.', '0'),
		LANG ('r', 'e', 'g', '.', '1'),
		LANG ('r', 'e', 'g', '.', '2'),
		LANG ('r', 'e', 'g', '.', '+')
	};
	chr buffer [2][32];
	
	PUT_ARR (DI_COLOR, path, NO_COLOR, "\n");
	tree ("", path);
	
	str_frm_u64 (buffer [0], n_dirs);
	str_frm_u64 (buffer [1], n_regs);
	
	NEW_LNE ();
	PUT_ARR (
		buffer [0], " ",
		lang_n_dirs [n_dirs > 3 ? 3 : n_dirs],
		", ",
		buffer [1], " ",
		lang_n_regs [n_regs > 3 ? 3 : n_regs]
	);
	NEW_LNE ();
}

