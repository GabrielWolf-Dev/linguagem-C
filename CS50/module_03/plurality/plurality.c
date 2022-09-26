#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

#define MAX 9
candidate candidates[MAX];

int candidate_count;
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{

    candidate_count = argc - 1;
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[(i + 1)];
    }

    int voters = 0;
    do
    {
        voters = get_int("Number of voters: ");
    }
    while (voters <= 0);

    for (int i = 0; i < voters; i++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
}

bool vote(string name)
{
    for (int i = 0; i < candidate_count ; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}


void print_winner(void)
{
    int winner = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winner)
        {
            winner = candidates[i].votes;
        }
    }
    for (int o = 0; o < candidate_count; o++)
    {
        if (candidates[o].votes == winner)
        {
            printf("%s\n", candidates[o].name);
        }
    }
}