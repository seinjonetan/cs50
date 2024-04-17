#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Pick a number. ");

    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}