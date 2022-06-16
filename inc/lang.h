
# ifndef PDL_LANG_H
# define PDL_LANG_H

# include <pocha/cor.h>

# define LANG_ERR_FIL LANG [0]
# define LANG_USE     LANG [1]
# define LANG_OPT     LANG [2]
# define LANG_OPTS    LANG [3]
# define LANG_PUT     LANG [4]
# define LANG_PUT_C   LANG [5] 
# define LANG_PUT_S   LANG [6]
# define LANG_LST     LANG [7]
# define LANG_LST_D   LANG [8]
# define LANG_LST_R   LANG [9]
# define LANG_LST_H   LANG [10]
# define LANG_LST_A   LANG [11]
# define LANG_SRT     LANG [12]
# define LANG_SRT_D   LANG [13]
# define LANG_SRT_N   LANG [14]
# define LANG_MSC     LANG [15]
# define LANG_MSC_C   LANG [16]
# define LANG_MSC_V   LANG [17]
# define LANG_MSC_H   LANG [18]
# define LANG_DIR_0   LANG [19]
# define LANG_DIR_1   LANG [20]
# define LANG_DIR_2   LANG [21]
# define LANG_DIR_X   LANG [22]
# define LANG_REG_0   LANG [23]
# define LANG_REG_1   LANG [24]
# define LANG_REG_2   LANG [25]
# define LANG_REG_X   LANG [26]

ext chr LANG [27][36];
ext nil lang_load_env (str path, str rescue);

# endif // PDL_LANG_H

