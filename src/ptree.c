# ifndef SHARE_DIR
# error "SHARE_DIR not defined: OS not suported"
# endif

# include "ptree/options.h"
# include "ptree/file.h"
# include "ptree/lang.h"
# include "ptree/size.h"
# include "ptree/tree.h"

# include "putils/put.h"
# include "putils/lng.h"

# include <signal.h>
# include <stdio.h>

nil at_signal (s32) {
	iff (printing.alternative) {
		PUT ("\e[?1049l\x1b[?25h");
	}
	exit (0);
}

chr main (s32 argc, str args []) {
	lang_load_env (SHARE_DIR "ptree/lang/", "es", 1024);
	
	unl (dictionary) {
		PUT ("couldn't load dictionary\n");
		ret 1;
	}
	
	str path = parse_options (argc, args);
	DIR * dir = opendir (path);
	
	unl (dir) {
		PUT_ERR_ARR (path, ": ", LANG ("path_doesnt_exist"));
		NEW_LNE_ERR ();
		ret 1;
	}
	closedir (dir);
	
	iff (printing.alternative) {
		PUT ("\e[?1049h\x1b[?25l");
		signal (SIGINT, at_signal);
	}
	iff (printing.loop) {
		PUT ("\e[1;1H\e[2J");
	}
	
	str lang_n_dirs [] = {
		LANG ("directories(0)"),
		LANG ("directories(1)"),
		LANG ("directories(2)"),
		LANG ("directories(+)")
	};
	
	str lang_n_regs [] = {
		LANG ("regular_ones(0)"),
		LANG ("regular_ones(1)"),
		LANG ("regular_ones(2)"),
		LANG ("regular_ones(+)")
	};
	chr buffer [2][16];
	
tree_loop:
	PUT_ARR (DI_COLOR, path, RESET_COLOR "\n");
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
	
	if (printing.loop) {
		PUT ("\e[1;1H\e[2J");
		
		n_files.dirs = 0;
		n_files.regs = 0;
		
		for (u16 i = 0; i < printing.delay * 10; i++) {
			usleep (100000);
		}
		
		goto tree_loop; // sin
	}
	
	at_signal (0);
}

