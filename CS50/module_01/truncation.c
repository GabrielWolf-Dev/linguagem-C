#include <cs50.h>
#include <stdio.h>

int main()
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    float z = (float) x / (float) y; // Operadores de conversão "(int,float,double,string,char,etc...)"

    printf("Result: %.2f\n", z);
}