#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start_size = 0;
    int end_size = 0;

    // TODO: Prompt for start size
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    int total = 0;

    // TODO: Calculate number of years until we reach threshold
    for (int i = 0; start_size < end_size; i++)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        total = i + 1;
    }

    // TODO: Print number of years
    printf("Years: %i\n" , total);
}
