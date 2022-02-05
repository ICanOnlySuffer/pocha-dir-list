# include "putils/getch.h"
# include <pthread.h>

# include "ptree/options.h"
# include "ptree/tree.h"

# if __ANDROID__
# define LANG_PATH "/data/data/com.termux/files/usr/share/ptree/lang/"
# elif __linux__
# define LANG_PATH "/usr/share/ptree/lang/"
# else
# error "Android and Linux suported only"
# endif

nil * ptree (nil * path) {
	if (printing.alternative) {
		printf ("\e[?1049h\x1b[?25l");
	}
	if (printing.loop) {
		printf ("\e[1;1H\e[2J");
	}
	
	str lang_n_dirs [] = {
		lang_get ("directories(0)"),
		lang_get ("directories(1)"),
		lang_get ("directories(2)"),
		lang_get ("directories(+)")
	};
	
	str lang_n_regs [] = {
		lang_get ("regular_ones(0)"),
		lang_get ("regular_ones(1)"),
		lang_get ("regular_ones(2)"),
		lang_get ("regular_ones(+)")
	};
	
	tree_loop:
	print (printing.colors.di, path, printing.colors.reset, "\n");
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
	lang_load (LANG_PATH);
	str path = parse_options (argc, args);
	DIR * dir = opendir (path);
	unless (dir) {
		fprintf (stderr, lang_get ("path_doesnt_exist"), path);
		putchar ('\n');
		return 1;
	}
	closedir (dir);
	
	pthread_t ptree_thread;
	pthread_t quit_thread;
	
	pthread_create (&ptree_thread, NULL, &ptree, path);
	pthread_create (&quit_thread, NULL, &quit, NULL);
	
	pthread_exit (NULL);
}

