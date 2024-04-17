#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count = 3;
int candidate_count;

int main(void)
{
    candidates[0].votes = 10;
    candidates[1].votes = 7;
    candidates[2].votes = 20;

    int lowest = candidates[0].votes;

    for (int i = 0; i < voter_count; i ++)
    {
        if (lowest > candidates[i].votes)
            lowest = candidates[i].votes;
    }

    printf("%i\n" , lowest);
}