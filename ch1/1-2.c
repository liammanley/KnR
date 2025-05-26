//Exercise 1.1 and 1.2
#include <stdio.h>

int main(void){
    //an unknown escape sequence like \j results in a compiler warning
    //and ignores the backslash
    //output: "helloj, world!\n"
    printf("hello\j, world!\n");
    return 0;
}