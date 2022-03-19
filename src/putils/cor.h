
# ifndef PUTILS_COR_H
# define PUTILS_COR_H

# include <stddef.h>
# include <stdint.h>

// values

# define NIL NULL
# define false 0
# define true 1

// operators

# define and &&
# define not !
# define or ||

// logic

# define iff(stuff_) if (stuff_)
# define unl(stuff_) if (not (stuff_))
# define whl(stuff_) while (stuff_)
# define utl(stuff_) while (not (stuff_))
# define elf(stuff_) else if (stuff_)
# define els else
# define cse(stuff_) switch (stuff_)
# define whn case

// typedefs

# define con const

typedef void nil;
typedef void * ptr;

typedef int8_t  s08;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u08;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float flt;
typedef double dbl;

typedef char chr;
typedef char * str;

// etc

# define ret return
# define ext extern
# define ARR_LEN(array_) \
	sizeof (array_) / sizeof (*array_)

# endif // PUTILS_COR_H

