#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string input = get_string("Text: ");

    int total_sentence = 0;
    int j = 0;
    int k = 0;

    for (int i = 0; input [i] != '\0'; i++)
    {
        int sentence = 0;
        int word_count = 0;
        int word = 0;

        for (j = 0; input[i] != '.' || input[i] != '?' || input[i] != '!'; j++)
        {
            for (k = 0; input[i] != '.' || input[i] != '?' || input[i] != '!' || input[i] != ' '; k++)
            {
                int letter = 0;

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
                else if (letter == 1 && input[i+1] == ',')
                {
                    word = 1;
                }
                else
                {
                    word = 0;
                }

                word_count += word;
            }
        }

        if (word_count < 2)
        {
            sentence = 0;
        }
        else
        {
            sentence = 1;
        }
        total_sentence += sentence;
    }

    printf("%i\n" , total_sentence);
}