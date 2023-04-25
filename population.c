//we have a population of n llamas.
// Each year,
// n / 3 new llamas are born,
// and n / 4 llamas pass away.

#include <cs50.h>
#include <stdio.h>
int get_start_size(void);
int get_end_size(int start_size);

int main(void) //gets both of the earlier values and calculates the result
{
    int years = 0;
    int s = get_start_size();
    int e = get_end_size(s);
    while (s < e)
    {
        s = s + (s / 3) - (s / 4);
        years = years + 1;
    }
    printf("Years: %d \n", years);
}

int get_start_size(void) //gets the start value
{
    int start_size;
    do
    {
        start_size = get_int("ENTER THE START SIZE: ");
    }
    while (start_size < 9);
    return start_size;
}

int get_end_size(int start_size) //gets end value
{
    int end_size;
    do
    {
        end_size = get_int("ENTER THE END SIZE: ");
    }
    while (start_size > end_size);
    return end_size;
}