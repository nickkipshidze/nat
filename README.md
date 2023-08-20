# nat

Nick's version of concatenate program. <br><br>
Python is my native language so if my C code isn't following good practice or has some issues please correct me on them.

## examples
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