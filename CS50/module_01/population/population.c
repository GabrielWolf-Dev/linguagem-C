#include <cs50.h>
#include <stdio.h>

int growthPopulationYears(int currentPopulation)
{
    int mathFunction = currentPopulation + (currentPopulation / 3) - (currentPopulation / 4);
    return mathFunction;
}

int main(void)
{
    int initialSize, endSize;
    int years;
    int growthPopulation;

    do
    {
        initialSize = get_int("Start size: ");
    } 
    while (initialSize < 9);

    do
    {
        endSize = get_int("End size: ");
    } 
    while (endSize < initialSize);

    growthPopulation = growthPopulationYears(initialSize);

    for (years = 1; growthPopulation < endSize; years++)
    {
        growthPopulation = growthPopulationYears(growthPopulation);
    }

    printf("Years: %i\n", years);

}