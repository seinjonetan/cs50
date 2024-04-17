#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string upper_convert (string input)
{
    char *output;
    output = (char*) malloc(strlen(input) * 100);

    for (int i = 0; i < strlen(input); i++)
    {
        output[i] = toupper(input[i]);
    }

    free(output);

    return(output);
}

int main (void)
{
    string input = get_string("Text: ");

    string output = upper_convert(input);

    printf("%s\n" , output);
}