#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (void)
{

    string key = get_string("Number: ");

    int letter_or_not = 0;

    for (int i = 0; i < strlen(key); i ++)
    {
        letter_or_not = isalpha(key[i]);
        letter_or_not += letter_or_not;
    }

    printf("%i\n" , letter_or_not);

    int length_rule = strlen(key) * 1024;

    printf("%i\n" , length_rule);

    if (letter_or_not < length_rule)
    {
        printf("0\n");
    }
    else
    {
        printf("1\n");
    }
}
