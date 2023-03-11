#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
int registerCandidates(int argc, string argv[]);
void collectVotes(int voter_count);
int countVotes();

int main(int argc, string argv[])
{
    int returnRegisterCandidates = registerCandidates(argc, argv);
    if (returnRegisterCandidates > 0)
    {
        return returnRegisterCandidates;
    }
    int voter_count = get_int("Number of voters: ");
    collectVotes(voter_count);
    print_winner();
}

int registerCandidates(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    return 0;
}

void collectVotes(int voter_count)
{
    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");
        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
}

// Update vote totals given a new vote
bool vote(string name)
{
    bool voteValid = false;
    string names = "";
    for (int i = 0; i < candidate_count; i++)
    {
        names = candidates[i].name;
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

int countVotes()
{
    int largerVote = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > largerVote)
        {
            largerVote = candidates[i].votes;
        }
    }
    return largerVote;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int largerVote = countVotes();
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == largerVote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}
