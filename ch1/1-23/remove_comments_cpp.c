/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest. */
//Assume the program has no syntax errors
//This program removes single line (C++ style) comments. remove_comments.c only removes /* comments

#include <stdio.h>

int main(void){
    int inside_string = 0;
    int inside_comment = 0;
    int inside_singleline_comment = 0;
    //could be dangerous to not initialize previous if first entry in file is *. But is that even possible?
    int prevprev = '\0';
    int prev = '\0';
    int c;
    while ((c=getchar())!=EOF){
        //state transitions
        if (!inside_comment && !inside_string && prev=='/' && c=='*'){
            inside_comment = 1;
        }
        else if (!inside_comment && !inside_string && !(prevprev == '\'' && prev == '\\') && c=='\"'){
            inside_string = 1;
        }
        else if (!inside_comment && inside_string && prev!='\\' && c == '\"'){
            inside_string = 0;
        }
        else if (inside_comment && prev=='*' && c=='/'){
            inside_comment = 0;
        }
        else if (inside_singleline_comment && c=='\n'){
            inside_singleline_comment = 0;
        }
        else if (!inside_singleline_comment && !inside_comment && prev=='/' && c=='/'){
            inside_singleline_comment = 1;
        }
        //I/O
        if (!inside_comment && !inside_singleline_comment){
            if (prevprev != '*' && prev == '/'){
                putchar(prev);
            }
            if (prevprev=='*' && prev == '/' && inside_string){
                putchar(prev);
            }
            if (c!='/'){
                putchar(c);
            }
        }
        //update prev and prevprev
        prevprev = prev;
        prev = c;
    }
    return 0;
}