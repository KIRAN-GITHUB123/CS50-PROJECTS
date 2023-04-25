#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//NOTE: COMMON ERROE IS THE TYPE OF VARS DECLARED (FLOAT/DOUBLE ONLY)
//39 REFERS TO THE ASCII VALUE OF AN APOSTOPHE

//Coleman-Liau index//
//FORMULA: index = 0.0588 * L - 0.296 * S - 15.8
//where L is the average number of letters per 100 words in the text.
//S is the average number of sentences per 100 words in the text.

//If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level),
//your program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1,
//your program should output "Before Grade 1"

void grade(string text, int len);
int main(void)
{
    string text = get_string("Text: ");
    int len = strlen(text);
    grade(text, len);
}

void grade(string text, int len)
{
    string aa = "'";
    float chars = 0;
    float words = 1;
    float sentences = 0;
    double index = 0;

    for (int i = 0; i < len; i++) //loop for iterating through the sentence entered
    {
        if (text[i] == '"' || text[i] == ' ' || text[i] == '.' || text[i] == '!' || text[i] == '?' || text[i] == ',' || text[i] == 39)
        {
            chars = chars + 0;
        }
        else
        {
            chars = chars + 1;
        }

        //count words
        if (text[i] == ' ')
        {
            words = words + 1;
        }
        else
        {
            words = words + 0;
        }

        //counts sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences = sentences + 1;
        }
        else
        {
            sentences = sentences + 0;
        }
    }

    //Finds the averages
    float a = (chars / words);
    double L = (a * 100.0);
    float b = (sentences / words);
    double S = (b * 100.0);

    //formula application //Coleman-Liau index//
    index = (0.0588 * L - 0.296 * S - 15.8);
    int index1 = round(index);

    //grading & printing result //refer the earlier comments for mechanism//
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index1);
    }
}