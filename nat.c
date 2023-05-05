#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void help() {
    printf(
        "Usage: nat [FILE]...\n"
        "Concatenate FILE(s) to standard output.\n\n"
        "-p, --pipes              better output formatting with ascii pipes\n"
        "-P, --no-pipes           no output formatting with ascii pipes\n"
        "-c, --color              use color escape sequences\n"
        "-C, --no-color           dont use color escape sequences\n"
        "    --help               display this help and exit\n"
    );
}

void colorcode(int code) {
    if (code == 0)
        printf("\033[0m");
    else
        printf("\033[0;%dm", code);
}

int readfile(char *filename, bool pipes, bool color) {
    FILE *fileptr;

    fileptr = fopen(filename, "r");

    char contents[128];

    if (fileptr != NULL) {
        if (color) colorcode(31); // Red

        if (pipes) printf("┌──── %s \n│\n", filename);
        else printf("+---- %s \n|\n", filename);

        while (fgets(contents, 128, fileptr)) {
            if (color) colorcode(31); // Red

            if (pipes) printf("│   ");
            else printf("|   ");

            if (color) colorcode(32); // Green

            printf("%s", contents);
        }

        printf("\n");
        fclose(fileptr);
    } else {
        fclose(fileptr);
        printf("nat: %s: No such file or directory\n", filename);
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc <= 1 || !strcmp(argv[1], "--help")) {
        help();
        return 0;
    }

    bool pipes = true;
    bool color = true;

    for (int arg = 1; arg < argc; arg++){
        if (!strcmp(argv[arg], "--pipes") || !strcmp(argv[arg], "-p")) 
            pipes = true;
        else if (!strcmp(argv[arg], "--no-pipes") || !strcmp(argv[arg], "-P"))
            pipes = false;
        else if (!strcmp(argv[arg], "--color") || !strcmp(argv[arg], "-c"))
            color = true;
        else if (!strcmp(argv[arg], "--no-color") || !strcmp(argv[arg], "-C"))
            color = false;
        else {
            char filename[64]; strcpy(filename, argv[arg]);
            readfile(filename, pipes, color);
        }
    }

    return 0;
}
