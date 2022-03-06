# if __ANDROID__
# define LANG_PATH "/data/data/com.termux/files/usr/share/ptree/lang/"
# elif __linux__
# define LANG_PATH "/usr/share/ptree/lang/"
# else
# error "Android and Linux suported only"
# endif

# include "ptree/options.h"
# include "ptree/file.h"
# include "ptree/lang.h"
# include "ptree/size.h"
# include "ptree/tree.h"

# include "putils/print.h"
# include "putils/ioe.h"
# include "putils/lng.h"

# include <signal.h>
# include <stdio.h>

nil at_signal (int) {
	if (printing.alternative) {
		print ("\e[?1049l\x1b[?25h");
	}
	exit (0);
}

chr main (s32 argc, str args []) {
	lang_map = lng_load (LANG_PATH, "en", 1024);
	
	str path = parse_options (argc, args);
	DIR * dir = opendir (path);
	
	unless (dir) {
		fprintf (stderr, LANG ("path_doesnt_exist"), path);
		put_chr ('\n');
		return 1;
	}
	closedir (dir);
	
	if (printing.alternative) {
		print ("\e[?1049h\x1b[?25l");
		signal (SIGINT, at_signal);
	}
	if (printing.loop) {
		printf ("\e[1;1H\e[2J");
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
	
tree_loop:
	print_many (di_color, path, reset_color "\n");
	tree ("", path);
	
	putchar ('\n');
	printf (
		lang_n_dirs [n_files.dirs > 3 ? 3 : n_files.dirs],
		n_files.dirs
	);
	print (", ");
	printf (
		lang_n_regs [n_files.regs > 3 ? 3 : n_files.regs],
		n_files.regs
	);
	put_chr ('\n');
	
	if (printing.loop) {
		print ("\e[1;1H\e[2J");
		
		n_files.dirs = 0;
		n_files.regs = 0;
		
		for (u16 i = 0; i < printing.delay * 10; i++) {
			usleep (100000);
		}
		
		goto tree_loop; // sin
	}
	
	at_signal (0);
}

