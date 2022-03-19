
# ifndef _PTREE_FILE_
# define _PTREE_FILE_

# include "../putils/str.h"
# include "../putils/vec.h"
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>

# include "options/listing.h"

# define PATH_SIZE 1024
# define NAME_SIZE 256

struct file {
	chr name [PATH_SIZE];
	chr path [PATH_SIZE];
	off_t size;
	u08 is_link;
	mode_t mode;
};

struct n_files {
	u32 regs;
	u32 dirs;
};

ext struct n_files n_files;
ext vec * get_files (str path);

# endif // _PTREE_FILE

