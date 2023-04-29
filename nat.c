#include <stdio.h>
#include <string.h>

void help() {
    printf(
        "Usage: nat [FILE]...\n"
        "Concatenate FILE(s) to standard output.\n"
    );
}

int readfile(char *filename) {
    FILE *fileptr;

    fileptr = fopen(filename, "r");

    char contents[100];

    if (fileptr != NULL) {
        while(fgets(contents, 100, fileptr)) {
            printf("%s", contents);
        }
    } else {
        printf("nat: %s: No such file or directory\n", filename);

        return -1;
    }

    fclose(fileptr);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        help();
        return 0;
    }

    for (int arg = 1; arg < argc; arg++){
        char filename[64]; strcpy(filename, argv[arg]);
        readfile(filename);
    }

    return 0;
}