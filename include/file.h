
# ifndef PTREE_FILE_H
# define PTREE_FILE_H

# include <putils/str.h>
# include <putils/vec.h>
# include <sys/stat.h>
# include <unistd.h>
# include <dirent.h>

# include "options/listing.h"

# ifndef PATH_SIZE
# define PATH_SIZE 256
# endif

# ifndef NAME_SIZE
# define NAME_SIZE 64
# endif

struct file {
	chr name [NAME_SIZE];
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

# endif // PTREE_FILE_H

