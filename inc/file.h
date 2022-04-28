
# ifndef PTV_FILE_H
# define PTV_FILE_H

# include <sys/stat.h>
# include <pul/str.h>
# include <pul/vec.h>
# include <unistd.h>
# include <dirent.h>

# include "option/listing.h"

# define NAME_SIZE 128
# define PATH_SIZE 256

typedef struct {
	chr name [NAME_SIZE];
	chr path [PATH_SIZE];
	u64 size;
	u08 is_link;
	mode_t mode;
} fil;

extern u32 n_regs;
extern u32 n_dirs;

extern vec get_files (str path);

# endif // PTV_FILE_H

