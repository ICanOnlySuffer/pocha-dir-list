# if __ANDROID__
# define LANG_PATH "/data/data/com.termux/files/usr/share/ptree/lang/"
# elif __linux__
# define LANG_PATH "/usr/share/ptree/lang/"
# else
# error "Android and Linux suported only"
# endif

# include "ptree/options.h"
# include "putils/getch.h"
# include "ptree/tree.h"
# include <signal.h>

nil at_exit (int) {
	if (printing.alternative) {
		printf ("\e[?1049l\x1b[?25h");
	}
	exit (0);
}

chr main (s32 argc, str args []) {
	lang_map = lang_load (LANG_PATH, "en", 1024);
	
	str path = parse_options (argc, args);
	DIR * dir = opendir (path);
	
	unless (dir) {
		fprintf (stderr, LANG ("path_doesnt_exist"), path);
		putchar ('\n');
		return 1;
	}
	closedir (dir);
	
	if (printing.alternative) {
		printf ("\e[?1049h\x1b[?25l");
		signal (SIGINT, at_exit);
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
	print (di_color, path, reset_color "\n");
	tree ("", path);
	
	putchar ('\n');
	printf (
		lang_n_dirs [n_files.dirs > 3 ? 3 : n_files.dirs],
		n_files.dirs
	);
	printf (", ");
	printf (
		lang_n_regs [n_files.regs > 3 ? 3 : n_files.regs],
		n_files.regs
	);
	putchar ('\n');
	
	if (printing.loop) {
		printf ("\e[1;1H\e[2J");
		
		n_files.dirs = 0;
		n_files.regs = 0;
		
		for (u16 i = 0; i < printing.delay * 10; i++) {
			usleep (100000);
		}
		
		goto tree_loop; // sin
	}
	
	at_exit (0);
}

