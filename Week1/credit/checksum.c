#include <stdio.h>
#include <cs50.h>
#include <math.h>

long check (long number, int even);

int main (void)
{
    long input = get_long("Number: ");

    long output = check(input , 2);

    printf("Final Output: %li\n" , output);
}

long check (long number, int even)
{
    long final_digit = 0;
    long final_none = 0;
    for(int i = even; i < 17; i += 2)
    {
        long a = i - 1;
        long b = pow(10 , i);
        long c = pow(10 , a);
        long d = number % b;
        long e = d / c;

        int product = e * even;

        if (product >= 10)
        {
            int g = product % 10;
            int h = product / 10;
            final_digit += g + h;
        }

        else
        {
            final_none += product;
        }

    }

    long final = final_digit + final_none;
    return final;
}