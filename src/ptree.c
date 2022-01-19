# include <putils/getch.h>
# include <pthread.h>

# include "ptree/flags.h"
# include "ptree/tree.h"

nil * ptree (nil * path) {
	if (printing.alternative) {
		printf ("\e[?1049h\x1b[?25l");
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
	pputs (printing.colors.di, path, printing.colors.reset);
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
		
		goto tree_loop;
	}
}

nil * quit (nil *) {
	while (printing.loop) {
		switch (getch ()) {
		case 'q':
			if (printing.alternative) {
				printf ("\e[?1049l\x1b[?25h");
			}
			exit (0);
		}
	}
}

chr main (u16 argc, str args []) {
	set_lang_map ("/usr/share/ptree/lang/");
	str path = parse_flags (argc, args);
	
	DIR * dir = opendir (path);
	if (not dir) {
		fprintf (stderr, LANG ("path_doesnt_exist"), path);
		putchar ('\n');
		return 1;
	}
	closedir (dir);
	
	if (printing.loop) {
		pthread_t ptree_thread;
		pthread_t quit_thread;
		
		pthread_create (&ptree_thread, NULL, &ptree, path);
		pthread_create (&quit_thread, NULL, &quit, NULL);
		
		pthread_exit (NULL);
	} else {
		ptree (path);
	}
}
















