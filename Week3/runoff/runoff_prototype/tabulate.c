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
int voter_count = 1;
int candidate_count = 2;

int main(void)
{
    candidates[0].name = "Amy";
    candidates[0].votes = 0;
    candidates[0].eliminated = 1;

    candidates[1].name = "Bob";
    candidates[1].votes = 0;
    candidates[1].eliminated = 0;

    preferences[0][0] = 0;
    preferences[0][1] = 1;

    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (candidates[preferences[i][j]].eliminated == 0)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }

    printf("Amy: %i\n" , candidates[0].votes);
    printf("Bob: %i\n" , candidates[1].votes);
}