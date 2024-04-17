#include <stdio.h>
#include <cs50.h>

int main (void)
{
    string input = get_string("Phrase: ");

    int output = 0;
    int letter = 0;
    int word = 0;

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

        if (letter == 1 && input[i+1] == ' ')
        {
            word = 1;
        }
        else if (letter == 1 && input[i+1] == '.')
        {
            word = 1;
        }
        else if (letter == 1 && input[i+1] == '!')
        {
            word = 1;
        }
        else if (letter == 1 && input[i+1] == '?')
        {
            word = 1;
        }
        else
        {
            word = 0;
        }

        output += word;
    }

    printf("%i\n" , output);
}