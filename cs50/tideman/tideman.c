#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool cyc(int end, int cycle_start);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
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

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
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

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    int i = 0;

    // printf("//%d//", candidate_count);
    // exit (0);
    while (i < candidate_count)
    {
        if (!strcmp(name, candidates[i]))
        {
            ranks[rank] = i;
            return true;
        }
        i++;
    }
    // TODO
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    int i = 0;
    int j = i + 1;

    while (i < candidate_count)
    {
        while (j < candidate_count)
        {
            preferences[ranks[i]][ranks[j]] += 1;
            j++;
        }
        i++;
        j = i + 1;
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair p;
    for (int r = 0; r < candidate_count; r++)
    {
        for (int c = r + 1; c < candidate_count; c++)
        {
            if (preferences[r][c] > preferences[c][r])
            {
                p.winner = r;
                p.loser = c;
                pairs[pair_count++] = p;
            }
            else if ((preferences[r][c] < preferences[c][r]))
            {
                p.winner = c;
                p.loser = r;
                pairs[pair_count++] = p;
            }
        }
    }
    return;
}

void sort_pairs(void)
{
    int i = pair_count - 1;
    int j = 0;
    int a;
    int b;

    while (i)
    {
        while (j < i)
        {
            a = preferences[pairs[j].winner][pairs[j].loser];
            b = preferences[pairs[j + 1].winner][pairs[j + 1].loser];
            if (a < b)
            {
                pair tmp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = tmp;
            }
            j++;
        }
        i--;
        j = 0;
    }
    return;
}

void lock_pairs(void)
{
    // Loop through pairs
    for (int i = 0; i < pair_count; i++)
    {
        //If cycle returns false, lock the pair
        if (!cyc(pairs[i].loser, pairs[i].winner))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        int n = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
            {
                n++;
                if (n == candidate_count)
                {
                    printf("%s\n", candidates[i]);
                }
            }
        }

    }
    return;
}


bool cyc(int end, int cycle_start)
{
    // Return True if there is a cycle created (recursion base case)
    if (end == cycle_start)
    {
        return true;
    }
    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i])
        {
            if (cyc(i, cycle_start))
            {
                return true;
            }
        }
    }
    return false;
}