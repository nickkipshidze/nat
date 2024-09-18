# NAT

Nick's version of concatenate program. <br><br>
Python is my native language so if my C code isn't following good practice or has some issues please correct me on them.

## Examples
```
$ nat
Usage: nat [FILE]...
Concatenate FILE(s) to standard output.

-p, --pipes              better output formatting with ascii pipes
-P, --no-pipes           no output formatting with ascii pipes
-c, --color              use color escape sequences
-C, --no-color           dont use color escape sequences
    --help               display this help and exit
```

```
$ nat nat.c
┌──── nat.c 
│
│   #include <stdio.h>
│   #include <stdbool.h>
│   #include <string.h>
│   
. . .
```

## Running the code

1. Clone the GitHub repository: `git clone https://github.com/NickKipshidze/nat`
0. cd into the directory: `cd nat`
0. Build the project: `make`
0. Run the binary: `./nat`
