# include <pthread.h>
# include "pstdio.h"
# include "getch.h"
# include "lang.h"
# include "help.h"
# include "tree.h"

e01 loop = false;
ux4 delay = 1;

ix0 ptree (ix1 * path) {
	pputs (di_color, (ix1 *) path, reset_color);
	
	// ptree
	tree ("", (ix1 *) path);
	
	// directories and files count
	ix1 * lang_directories;
	
	switch (n_directories) {
	case 0:
		lang_directories = "directories(0)";
		break;
	case 1:
		lang_directories = "directories(1)";
		break;
	default:
		lang_directories = "directories(+)";
	}
	
	ix1 * lang_regular_ones;
	
	switch (n_regular_ones) {
	case 0:
		lang_regular_ones = "regular_ones(0)";
		break;
	case 1:
		lang_regular_ones = "regular_ones(1)";
		break;
	default:
		lang_regular_ones = "regular_ones(+)";
	}
	
	printf (LANG (lang_directories), n_directories);
	printf (", ");
	printf (LANG (lang_regular_ones), n_regular_ones);
	putchar ('\n');
}

ix0 * ptree_loop (ix0 * path) {
	ux4 splits = delay * 10;
	
	while (loop) {
		printf ("\e[1;1H\e[2J");
		
		ptree (path);
		
		n_directories = 0;
		n_regular_ones = 0;
		
		for (ux1 i = 0; loop && i < splits; i++) {
			usleep (100000);
		}
	}
}

ix0 * break_loop (ix0 *) {
	while (loop) {
		if (getch () == 'q') {
			loop = false;
		}
	}
}

ix0 main (ux1 argc, ix1 * args []) {
	
	ix1 * path = ".";
	
	struct hash EMPTY_LANG = {"no-key", "no-value"};
	lang_map = (struct hashmap) new_vector (struct hash, EMPTY_LANG);
	
	ix1 path_buffer [MAX_PATH_LENGTH];
	lang_compile ("/usr/lib/ptree/lang/");
	
	# include "flags.h"
	
	// check dir
	DIR * dir = opendir (path);
	if (dir == NULL) {
		ix1 * error;
		printf (LANG ("path_doesnt_exist"), path);
		putchar ('\n');
		return;
	}
	closedir (dir);
	
	if (loop) {
		pthread_t ptree_thread;
		pthread_t break_thread;
		
		pthread_create (&ptree_thread, NULL, &ptree_loop, path);
		pthread_create (&ptree_thread, NULL, &break_loop, NULL);
		
		pthread_exit (NULL);
	} else {
		ptree (path);
	}
	
	free (lang_map.items);
}
















