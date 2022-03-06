
# ifndef _PUTILS_FILE_
# define _PUTILS_FILE_
# include "../putils/extra.h"
# include "../putils/vec.h"
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>

struct file {
	chr name [1024];
	chr path [256];
	off_t size;
	u08 is_link;
	mode_t mode;
};

extern struct {
	u32 regs;
	u32 dirs;
} n_files;

extern vec * get_files (str path);

# endif // _PUTILS_FILE

