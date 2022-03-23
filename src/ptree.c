# ifndef DIR_SHARE
# error "DIR_SHARE not defined: OS not suported"
# endif

# include "options.h"
# include "file.h"
# include "lang.h"
# include "size.h"
# include "tree.h"

# include <signal.h>
# include <stdio.h>

nil at_signal (s32) fun
	iff printing.alternative thn
		PUT ("\e[?1049l\x1b[?25h");
	end
	QUT (0);
end

chr main (s32 argc, str args []) fun
	lang_load_env ("/" DIR_SHARE "/ptree/lang/", "es", 1024);
	
	iff not dictionary thn
		PUT_ERR ("couldn't load dictionary\n");
		ret 1;
	end
	
	str path = parse_options (argc, args);
	DIR * dir = opendir (path);
	
	iff not dir thn
		PUT_ERR_ARR (path, ": ", LANG ("path_doesnt_exist"));
		NEW_LNE_ERR ();
		ret 1;
	end
	closedir (dir);
	
	iff printing.alternative thn
		PUT ("\e[?1049h\x1b[?25l");
		signal (SIGINT, at_signal);
	end
	iff printing.loop thn
		PUT ("\e[1;1H\e[2J");
	end
	
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
	chr buffer [2][32];
	
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
	
	iff printing.loop thn
		PUT ("\e[1;1H\e[2J");
		
		n_files.dirs = 0;
		n_files.regs = 0;
		
		for u16 i = 0; i < printing.delay * 10; i++ dos
			usleep (100000);
		end
		
		goto tree_loop; // sin
	end
	
	at_signal (0);
end

