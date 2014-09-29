#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>
#include "def.h"

int file_name(char *name) {
    char *patten="(.*/)?(.*)\\.hq9fp";
    char *source;
    regex_t pt;

    if(regcomp(&pt, patten, REG_EXTENDED | REG_NEWLINE)) {
        perror("regex compile failed");
        exit(1);
    }

    regmatch_t patternMatch[3];

    if(!(regexec(&pt, name, 3, patternMatch, 0))) {
        int start, end, len;

        start=patternMatch[2].rm_so;
        end=patternMatch[2].rm_eo;
        len=end-start;

        source=(char *)malloc((len+1) * sizeof(char));

        if(source==NULL) {
            perror("malloc");
            exit(1);
        }

        strncpy(source, name+start, len);
        print_result(source);
        free(source);
    }
    return(0);
}
