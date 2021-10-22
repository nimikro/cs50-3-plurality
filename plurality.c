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

int main(int argc, string argv[])
{
    // Check for invalid usage
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

    int voter_count = get_int("Number of voters: ");

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

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }

    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    candidate candidate_temp;
    int counter = 0;
    bool flag = false;
    //sort candidates, print the first, or if there is a tie (indicated by flag = true), print the tied candidates, amount equal to counter.
    for(int i = 0; i < candidate_count; i++)
    {
        for(int j = i+1; j < candidate_count; j++)
        {
            if(candidates[i].votes < candidates[j].votes)
            {
                candidate_temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = candidate_temp;
            }
            else if(candidates[i].votes > candidates[j].votes)
            {
                continue;
            }
            else //candidate tie
            {
                candidate_temp = candidates[i+1];
                candidates[i+1] = candidates[j];
                candidates[j] = candidate_temp;
                counter++;
                flag = true;
            }
        }
    }
    printf("%s\n", candidates[0].name); //print winner

    //if there is a tie and the counter is equal or higher than the number of candidates (counter starts at 0) then all candidates are tied.
    if(flag == true && counter >= candidate_count)
    {
        for(int i = 1; i < candidate_count; i++)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    //if there is a tie print all the tied candidates (1st cadidate is already printed out)
    else if(flag == true)
    {
        for(int i = 1; i < counter+1; i++) //counter+1 is used to skip over the first candidate whose name is already printed out.
        {
            printf("%s\n", candidates[i].name);
        }
    }

flag = false;
return;
}

