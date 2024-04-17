#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string lower_convert (string input)
{
    char *output;
    output = (char*) malloc(strlen(input) * 40);

    for (int i = 0; i < strlen(input); i++)
    {
        output[i] = tolower(input[i]);
    }

    free(output);

    return(output);
}

string upper_convert (string input)
{
    char *output;
    output = (char*) malloc(strlen(input) * 40);

    for (int i = 0; i < strlen(input); i++)
    {
        output[i] = toupper(input[i]);
    }

    free(output);

    return(output);
}

int main (void)
{
    char output = 'a';
    //Include alphabet library to match
    string all_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string all_lower = "abcdefghijklmnopqrstuvwxyz";
    string cipher = "VcHpRzGjNtLsKfBdQwAxEuYmOi";

    string lower = lower_convert(cipher);

    //printf("%s\n" , upper);
    //printf("%s\n" , lower);

    char cipher_text = get_char("Cipher Char: ");

    if (islower (cipher_text))
    {
        int order = 0;

        for (int i = 0; cipher_text != all_lower[i]; i++)
        {
            order = i + 1;
        }

        output = lower[order];
        printf("Original: %c\n" , all_lower[order]);
    }

    else
    {
        int order = 0;

        string upper = upper_convert(cipher);

        for (int j = 0; cipher_text != all_upper[j]; j++)
        {

            order = j + 1;
        }

        output = upper[order];
        printf("Original: %c\n" , all_upper[order]);
    }

    printf("%c\n" , output);
}