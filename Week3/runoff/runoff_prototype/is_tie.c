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
int voter_count;
int candidate_count = 3;

int main(void)
{
    int min = 10;
    candidates[0].votes = 15;
    candidates[1].votes = 10;
    candidates[2].votes = 10;

    int tied = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
            tied++;
    }

    if (tied == candidate_count)
    {
        return true;
    }

    return false;
}