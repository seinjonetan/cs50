#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int x = get_int("Width ");

    for(int i = 0; i < x; i++)
    {
        printf("#");
    }
    printf("\n");
}