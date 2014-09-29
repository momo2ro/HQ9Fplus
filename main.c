#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "def.h"

static void argvfile(int argc, char *argv[], int p);

int main(int argc, char *argv[]) {
    int opt;
    int p=0;

    while((opt=getopt(argc, argv, "hip")) != -1) {
        switch(opt) {
            case 'h':
                printf(USAGE);
                exit(0);
            case 'i':
                shell();
                exit(0);
            case 'p':
                if(optind == argc) {
                    printf(USAGE);
                }
                else {
                    p=1;
                    argvfile(argc, argv, p);
                }
                exit(0);
        }
    }

    if(optind == argc) {
        file_open(stdin);
    }
    else {
        argvfile(argc, argv, p);
    }
    exit(0);
}

static void argvfile(int argc, char *argv[], int p) {
    FILE *f;
    int i;

    for(i=optind;i<argc;i++) {
        f=fopen(argv[i], "r");
        if(!f) {
            perror(argv[i]);
            exit(1);
        }

        if(!p) {
            file_open(f);
        }
        else {
            file_name(argv[i]);
        }

        fclose(f);
    }
}
