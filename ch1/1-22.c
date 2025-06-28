//Exercise 1-22
/* Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column. */

//get line up to n-1 columns or \n (or potentially more if there's a tab at the end). null terminate. argument should be aray of size n
//if arr[return value-1] == '\n' just print the line
//else, go back until a non space character is reached. null terminate after the last non space. then printf("%s\n",arr)

#include <stdio.h>
#include <ctype.h> //isspace
#define MAXLINE 10
#define TABSTOP 8
#define COLUMNS 5

int get_shortline(char line[], int nth_col){
    int c;
    int i = 0;
    int col = 1;
    while ((c=getchar())!=EOF){
        col += (c=='\t') ? (8 - col % TABSTOP) : 1;
        line[i++] = c;
        if (c=='\n' || col >= nth_col){
            line[i] = '\0';
            return i;
            
        }
    }
    return 0; //signal EOF
}

int main(void){
    char line[COLUMNS];
    int len;
    while ((len = get_shortline(line, COLUMNS))){
        if (line[len-1]=='\n'){
            printf("%s",line);
        }
        else{
            //if the last character isn't a newline, walk backwards until finding a non space. Null terminate after the last non space.
            int i = len-1;
            //printf("i is %d\n",i);
            //printf("line is %s\n", line);
            while (isspace(line[i]) && i>=0){
                //printf("line[%d] is space\n",i);
                i--;
            }
            //printf("adding null terminat at index [%d]\n",i);
            line[i+1] = '\0';
            printf("%s\n",line);
        }
    }
    return 0;
}

