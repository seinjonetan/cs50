#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main (void)
{
    string input = get_string("Phrase: ");

    int total_sentence = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        int sentence = 0;

        if (input[i] == '.' || input[i] == '!' || input[i] == '?')
        {
            sentence = 1;
        }
        else
        {
            sentence = 0;
        }

        total_sentence += sentence;
    }

    printf("%i\n" , total_sentence);
}