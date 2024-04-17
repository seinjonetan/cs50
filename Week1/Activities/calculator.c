#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int x = get_int("X: ");
    int y = get_int("Y: ");
    int z = x + y;
    printf("%i\n", z);
}