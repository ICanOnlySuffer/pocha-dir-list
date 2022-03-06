# include "../putils/extra.h"
# include <stdio.h>

nil print_size (u64 size) {
	putchar ('[');
	if (size < 1000) {
		printf ("%3lluB", size);
	} else if (size < 1024 * 10) {
		printf ("%3.1fK", size / 1024.0);
	} else if (size < 1024 * 1000) {
		printf ("%3lluK", size / 1024);
	} else if (size < 1024 * 1024 * 10) {
		printf ("%3.1fM", size / 1024.0 / 1024);
	} else if (size < 1024 * 1000 * 1000) {
		printf ("%3lluM", size / 1024 / 1024);
	} else if (size < (u64) (1024 * 1024 * 1024) * 10) {
		printf ("%3.1fG", size / 1024.0 / 1024 / 1024);
	} else if (size < (u64) (1024) * 1000 * 1000 * 1000) {
		printf ("%3lluG", size / 1024 / 1024 / 1024);
	} else if (size < (u64) (1024) * 1024 * 1024 * 1024 * 10) {
		printf ("%3.1fT", size / 1024.0 / 1024 / 1024 / 1024);
	} else {
		printf ("%3lluT", size / 1024 * 1024 * 1024 * 1024);
	}
	printf ("] ");
}

