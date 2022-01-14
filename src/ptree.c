# include <pthread.h>
# include "ptree/utils/getch.h"
# include "ptree/flags.h"
# include "ptree/tree.h"

nil *ptree (nil *path) {
	if (printing.alternative) {
		printf ("\e[?1049h\x1b[?25l");
	}
	if (printing.loop) {
		printf ("\e[1;1H\e[2J");
	}
	
	while (true) {
		
		pputs (printing.colors.di, path, printing.colors.reset);
		tree ("", path);
		
		str n_dirs = (str []) {
			"directories(0)",
			"directories(1)",
			"directories(2)",
			"directories(+)"
		} [n_files.dirs > 3 ? 3 : n_files.dirs];
		
		str n_regs = (str []) {
			"regular_ones(0)",
			"regular_ones(1)",
			"regular_ones(2)",
			"regular_ones(+)"
		} [n_files.regs > 3 ? 3 : n_files.regs];
		
		putchar ('\n');
		printf (LANG (n_dirs), n_files.dirs);
		printf (", ");
		printf (LANG (n_regs), n_files.regs);
		putchar ('\n');
		
		if (printing.loop) {
			printf ("\e[1;1H\e[2J");
			
			n_files.dirs = 0;
			n_files.regs = 0;
			
			for (ux1 i = 0; i < printing.delay * 10; i++) {
				usleep (100000);
			}
		} else {
			break;
		}
	}
}

nil *quit (nil *) {
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

ix4 main (ux1 argc, str args []) {
	
	set_lang_map ("/usr/share/ptree/lang/");
	
	str path = parse_flags (argc, args);
	ix1 path_buffer [PATH_SIZE];
	
	// check dir
	DIR *dir = opendir (path);
	if (dir == NULL) {
		ix1 * error;
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
















