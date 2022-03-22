# include "size.h"

nil str_frm_filesize (str buffer, u64 size) {
	if (size < 1000) {
		sprintf (buffer, "%3lluB", size);
	} else if (size < 1024 * 10) {
		sprintf (buffer, "%3.1fK", size / 1024.0);
	} else if (size < 1024 * 1000) {
		sprintf (buffer, "%3lluK", size / 1024);
	} else if (size < 1024 * 1024 * 10) {
		sprintf (buffer, "%3.1fM", size / 1024.0 / 1024);
	} else if (size < 1024 * 1000 * 1000) {
		sprintf (buffer, "%3lluM", size / 1024 / 1024);
	} else if (size < (u64) (1024 * 1024 * 1024) * 10) {
		sprintf (buffer, "%3.1fG", size / 1024.0 / 1024 / 1024);
	} else if (size < (u64) (1024) * 1000 * 1000 * 1000) {
		sprintf (buffer, "%3lluG", size / 1024 / 1024 / 1024);
	} else if (size < (u64) (1024) * 1024 * 1024 * 1024 * 10) {
		sprintf (buffer, "%3.1fT", size / 1024.0 / 1024 / 1024 / 1024);
	} else {
		sprintf (buffer, "%3lluT", size / 1024 * 1024 * 1024 * 1024);
	}
}
