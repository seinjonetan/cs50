#include <stdio.h>
#include <cs50.h>

int main (void)
{
    //get user input
    int x = get_int("Pick a number. ");

    //check if there are any remainders
    if (x % 2 == 0)
    {
        printf("This is an even number.\n");
    }
    else
    {
        printf("This is an odd number.\n");
    }
}