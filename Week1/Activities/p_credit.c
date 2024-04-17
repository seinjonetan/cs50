#include <stdio.h>
#include <cs50.h>
#include <math.h>

long check (long number, int even);

int main (void)
{
    long input = get_long("Number: ");

    long even_number = check(input , 2);
    long odd_number = check(input, 1);

    long total = even_number + odd_number;
    long remainder = total % 10;

    printf("%li\n" , total);

    if (remainder == 0)
    {
        printf("VALID\n");

        if(input > pow(10 , 15))
        {
            long first_two = input / pow(10 , 14);
            long first_one = input / pow(10 , 15);

            if (first_two >= 50)
            {
                printf("MASTERCARD\n");
            }
            else if (first_one  == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else if (input > pow(10 , 14) && input < pow(10 , 15))
        {
            long fifteen_two = input / pow(10 , 13);

            if (fifteen_two == 34 || fifteen_two == 37)
            {
                printf("AMAX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        else
        {
            long thirteen_two = input / pow(10 , 12);

            if (thirteen_two == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }

    printf("%li\n" , total);
}

long check (long number, int even)
{
    long f = 0;
    for(int i = even; i < 17; i += 2)
    {
        long a = i - 1;
        long b = pow(10 , i);
        long c = pow(10 , a);
        long d = number % b;
        long e = d / c;
        f += e * even;
        printf("%li\n" , f);
    }
    return f;
}