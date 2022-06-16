# Pocha Dir List

Lightweight directory listing program inspired by
[tree](https://gitlab.com/OldManProgrammer/unix-tree). Prints the
contents of a directory in a tree shape in the terminal.

## Installation

Available at the [AUR](
https://aur.archlinux.org/packages/pocha-dir-list)

**dependencies:**

- [libpocha](https://gitlab.com/ICanOnlySuffer/libpocha) (make)

**command:**

	# make install clean

## Usage

	$ pdl -h

```
usage: pdl [OPTION]...
options:
-P (printing):
  -c  use colors from LS_COLORS
  -s  size
-L (listing):
  -d  directories only
  -r  regular ones only
  -h  hidden only
  -a  all
-S (sorting):
  -d  directories first
  -n  by name
-M (misc):
  -v  version
  -h  help
```

**default output:**

	$ pdl

```
.
|-- inc/
|   |-- buffer.h
|   |-- lang.h
|   |-- option.h
|   |-- tree.h
|   |-- file.h
|   `-- option/
|       |-- listing.h
|       |-- misc.h
|       |-- printing.h
|       `-- sorting.h
|-- src/
|   |-- tree.c
|   |-- buffer.c
|   |-- pdl.c
|   |-- option.c
|   |-- file.c
|   |-- lang.c
|   `-- option/
|       |-- printing.c
|       |-- listing.c
|       |-- sorting.c
|       `-- misc.c
|-- readme.md
|-- shr/
|   |-- en
|   |-- pt
|   `-- es
|-- Makefile
`-- license.txt

6 directories, 25 regular ones
```

**sorting by name then directories first:**

	$ pdl -Snd

```
.
|-- inc/
|   |-- option/
|   |   |-- listing.h
|   |   |-- misc.h
|   |   |-- printing.h
|   |   `-- sorting.h
|   |-- buffer.h
|   |-- file.h
|   |-- lang.h
|   |-- option.h
|   `-- tree.h
|-- shr/
|   |-- en
|   |-- es
|   `-- pt
|-- src/
|   |-- option/
|   |   |-- listing.c
|   |   |-- misc.c
|   |   |-- printing.c
|   |   `-- sorting.c
|   |-- buffer.c
|   |-- file.c
|   |-- lang.c
|   |-- option.c
|   |-- pdl.c
|   `-- tree.c
|-- Makefile
|-- license.txt
`-- readme.md

6 directories, 25 regular ones
```

## Contributing

Bug reports, suggestions and pull requests are welcome!

## Languages

Currently available in English, Spanish and Portugese.

