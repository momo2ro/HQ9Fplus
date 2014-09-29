#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "def.h"

int file_open(FILE *f) {
    char *source;

    source = (char *)malloc(BUFFERSIZE * sizeof(char));
    if(source==NULL) {
        perror("malloc");
        exit(1);
    }

    fgets(source, malloc_usable_size(source), f);
    replace_char(source, '\n', '\0');
    print_result(source);
    free(source);
    return 0;
}
