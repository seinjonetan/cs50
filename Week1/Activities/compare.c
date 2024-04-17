#include <stdio.h>
#include <cs50.h>

int main (void)
{
    //get user input
    int x = get_int("How many points did you lose? ");

    //define number
    const int MINE = 2;

    //output
    if (x > MINE)
    {
        printf("You lost more points than I did.\n");
    }
    else if (x < MINE)
    {
        printf("You lost less points than I did.\n");
    }
    else
    {
        printf("You lost just as many points as I did.\n");
    }
}