/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest. */
//Assume the program has no syntax errors
//This program does not remove double slash comments, like this one

//Keep track of:
//1. whether inside string or not
    //initially 0
    //inside_string = not inside_string when we see " and outside comment0
        //UNLESS:
        //inside_string == 1 and previous char is \
        //inside string == 0 and two previous chars were 
            // '\"' is the char representation of "
//Whether inside comment or not
    //initially 0
    //if we see /* and we're outside a string, inside_comment = 1
    //if we see */ and we're outside a string, inside_comment = 0
//inside comment: do nothing
//outside comment: putchar. and put the / if it was previous

#include <stdio.h>

int main(void){
    int inside_string = 0;
    int inside_comment = 0;
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
        //I/O
        if (!inside_comment){
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