#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool key_checker (string input);
bool check_duplicate (string input);
string upper_convert (string input);
string lower_convert (string input);
char cipher (char input, string cipher_lower, string cipher_upper);

int main (int argc, string argv[])
{
    if (argc == 2)
    {
        if (key_checker(argv[1]) == 1 && check_duplicate(upper_convert(argv[1])) == 0 && strlen(argv[1]) == 26)
        {
            string input = get_string("plaintext: ");

            string ci_lower = lower_convert(argv[1]);
            string ci_upper = upper_convert(argv[1]);

            printf("ciphertext: ");

            for (int i = 0; i < strlen(input); i++)
            {
                char output = 'a';
                char temp = 'a';

                if (isalpha(input[i]))
                {
                    temp = cipher(input[i] , ci_lower, ci_upper);

                    if (islower(input[i]))
                    {
                        output = tolower(temp);
                    }

                    else
                    {
                        output = temp;
                    }

                    printf("%c" , output);
                }

                else
                {
                    printf("%c" , input[i]);
                }
            }

            printf("\n");

            return 0;
        }
        else
        {
            printf("Insert 26 unique letters in any order.\n");

            return 1;
        }
    }
    else
    {
        return 1;
    }
}

bool key_checker (string input)
{
    int all_letter = 0;
    int letter_or_not = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        letter_or_not = isalpha(input[i]);
        all_letter += letter_or_not;
    }

    if (all_letter < (strlen(input) * 1024))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool check_duplicate (string input)
{
    string all_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int duplicate_count = 0;
    int yes_duplicate = 0;

    for (int i = 0; i < 26; i ++)
    {
        int duplicate = 0;
        int total_count = 0;

        for (int j = 0; j < strlen(input); j++)
        {
            int count = 0;

            if (all_upper[i] == input[j])
            {
                count = 1;
            }

            else
            {
                count = 0;
            }

            total_count += count;
        }

        if (total_count > 1)
        {
            duplicate = 1;
        }
        else
        {
            duplicate = 0;
        }

        duplicate_count += duplicate;
    }

    if (duplicate_count != 0)
    {
        yes_duplicate = 1;
    }

    else
    {
        yes_duplicate = 0;
    }

    return yes_duplicate;
}

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

string lower_convert (string input)
{
    char *output;
    output = (char*) malloc(strlen(input) * 100);

    for (int i = 0; i < strlen(input); i++)
    {
        output[i] = tolower(input[i]);
    }

    free(output);

    return(output);
}

char cipher (char input, string cipher_lower, string cipher_upper)
{
    char output = 'a';

    string all_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string all_lower = "abcdefghijklmnopqrstuvwxyz";

    if (islower(input))
    {
        int order = 0;

        for (int i = 0; input != all_lower[i]; i++)
        {
            order = i + 1;
        }

        output = cipher_lower[order];
    }
    else
    {
        int order = 0;

        for (int i = 0; input != all_upper[i]; i++)
        {
            order = i + 1;
        }

        output = cipher_upper[order];
    }

    return output;
}