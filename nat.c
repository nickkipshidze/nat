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

    char contents[128];

    if (fileptr != NULL) {
        printf("+---- %s \n|\n", filename);
        while (fgets(contents, 128, fileptr)) {
            printf("|   %s", contents);
        }
        printf("\n");
        fclose(fileptr);
    } else {
        fclose(fileptr);
        printf("nat: %s: No such file or directory\n", filename);
        return -1;
    }
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
