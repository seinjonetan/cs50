#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char cipher(char input, string lower, string upper)
{
    char output = 'a';

    string all_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string all_lower = "abcdefghijklmnopqrstuvwxyz";

    if (islower (input))
    {
        int order = 0;

        for (int i = 0; input != all_lower[i]; i++)
        {
            order = i + 1;
        }

        output = upper[order];
    }

    else
    {
        int order = 0;

        for (int j = 0; input != all_upper[j]; j++)
        {
            order = j +1;
        }

        output = lower[order];
    }

    return output;
}

int main (void)
{
    string plaintext = get_string("Text: ");

    for (int i =0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            char ciphertext = cipher(plaintext[i], "VCHPRZGJNTLSKFBDQWAXEUYMOI", "vchprzgjntlskfbdqwaxeuymoi");
            printf("%c" , ciphertext);
        }

        else
        {
            printf("%c" , plaintext[i]);
        }
    }

    printf("\n");
}