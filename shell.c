#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "def.h"

int shell() {
    char *source;

    source = (char *)malloc(BUFFERSIZE * sizeof(char));
    if(source==NULL) {
        perror("malloc");
        exit(1);
    }

    while(1) {
        printf("> ");
        fgets(source, malloc_usable_size(source), stdin);
        replace_char(source, '\n', '\0');
        if(!strcmp(source, "quit")) {
            break;
        }
        else {
            print_result(source);
        }
    }

    free(source);
    return 0;
}
