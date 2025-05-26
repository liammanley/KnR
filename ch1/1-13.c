//Exercise 1-13: Write a program to print a histogram of the lengths of words in its input
//I did the horizontal histogram
#include <stdio.h>
#define MAX_LENGTH 10 //maximum length of a word

void printHistogramHorizontal(int len_frequency[]);
void printHistogramVertical(int len_frequency[]);
int getHistogramHeight(int len_frequency[]);

int main(void){
    //len_frequency[MAX_LENGTH] represents the number of words at least MAX_LENGTH long
    int len_frequency[MAX_LENGTH+1];
    for (int i=0; i <= MAX_LENGTH; i++){
        len_frequency[i]=0;
    }
    int length = 0;
    int c;
    //get frequencies
    while ((c=getchar())!=EOF){
        if (c==' ' || c=='\t' || c=='\n'){
            //blank, tab, newline: record word length.
            //multiple consecutive blanks, tabs, or newlines will update len_frequency[0]
            //that's OK because we ignore len_frequency[0] in the histogram
            if (length >= MAX_LENGTH){
                len_frequency[MAX_LENGTH]++;
            }
            else{
                len_frequency[length]++;
            }
            length = 0;
        }
        else{
            length++;
        }
    }
    printHistogramVertical(len_frequency);
    return 0;
}

void printHistogramHorizontal(int len_frequency[]){
    for (int i=1; i < MAX_LENGTH; i++){
        printf("%4d: ", i);
        for (int _ = 0; _ < len_frequency[i]; _++){
            putchar('X');
        }
        putchar('\n');
    }
    printf(">=%d: ", MAX_LENGTH);
    for (int _ = 0; _ < len_frequency[MAX_LENGTH]; _++){
        putchar('X');
    }
    putchar('\n');
}

void printHistogramVertical(int len_frequency[]){
    int height = getHistogramHeight(len_frequency);
    //print Xs
    for (int row = height; row > 0; row--){
        for (int i = 1; i <= MAX_LENGTH; i++){
            if (len_frequency[i]>=row){
                printf("     X");
            }
            else{
                printf("      ");
            }
        }
        putchar('\n');
    }
    //print bottom row
    for (int i = 1; i < MAX_LENGTH; i++){
        printf("%6d", i);
    }
    printf("  >=%d\n", MAX_LENGTH);
}

int getHistogramHeight(int len_frequency[]){
    //find the largest value in the histogram
    int height = 0;
    for (int i=1; i <= MAX_LENGTH; i++){
        if (len_frequency[i]>height){
            height = len_frequency[i];
        }
    }
    return height;
}