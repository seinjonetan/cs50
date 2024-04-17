#include <stdio.h>
#include <cs50.h>

int main (void)
{
    string input = get_string("Phrase: ");

    int total_blanks = 0;
    int total_sentence = 0;
    int sentence = 0;
    int sentence_track = 0;
    int word_track = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '.')
        {
            for (int j = sentence_track; input[j] != '.'; j++)
            {
                int blanks = 0;

                if (input[j] == ' ')
                {
                    blanks = 1;
                    word_track = j;
                }
                else
                {
                    blanks = 0;
                }

                total_blanks += blanks;
                printf("%i\n" , total_blanks);
            }

            if (total_blanks > 1)
            {
                sentence = 1;
            }
            else
            {
                sentence = 0;
            }

            sentence_track = i;
        }
        else if (input[i] == '!' || input[i] == '?')
        {
            sentence = 1;
            sentence_track = i;
        }
        else
        {
            sentence = 0;
        }

        total_sentence += sentence;
    }

    printf("%i\n" , total_sentence);
}