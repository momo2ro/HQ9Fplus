#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "def.h"

static void hello();
static void _source(char *source);
static void _99_bottles_of_beer();
static void on_the_wall(int number);
static void take_one_down(int number);
static char *bottle_s(int number);
static char *no_or_number(int number);
static void fizzbuzz(int number);

int print_result(char *source) {
    int i=0;
    int counter=0;

    while(source[i] != '\0') {
        source[i] = toupper(source[i]);
        if(source[i]!='H' && source[i]!='Q' && source[i]!='9' && source[i]!='F' && source[i]!='+') {
            perror("Syntax error\n");
            return(0);
        }
        i++;
    }

    i=0;
    while(source[i] != '\0') {
        switch(source[i]) {
            case 'H':
                hello();
                break;
            case 'Q':
                _source(source);
                break;
            case '9':
                _99_bottles_of_beer();
                break;
            case 'F':
                fizzbuzz(FIZZBUZZ_NUMBER);
                break;
            case '+':
                counter++;
                break;
        }
        i++;
    }
    return 0;
}

static void hello() {
    printf("Hello, world!\n");
}

static void _source(char *source) {
    printf("%s", source);
}

static void _99_bottles_of_beer() {
    int i=99;
    while(i>=0) {
        on_the_wall(i);
        i--;
        take_one_down(i);
        printf("\n");
    }
}

static void on_the_wall(int number) {
    printf("%s %s of beer on the wall, %s %s of beer.\n", no_or_number(number), bottle_s(number), no_or_number(number), bottle_s(number));
}

static void take_one_down(int number) {
    if(number==-1) printf("Go to the store and buy some more, 99 bottles of beer on the wall.\n");
    else printf("Take one down and pass it around, %s %s of beer on the wall.\n", no_or_number(number), bottle_s(number));
}

static char *no_or_number(int number) {
    if(number==0) return "No more";
    else {
        char btr[2];
        char *bt = btr;
        sprintf(bt, "%d", number);
        return bt;
    }
}

static char *bottle_s(int number) {
    if(number==1) return "bottle";
    else return "bottles";
}

static void fizzbuzz(int number) {
    int i;
    for(i=1;i<=number;i++) {
        if(i%15==0) printf("FizzBuzz");
        else if(i%3==0) printf("Fizz");
        else if(i%5==0) printf("Buzz");
        else printf("%d", i);
        printf(" ");
    }
    printf("\n");
}
