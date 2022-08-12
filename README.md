# Simple Shell - Super Friendship Shell

## Table of Contents
* [Description and File Listing](#description)
* [Environment](#environment)
* [Prerequisites](#prerequisites)
* [How to Install](#installation)
* [Hot to Compile](#compile)
* [Example of Use](#example-of-use)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)

## Description and File Listing
A basic shell done in C.  Detailed list of features forthcoming.

|     *Filename*        |               *Description*                      |
|-----------------------|--------------------------------------------------|
| shell.h               | Header file containing function declaractions    |
| main.c                | Main .c source file for project                  |
| sfsh.h                | Header file for our Super Friendship Shell       |
| sfsh_loop.c           | Entry point hands off to our Shell's loop        |
| sfsh_getline.c        | Function takes in command and argument as string |
| sfsh_tokenize.c       | Function breaks up string with delimiters        |
| sfsh_execute.c        | Matches commands with supported builtins         | 
| sfsh_launch.c         | Creates child process to execute function        | 
| sfsh_helpers.c        | Helper functions for the Super Friendship Shell  | 
| sfsh_builtins0.c      | Implementation of built-in functions             | 
| sfsh_builtins1.c      | Implementation of even more built-in functions   | 
| sfsh_string_helpers.c | String helper functions for manipulation         | 

## Environment
The Super Friendship Shell was built in Ubuntu 14.04 LTS in a virtual 
machine managed by Vagrant.

## Prerequisites
Please have the following installed in your Ubunutu 14.04 environment:
- git (sudo apt-get install git)
- build-essential (sudo apt-get install build-essential) 

## How to Install
Clone the repository to a directory of your choice
```
https://github.com/amoyinoluwa/simple_shell.git
```

## How to Compile
After cloning the repository, please run the following the command...
```
gcc -Wall -Werror -Wextra -pedantic *.c -o sfsh
```
Or, you can just use the Makefile
```
make
```
Then, just Type this command to execute the Super Friendship Shell!
```
./sfsh
```

## Examples of Use
Run the executable ./sfsh after compilation.
```
$ ./sfsh
$ ls -al
total 56
-rw-rw-r-- 1 vagrant vagrant  156 Nov 20 00:29 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  289 Nov 20 00:29 main.c
-rw-rw-r-- 1 vagrant vagrant  319 Nov 20 00:29 Makefile
-rwxrwxr-x 1 vagrant vagrant  557 Nov 20 00:29 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant 1778 Nov 20 00:29 README.md
-rw-rw-r-- 1 vagrant vagrant 1671 Nov 20 00:29 sfsh_builtins0.c
-rw-rw-r-- 1 vagrant vagrant 1721 Nov 20 00:29 sfsh_execute.c
-rw-rw-r-- 1 vagrant vagrant  540 Nov 20 00:29 sfsh_getline.c
-rw-rw-r-- 1 vagrant vagrant 1120 Nov 20 00:29 sfsh.h
-rw-rw-r-- 1 vagrant vagrant  228 Nov 20 00:29 sfsh_helpers.c
-rw-rw-r-- 1 vagrant vagrant 1383 Nov 20 00:29 sfsh_launch.c
-rw-rw-r-- 1 vagrant vagrant  432 Nov 20 00:29 sfsh_loop.c
-rw-rw-r-- 1 vagrant vagrant 1844 Nov 20 00:29 sfsh_string_helpers.c
-rw-rw-r-- 1 vagrant vagrant  758 Nov 20 00:29 sfsh_tokenize.c
$
```

## Authors
*Joseph Ajayi* - [Github](https://github.com/amoyinoluwa)
*Kaiga Munene* - [Github](https://github.com/KaigaMunene)
