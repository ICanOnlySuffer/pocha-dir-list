
# ifndef PDL_FILE_H
# define PDL_FILE_H
# include <pocha/vec.h>
# include <unistd.h>

# define NAME_SIZE 128
# define PATH_SIZE 256

typedef struct {
	chr name [NAME_SIZE];
	chr path [PATH_SIZE];
	u64 size;
	u08 is_link;
	mode_t mode;
} file_t;

ext u32 n_regs;
ext u32 n_dirs;
ext vec get_files (str path);

# endif // PDL_FILE_H

