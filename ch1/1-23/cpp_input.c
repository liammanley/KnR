#include <stdio.h>
/*comment*/ /*another comment*/
/* /* comment */
int main(void){
    printf("hello, world!");
    printf("hello/*this is not a comment*/, world!" /*hi*/);
    /* " comment */
    //the quote is not the beginning of a string
    /*comment // */
    ///*comment*/ printf("hello!\n");
    char x = '\"'; /*comment*/
    printf("hello\" /*this is not a comment*/, world!");
    return 0;
}
