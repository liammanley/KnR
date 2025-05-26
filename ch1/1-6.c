//Exercise 1-6: Verify that the expression getchar() != EOF is 0 or 1
#include <stdio.h>

int main(void){
    int c;
    //print each character and the value of (getchar()!=EOF)
    //it's a boolean expression, so getchar()!=EOF is always 1 or 0
    while (1){
        c = getchar();
        printf("%c %d\n", c, c!=EOF);
        if (c==EOF){
            break;
        }
    }
    return 0;
}