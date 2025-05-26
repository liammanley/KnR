//Exercise 1.3: Modify the temperature conversion program to print a heading above the table
//Original program: Fahrenheit to Celcius conversion table

#include <stdio.h>
#define LOW 0
#define HIGH 300
#define STEP 20

int main(void){
    float fahr;
    float celcius;
    printf("Fahrenheit\tCelcius\n");
    for (fahr = LOW; fahr <= HIGH; fahr += STEP){
        //C = (5/9) * (F-32)
        //5.0 and 9.0 are used so the result is a float
        celcius = (5.0/9.0) * (fahr-32.0);
        printf("%10.0f\t%7.1f\n", fahr, celcius);
    }
    return 0;
}