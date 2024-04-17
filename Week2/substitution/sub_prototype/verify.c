#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
    string key = get_string("Number: ");

    int all_letter = 0;

    for (int i = 0; i < strlen(key); i ++)
    {
        int letter_or_not = isalpha(key[i]);
        all_letter += letter_or_not;
        printf("%i\n" , all_letter);
    }

    printf("%lu\n" , (strlen(key) * 1024));

    if (all_letter == (strlen(key) * 1024))
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}