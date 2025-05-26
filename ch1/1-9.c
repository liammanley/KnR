//Exercise 1.9: Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
#include <stdio.h>

int main(void){
    int c;
    int blank = 0;
    while ((c=getchar())!=EOF){
        if (c==' '){
            blank = 1;
        }
        else{
            //only put one blank when non-blank character is reached and blank == 1
            if (blank){
                putchar(' ');
                blank = 0;
            }
            putchar(c);
        }
    }
    return 0;
}