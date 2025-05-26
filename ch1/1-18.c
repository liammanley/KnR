//Exercise 1-18: Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines
//NOTE: this program may incorrectly handle lines with length >= MAXLINE
//NOTE: getline() and copy() are from section 1.9: Character Arrays.
//NOTE: renamed getline() to my_getline() because getline() is a function in stdio.h
#include <stdio.h>
#define MAXLINE 1000 //maximum input line size

int my_getline(char s[], int lim);

int main(void){
    int len;
    char line[MAXLINE];
    while (len=my_getline(line, MAXLINE)){
        //last_index will be updated to hold the index of the last non-whitespace, or -1 if a blank line
        int last_index = len-2;
        while (last_index>=0){
            if (line[last_index]!=' ' && line[last_index]!='\t'){
                break; //found last non-whitespace
            }
            last_index--;
        }
        if (last_index!=-1){ //don't print a blank line
            line[last_index+1] = '\n';
            line[last_index+2] = '\0';
            printf("%s",line);
        }
    }
    return 0;
}

//getline: read a line into s, return length
int my_getline(char s[], int lim){
    int c, i;
    /*the loop condition works because (c=getchar())!=EOF is evaluated before c!='\n' because
    "Expressions connected by && or || are evaluated left to right" (KnR 21) */
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++){
        s[i]=c;
    }
    if (c=='\n'){
        s[i]=c;
        i++;
    }
    s[i]='\0';
    return i;
}
