# Pocha's Tree Visualizer

A lightweight tree directory visualizer based on `tree`.

## Installation

Available at the [AUR](https://aur.archlinux.org/packages/ptv)

**dependencies:**

- [pul](https://gitlab.com/ICanOnlySuffer/pul) (make & runtime)

**command:**

	# make install clean

## Usage

	$ ptv -h

```
usage: ptv [OPTION]...
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
-M (miscellaneous):
  -v  version
  -h  help
```

**default output:**

	$ ptv

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
|       |-- miscellaneous.h
|       |-- printing.h
|       `-- sorting.h
|-- src/
|   |-- tree.c
|   |-- buffer.c
|   |-- ptv.c
|   |-- option.c
|   |-- file.c
|   |-- lang.c
|   `-- option/
|       |-- printing.c
|       |-- listing.c
|       |-- sorting.c
|       `-- miscellaneous.c
|-- readme.md
|-- shr/
|   `-- lang/
|       |-- en
|       |-- pt
|       `-- es
|-- Makefile
`-- license.txt

6 directories, 25 regular ones
```

**sorting by name then directories first:**

	$ ptv -Snd

```
.
|-- inc/
|   |-- option/
|   |   |-- listing.h
|   |   |-- miscellaneous.h
|   |   |-- printing.h
|   |   `-- sorting.h
|   |-- buffer.h
|   |-- file.h
|   |-- lang.h
|   |-- option.h
|   `-- tree.h
|-- shr/
|   `-- lang/
|       |-- en
|       |-- es
|       `-- pt
|-- src/
|   |-- option/
|   |   |-- listing.c
|   |   |-- miscellaneous.c
|   |   |-- printing.c
|   |   `-- sorting.c
|   |-- buffer.c
|   |-- file.c
|   |-- lang.c
|   |-- option.c
|   |-- ptv.c
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

