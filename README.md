# PTree (pocha-tree)

A simple directory visualizer based on 'tree' by
Steve Baker, Thomas Moore, Francesc Rocher, Florian Sesser & Kyosuke Tokoro

## Installation

```shell
$ git clone https://github.com/ICanOnlySuffer/ptree
$ cd ptree
$ ./install
```

## Uninstallation

```shell
$ ./uninstall
```

## Usage

```shell
$ ptree -h
```

```ruby
usage: ptree [-Ldfah] [-Sad] [-Pc]
  -P    Printing
    -c    with colors from LS_COLORS
    -l    on loop
    -d    loop refresh delay
  -S    Sorting
    -a    alphanumerically
    -d    directories first
  -L    Listing
    -d    only directories
    -r    only regular ones
    -b    directories and regular ones
    -h    hidden files
```

Example:

```
$ ptree -Sad
```

```
.
|-- flags/
|   |-- listing.h
|   |-- number.h
|   |-- other.h
|   |-- printing.h
|   `-- sorting.h
|-- lang/
|   |-- en
|   `-- es
|-- LICENCE.txt
|-- README.md
|-- file.h
|-- flags.h
|-- getch.h
|-- hashmap.h
|-- help.h
|-- install
|-- lang.h
|-- main.c
|-- pstdio.h
|-- pstring.h
|-- root-do
|-- tree.h
|-- types.h
|-- uninstall
`-- vector.h

2 directories, 24 regular ones
```

## Contributing

Bug reports, suggestions and pull requests are welcome!

## Licence

This project is available as open source under terms of the [MIT Licence] (
	https://opensource.org/licenses/MIT).







