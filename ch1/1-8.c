//Exercise 1.8: Write a program to count blanks (' '), tabs, and newlines
#include <stdio.h>

int main(void){
    int num_blanks = 0;
    int num_tabs = 0;
    int num_newlines = 0;
    int c;
    while ((c = getchar()) != EOF){
        if (c==' '){
            num_blanks++;
        }
        if (c=='\t'){
            num_tabs++;
        }
        if (c=='\n'){
            num_newlines++;
        }
    }
    printf("Input has [%d] blanks, [%d] tabs, [%d] newlines\n", num_blanks, num_tabs, num_newlines);
    return 0;
}