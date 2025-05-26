//Exercise 1-19: Write a function reverse(s) that reverses the character string s.
    //Use it to write a program that reverses its input a line at a time
//NOTE: getline() and copy() are from section 1.9: Character Arrays.
//NOTE: renamed getline() to my_getline() because getline() is a function in stdio.h
#include <stdio.h>
#define MAXLINE 1000 //maximum input line size

int my_getline(char s[], int lim);
void reverse(char s[]);

int main(void){
    int len;
    char line[MAXLINE];
    while (len=my_getline(line, MAXLINE)){
        //replace the newline with the null terminator, so the newline isn't reversed
        line[len-1] = '\0';
        reverse(line);
        printf("%s\n", line); //print newline at the end
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

void reverse(char s[]){
    int end;
    for (end = 0; s[end]; end++);
    end --; //end is now the index of last char. Alternatively, I could have used end = strlen(s)-1
    for (int start = 0; start<end; start++, end--){
        int temp = s[start];
        s[start] = s[end];
        s[end] = temp;
    }
}