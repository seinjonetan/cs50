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

    if (remainder == 0)
    {
        if(input > pow(10 , 15))
        {
            long first_two = input / pow(10 , 14);
            long first_one = input / pow(10 , 15);

            if (first_two >= 51 && first_two <= 55)
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
                printf("AMEX\n");
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