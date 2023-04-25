#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>

bool valid(long number, int C);
void brand(int C, string num, long number);

int main(void) //accepts the card number from user
{
    string num = get_string("ENTER YOUR CARD NUMBER: ");
    long number = atol(num); //converts string to long
    int C = strlen(num);
    valid(number, C);
    brand(C, num, number);
}

void brand(int C, string num, long number) //decides the brand based on given specifications
{
    if (valid(number, C) == true) //validates card number before proceeding
    {
        if (C == 15)
        {
            if ((num[0] == '3' && num[1] == '2') || (num[0] == '3' && num[1] == '7')) //iterates and checks conditions
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (C == 16)
        {
            if (num[0] == '4')
            {
                printf("VISA\n");
            }
            else if ((num[0] == '3' && num[1] == '2') || (num[0] == '3' && num[1] == '7')) //iterates and checks conditions
            {
                printf("AMEX\n");
            }
            else if (num[0] == '5' && (num[1] == '1' || num[1] == '2' || num[1] == '3' || num[1] == '4' || num[1] == '5'))
            {
                //iterates and checks conditions
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (C == 13)
        {
            if (num[0] == '4')
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool valid(long number, int C) //Luhn’s Algorithm: checks the validity of credit card
{
    int i = 0; //for iterating
    int temp = 0; //stores the temp value
    int first = 0; //gets the first value for cal
    int second = 0; //gets the second value for cal
    int final = 0; //gets the final value for cal

    while (number)
    {
        if (i % 2 != 0)
        {
            first = ((number % 10) * 2);
            if (first > 9)
            {
                while (first)
                {
                    temp += first % 10;
                    first /= 10;
                }
            }
            temp += first;
        }
        else
        {
            second += number % 10;
        }
        number /= 10;
        i++;
    }

    temp += second;
    final = temp % 10;
    if (final == 0)
    {
        return 1; //1 => true
    }
    return 0; //0 => false
}