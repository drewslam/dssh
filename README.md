# dssh - Drewslam's Shell

An interactive Unix-compatible shell written in C.

## Features

- Interactive command prompt.
- Execution of Unix commands with arguments.
- Basic error handling
- Clean exit with "exit" keyword.

ex.
```
dssh> ls .
build  dssh  include  Makefile  README.md  src
dssh> ls -l .
total 40
drwxr-xr-x. 1 drewslam drewslam    42 Aug  9 09:55 build
-rwxr-xr-x. 1 drewslam drewslam 28808 Aug  9 09:55 dssh
drwxr-xr-x. 1 drewslam drewslam    46 Aug  3 09:23 include
-rw-r--r--. 1 drewslam drewslam   653 Aug  5 06:17 Makefile
-rw-r--r--. 1 drewslam drewslam   290 Aug  8 04:21 README.md
drwxr-xr-x. 1 drewslam drewslam    42 Aug  9 09:54 src
```

## Architecture

- Custom doubly-linked list queue implementation for command parsing.
- Fork-exec model for command execution.

## To Be Implemented

- Support for builtins (ex. cd)
- Pipe operators
- A high-level scripting language

## Requirements

- A Unix-like operating system
- GCC
- GNU Make

## Build

```bash
git clone https://github.com/drewslam/dssh.git
cd dssh
make
```

## Usage

```bash
./dssh
```
