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
int voter_count = 21;
int candidate_count = 2;

int main(void)
{
    candidates[0].name = "Amy";
    candidates[0].votes = 11;
    candidates[0].eliminated = 0;

    candidates[1].name = "Bob";
    candidates[1].votes = 8;
    candidates[1].eliminated = 0;

    int highest = 0;
    int majority = (voter_count / 2) + 1;

    for (int i = 0; i < candidate_count; i++)
    {
        if (highest < candidates[i].votes)
            highest = candidates[i].votes;
    }

    if (highest >= majority)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[j].votes == highest)
            {
                printf("%s\n" , candidates[j].name);
                return true;
            }
        }
    }

    return false;
}