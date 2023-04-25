#include <cs50.h>
#include <stdio.h>

void pyramid(int rows);

//ACCEPTS THE HIEGHT FROM USER
int main(void)
{
    int rows = 0;
    do
    {
        rows = get_int("Hieght: ");
    }
    while (rows <= 0 || rows > 8);
    pyramid(rows);
}

//PRINTS A MIRRORED AS WELL AS A STRAIGHT PYRAMID OF HIEGHT SUGGESTED BY THE USER
void pyramid(int rows)
{
    for (int x = 1; x <= rows; x++)
    {
        for (int y = x; y < rows; y++)
        {
            printf(" "); //PRINTS APPROPRIATE NUMBER OF SPACES
        }

        for (int y = 1; y <= x; y++)
        {
            printf("#"); //PRINTS APPROPRIATE NUMBER OF #

        }
        printf("  "); //PRINTS SPACES B/W PYRAMIDS
        for (int j = 1; j <= x; j++)
        {
            printf("#"); //PRINTS APPROPRIATE NUMBER OF #
        }
        printf("\n");
    }
}