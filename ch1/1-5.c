//Exercise 1.3: Modify the teamperature conversion program to print the table in reverse order,
//that is, from 300 degrees to 0
//Original program: Exercise 1.3

#include <stdio.h>
#define LOW 0
#define HIGH 300
#define STEP 20

int main(void){
    float fahr;
    float celcius;
    printf("Fahrenheit\tCelcius\n");
    for (fahr = HIGH; fahr >= LOW; fahr -= STEP){
        //C = (5/9) * (F-32)
        //5.0 and 9.0 are used so the result is a float
        celcius = (5.0/9.0) * (fahr-32.0);
        printf("%10.0f\t%7.1f\n", fahr, celcius);
    }
    return 0;
}