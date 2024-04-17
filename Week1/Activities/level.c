#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int x = get_int("Size ");

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < x; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}