//Exercise 1-4: Write a program to print the corresponding Celcius to Fahrenheit table
#include <stdio.h>

int main(void){
    float fahr;
    float celcius;
    printf("Celcius\tFahrenheit\n");
    //celcius values go from 0 to 40: 32 F to 104 F
    for (celcius = 0; celcius <=40; celcius+=5){
        //F = (9/5) * C + 32
        fahr = (9.0/5.0) * celcius + 32;
        printf("%7.0f\t%10.1f\n", celcius, fahr);
    }
    return 0;
}