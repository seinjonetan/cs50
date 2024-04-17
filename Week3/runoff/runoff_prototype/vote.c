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
int candidate_count = 1;

bool vote(int voter, int rank, string name);

int main(void)
{
    int voter = get_int("Voter: ");
    int rank = get_int("Rank: ");
    string name = get_string("Name: ");

    candidates[0].name = "Amy";
    candidates[0].votes = 0;
    candidates[0].eliminated = 0;

    printf("%i\n" , vote(voter, rank, name));
}

bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            printf("True\n");
            return true;
        }
    }

    printf("False\n");
    return false;
}