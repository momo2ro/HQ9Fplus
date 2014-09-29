#include <stdio.h>
#include <string.h>
#include "def.h"

void replace_char(char *source, char bef, char aft) {
    char *rep;
    /* replace only first character. */
    if(!(rep=strchr(source, bef))) return;
    *rep=aft;
}
