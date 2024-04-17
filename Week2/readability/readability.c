#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_letters (string input);
int count_words (string input);
int count_sentences (string input);

int main(void)
{
    string text = get_string("Text: ");

    float L = ((float) count_letters(text) / (float) count_words(text)) * 100;
    float S = ((float) count_sentences(text) / (float) count_words(text)) * 100;

    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int final = round(index);

    if (final > 16)
    {
        printf("Grade 16+\n");
    }
    else if (final < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n" , final);
    }
}

int count_letters (string input)
{
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

    return output;
}

int count_words (string input)
{
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
        else if (letter == 1 && input[i+1] == ',')
        {
            word = 1;
        }
        else
        {
            word = 0;
        }

        output += word;

    }

    return output;
}

int count_sentences (string input)
{
    int total_sentence = 0;

    for (int i = 0; input[i] != '\0'; i++)
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

    return total_sentence;
}