#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");

    // TODO: Compute and return score for string
    string all_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string all_lower = "abcdefghijklmnopqrstuvwxyz";
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int total_score = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        int letter_score =0;

        if (islower(word[i]))
        {
            int letter_tracker = 0;

            for (int j = 0; j < strlen(all_lower); j++)
            {
                if (word[i] == all_lower[j])
                {
                    letter_tracker = j;
                }
            }

            letter_score = POINTS[letter_tracker];
        }
        else if (isupper(word[i]))
        {
            int letter_tracker = 0;

            for (int j = 0; j < strlen(all_upper); j++)
            {
                if (word[i] == all_upper[j])
                {
                    letter_tracker = j;
                }
            }

            letter_score = POINTS[letter_tracker];
        }

        total_score += letter_score;
    }

    printf("Total score: %i\n" , total_score);
}