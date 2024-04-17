#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    string input = get_string("Text: ");

    char *output;
    output = (char*) malloc(strlen(input));

    for (int i = 0; i < strlen(input); i++)
    {
        output[i] = toupper(input[i]);
        printf("%c\n", output[i]);
    }

    free(output);

    return 0;
}