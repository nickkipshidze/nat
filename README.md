# nat
Nick's version of concatenate program. <br><br>
Python is my native language so if my C code isn't following good practice or has some issues please correct me on them.

<br>

## examples
```
$ nat
Usage: nat [FILE]...
Concatenate FILE(s) to standard output.
```

```
$ nat nat.c
+---- nat.c 
|
|   #include <stdio.h>
|   #include <string.h>
|   
|   void help() {
|       printf(
|           "Usage: nat [FILE]...\n"
|           "Concatenate FILE(s) to standard output.\n"
|       );
|   }
|
. . .
```