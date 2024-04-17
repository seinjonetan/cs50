#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int x = 0;

    while(x < 1 || x > 8)
    {
        x = get_int("Size: ");
    }

    int y = 1;
    for(int j = 0; j < x; j++)
    {
        int z = x - y;

        for(int k = 0; k < z; k++)
        {
            printf(" ");
        }
        for(int l = 0; l < y; l++)
        {
            printf("#");
        }
        printf("  ");
        for(int m = 0; m < y; m++)
        {
            printf("#");
        }

        printf("\n");
        y++;

    }
}