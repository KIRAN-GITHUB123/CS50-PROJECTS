//imports modules required
#include <stdio.h>
#include <cs50.h>
int main(void)
//asks for the users name and greets him
{
    string first = get_string("What's your name? ");
    printf("hello, %s\n", first);
}