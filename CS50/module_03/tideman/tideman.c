#include <cs50.h>

#include <stdio.h>

#include <string.h>

#define MAX 9


int preferences[MAX][MAX];


bool locked[MAX][MAX];


typedef struct

{

int winner;

int loser;
}

pair;


string candidates[MAX];

pair pairs[MAX * (MAX - 1) / 2];

int pair_count;

int candidate_count;


bool vote(int rank, string name, int ranks[]);

void record_preferences(int ranks[]);

void add_pairs(void);

void sort_pairs(void);

void lock_pairs(void);

void print_winner(void);

int main(int argc, string argv[])

{

if (argc < 2)

{

    printf("Usage: tideman [candidate ...]\n");

    return 1;

}

candidate_count = argc - 1;

if (candidate_count > MAX)

{

    printf("Maximum number of candidates is %i\n", MAX);

    return 2;

}

for (int i = 0; i < candidate_count; i++)

{

    candidates[i] = argv[i + 1];

}


for (int i = 0; i < candidate_count; i++)

{

    for (int j = 0; j < candidate_count; j++)

    {

        locked[i][j] = false;

    }

}

pair_count = 0;

int voter_count = get_int("Number of voters: ");


for (int i = 0; i < voter_count; i++)

{

    int ranks[candidate_count];


    for (int j = 0; j < candidate_count; j++)

    {

        string name = get_string("Rank %i: ", j + 1);

        if (!vote(j, name, ranks))

        {

            printf("Invalid vote.\n");

            return 3;

        }

    }

    record_preferences(ranks);

    printf("\n");

}

add_pairs();

sort_pairs();

lock_pairs();

print_winner();

return 0;
}

bool vote(int rank, string name, int ranks[])

{


for (int i = 0; i < candidate_count; i++)

{

    if (strcmp(name, candidates[i]) == 0)

    {

        ranks[rank] = i;

        return true;

    }

}

return false;
}

void record_preferences(int ranks[])

{

for (int i = 0; i < candidate_count; i++)

{

    for (int j = i + 1; j < candidate_count; j++)

    {

        preferences[ranks[i]][ranks[j]]++;

    }

}

return;
}

void add_pairs(void)

{


for (int i = 0; i < candidate_count; i++)

{

    for (int j = i + 1; j < candidate_count; j++)

    {

        if (preferences[i][j] > preferences [j][i])

        {

            pairs[pair_count].winner = i;

            pairs[pair_count].loser = j;

            pair_count++;

        }

        else if (preferences[i][j] < preferences [j][i])

        {

            pairs[pair_count].winner = j;

            pairs[pair_count].loser = i;

            pair_count++;

        }

    }

}

return;
}

void sort_pairs(void)

{

for (int i = 0; i < pair_count; i++)

{

    int max = i;

    for (int j = i + 1; j < pair_count; j++)

    {

        if (preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[max].winner][pairs[max].loser])

        {

            max = j;

        }

    }

    pair temp = pairs[i];

    pairs[i] = pairs[max];

    pairs[max] = temp;

}

return;
}

bool is_circle(int winner, int loser)

{

if (winner == loser)

{

    return true;

}

for (int i = 0; i < pair_count; i++)

{

    if (pairs[i].winner == loser && locked[pairs[i].winner][pairs[i].loser] == true)

    {

        if (pairs[i].loser == winner || is_circle(winner, pairs[i].loser))

        {

            return true;

        }

    }

}

return false;
}

void lock_pairs(void)

{

for (int i = 0; i < pair_count; i++)

{

    if (is_circle(pairs[i].winner, pairs[i].loser) == false)

    {

        locked[pairs[i].winner][pairs[i].loser] = true;

    }

    else

    {

        locked[pairs[i].winner][pairs[i].loser] = false;

    }

}

return;
}

void print_winner(void)

{

for (int i = 0; i < candidate_count; i++)

{

    int a = 0;

    for (int j = 0; j < candidate_count; j++)

    {

        if (locked[j][i] == false)

        {

            a++;

            if (a == 3)

            {

                printf("%s\n", candidates[i]);

                break;

            }

        }

    }

}

return;
}