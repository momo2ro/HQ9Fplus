#ifndef DEF_H
#define DEF_H

int interpreter();
int file_compile(FILE *f);
int file_name(char *name);
int print_result(char *source);
void replace_char(char *source, char bef, char aft);

#define BUFFERSIZE 100
#define FIZZBUZZ_NUMBER 1000
#define USAGE "Usage: ./hq9fp [-h(print this help)] [-i(launch shell)] [-p(source from filename)] [FILE...]"

#endif
