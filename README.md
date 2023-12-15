                                                         C - Simple Shell

This project creates our own version of Simple Shell. This is a group project from HolbertonSchool training


## Description
Shell is a simple UNIX command language interpreter that reads commands from either a file or standard input and executes them. The shell, also known as a command-line interpreter, is a command-line user interface found in Unix-like operating systems. It serves as both an interactive command language and a scripting language. The shell's role is to provide a flexible and powerful way to control the system's execution, either through commands entered directly by the user or by executing shell scripts.






## Cloning repository

You can install the simple shell cloning this repository in your terminal :
```bash
git clone https://github.com/harishammache/holbertonschool-simple_shell.git
```

## Compilation

You can compile the files with this command :
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## For use it

In order to use this shell, in a terminal, first run the program:
``prompt$ ./hsh``

It wil then display a simple prompt and wait for commands:
``$``

A command will be of the type :
``$ command``


## Builtins

| Command | Description
| --------| -----------
|env| Unix command used to display the current system environment or to execute a program in a specified environment
|exit | If you wish to exit out of the shell the user can use the builtin exit |







## Exemple

```bash
$ pwd
/workspaces/conteneur/holbertonschool-simple_shell
```

```bash
$ exit
$
```

```bash
$ ls -la
drwxr-xr-x 1 vscode vscode  4096 Dec 15 11:47 .
drwxrwxrwx 1 root   root    4096 Dec 11 09:42 ..
-rw-r--r-- 1 vscode vscode   900 Dec 15 11:03 create_path_list.c
-rw-r--r-- 1 vscode vscode   572 Dec 15 11:03 execute_command.c
-rw-r--r-- 1 vscode vscode   707 Dec 15 11:03 get_path.c
drwxr-xr-x 1 vscode vscode  4096 Dec 15 11:46 .git
-rwxr-xr-x 1 vscode vscode 17424 Dec 15 11:47 hsh
-rw-r--r-- 1 vscode vscode   829 Dec 15 11:03 parse_user_input.c
-rw-r--r-- 1 vscode vscode     0 Dec 14 08:56 README.md
-rw-r--r-- 1 vscode vscode   933 Dec 15 11:03 search_executable_files.c
-rw-r--r-- 1 vscode vscode  1037 Dec 15 11:03 shell.c
-rw-r--r-- 1 vscode vscode   702 Dec 15 11:03 shell.h
```

## Flowchart
![Logo](https://zupimages.net/up/23/50/l8b2.png)


## Authors

- [@Sarah BOUTIER](https://github.com/savvyhe)
- [@Haris HAMMACHE](https://github.com/harishammache)
