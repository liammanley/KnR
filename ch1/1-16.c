//Exercise 1-16: Revise the main routine of the longest line program so it will 
//correctly print the length of arbitrarily long input lines, and as much as possible of the text
//NOTE: getline() and copy() are from section 1.9: Character Arrays.
//NOTE: renamed getline() to my_getline() because getline() is a function in stdio.h
#include <stdio.h>
#define MAXLINE 1000 //maximum input line size

int my_getline(char s[], int lim);
void copy(char to[], char from[]);

int main(void){
    int len; //current line length
    int max = 0; //maximum length seen so far
    char line[MAXLINE]; //current input line
    char longest[MAXLINE]; //longest line saved here
    while ((len=my_getline(line, MAXLINE))>0){
        /*MY CHANGES*/
        if (len==MAXLINE-1 && line[MAXLINE-2]!='\n'){ //getline() didn't get the full line
            printf("getting rest of line\n");
            //update length with the rest of the line's length
            int c;
            while ((c=getchar())!='\n'){
                len++;
            }
            len++; //count newline
        }
        /*END OF MY CHANGES*/
        if (len > max){
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0){ // there was a line
        printf("%s", longest);
        printf("\nLongest Length: [%d]\n", max);
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

//copy: copy 'from' into 'to'; assume to is big enough
//this is just strcpy
void copy(char to[], char from[]){
    int i = 0;
    while ((to[i]=from[i]) != '\0'){
        i++;
    }
}