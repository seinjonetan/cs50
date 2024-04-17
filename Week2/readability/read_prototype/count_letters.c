#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string input = get_string("Word: ");

    int output = 0;
    int letter = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            letter = 1;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            letter = 1;
        }
        else
        {
            letter = 0;
        }

        output += letter;
    }

    printf("%i\n" , output);
}