//Exercise 1-17: Write a program to print all input lines that are longer than 80 characters 
//NOTE: getline() and copy() are from section 1.9: Character Arrays.
//NOTE: renamed getline() to my_getline() because getline() is a function in stdio.h
#include <stdio.h>
#define MAXLINE 1000 //maximum input line size

int my_getline(char s[], int lim);

int main(void){
    int len; //current line length
    char line[MAXLINE]; //current input line
    while ((len=my_getline(line, MAXLINE))>0){
    	if (len>80){
	        printf("%s",line);
	    }
	//print the rest of the line if there is overflow
        while (len==MAXLINE-1 && line[MAXLINE-2]!='\n'){
            len = my_getline(line, MAXLINE);
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
