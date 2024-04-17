#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    string all_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string input = get_string("Text: ");

    int duplicate_count = 0;
    int yes_duplicate = 0;

    for (int i = 0; i < 26; i ++)
    {
        int duplicate = 0;
        int total_count = 0;

        for (int j = 0; j < strlen(input); j++)
        {
            int count = 0;

            if (all_upper[i] == input[j])
            {
                count = 1;
            }

            else
            {
                count = 0;
            }

            total_count += count;
        }

        if (total_count > 1)
        {
            duplicate = 1;
        }
        else
        {
            duplicate = 0;
        }

        duplicate_count += duplicate;
    }

    printf("%i\n" , duplicate_count);

    if (duplicate_count != 0)
    {
        yes_duplicate = 1;
    }

    else
    {
        yes_duplicate = 0;
    }

    printf("%i\n" , yes_duplicate);
}