//Exercise 1-21: Write a program entab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
//Assume a fixed set of tab stops, say every n columns.
//Note: A tab stop is every n characters.
//If the number of characters in the line before the tab is a multiple of n, the tab should be replaced by n spaces
//otherwise, the tab should be replaced by enough spaces to make the number of characters in the line a multiple of n
#include <stdio.h>

int main(void){
    int n = 8; //tab stops every n columns
    int c;
    int line_len = 0;
    while ((c=getchar())!=EOF){
        if (c!='\t'){
            if (c=='\n'){
                line_len = 0;
            }
            else{
                line_len++;
            }
            putchar(c);
        }
        else{
            int num_spaces = (line_len%n) ? n-(line_len%n) : n;
            for (int _ = 0; _ < num_spaces; _++){
                putchar(' ');
            }
            line_len = 0;
        }
    }
}