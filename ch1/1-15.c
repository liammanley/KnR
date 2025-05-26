//Exercise 1-15: Rewrite the temperature conversion program (1-4.c) to use a function for conversion
//Exercise 1-4: Write a program to print the corresponding Celcius to Fahrenheit table
#include <stdio.h>

float celciusToFahr(float celcius){
    //F = (9/5) * C + 32
    return (9.0/5.0) * celcius + 32;
}

int main(void){
    float celcius;
    printf("Celcius\tFahrenheit\n");
    //celcius values go from 0 to 40: 32 F to 104 F
    for (celcius = 0; celcius <=40; celcius+=5){
        printf("%7.0f\t%10.1f\n", celcius, celciusToFahr(celcius));
    }
    return 0;
}