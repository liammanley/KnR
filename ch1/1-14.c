//Exercise 1-14: Write a program to print a histogram of the frequencies of different characters in its input
//Interpretation: Print the frequencies of each alphanumeric character and count the number of non-alphanumeric characters
#include <stdio.h>

void printHistogramHorizontal(int len_frequency[], char offset, int len);
int main(void){
    //len_frequency[MAX_LENGTH] represents the number of words at least MAX_LENGTH long
    int lower_frequency[26];
    int upper_frequency[26];
    int num_frequency[10];
    int other = 0;

    for (int i=0; i < 26; i++){
        lower_frequency[i]=0;
        upper_frequency[i]=0;
    }
    for (int i=0; i < 10; i++){
        num_frequency[i]=0;
    }
    int c;
    //get frequencies
    while ((c=getchar())!=EOF){
        if (c>='a' && c<='z'){
            lower_frequency[c-'a']++;
        }
        else if (c>='A' && c<='Z'){
            upper_frequency[c-'A']++;
        }
        else if (c>='0' && c<= '9'){
            num_frequency[c-'0']++;
        }
        else{
            other++;
        }
    }
    printHistogramHorizontal(lower_frequency, 'a', 26);
    printHistogramHorizontal(upper_frequency, 'A', 26);
    printHistogramHorizontal(num_frequency, '0', 10);
    printf("other characters: [%d]\n",other);
    return 0;
}

void printHistogramHorizontal(int data[], char offset, int len){
    for (int i=0; i < len; i++){
        printf("%c: ", offset+i);
        for (int _ = 0; _ < data[i]; _++){
            putchar('X');
        }
        putchar('\n');
    }
    putchar('\n');
}
