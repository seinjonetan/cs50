#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string standard_convert (string input)
{
    char *output;
    output = (char *) malloc(strlen(input)*100);

    for (int i = 0; i < strlen(input); i++)
    {
      output[i] = toupper(input[i]);
    }

    free(output);

    return output;
}

string lower_convert (string input)
{
    char *output;
    output = (char*) malloc(strlen(input)*100);

    for(int i = 0; i < strlen(input); i++)
    {
        output [i] = tolower(input [i]);
    }

    free(output);

    return output;
}

bool check_duplicate (string input)
{
    string all_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

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

    if (duplicate_count != 0)
    {
        yes_duplicate = 1;
    }

    else
    {
        yes_duplicate = 0;
    }

    return yes_duplicate;
}

int main (int argc, string argv[])
{
    string convert = standard_convert(argv[1]);

    printf("%s\n" , convert);

    string l_convert = lower_convert(convert);

    printf("%s\n" , l_convert);

    bool duplicate = check_duplicate(argv[1]);

    printf("%i\n" , duplicate);
}