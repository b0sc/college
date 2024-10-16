#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 9
#define MAX_NAME 50
#define MAX_VOTERS 1000
#define string char*

// wrapper for default free to avoid dangling pointer
// by setting the freed pointer to NULL

#define free(x)  {free((x));x=NULL;}

typedef struct{
    string name;
    int votes;
    bool eliminated;
}candidate;


typedef struct{
    candidate *candidates;
    int count;
}candidates_t;


bool vote(candidates_t *candidates,int pref_table[MAX_VOTERS][MAX_CANDIDATES], int voter, int rank, string name){
    for (int i = 0; i < candidates->count; i++){
        if (strcmp(candidates->candidates[i].name, name) == 0){
            pref_table[voter][rank] = i;
            return true;
        }
    }
    return false;
}

void tabulate(candidates_t *candidates,int pref_table[MAX_VOTERS][MAX_CANDIDATES],int voter_count){
    for (int i = 0; i < voter_count; i++){
        // Find the highest-ranked non-eliminated candidate
        for (int j = 0; j < candidates->count; j++){
            int candidate_index = pref_table[i][j];
            if (!candidates->candidates[candidate_index].eliminated){
                candidates->candidates[candidate_index].votes++;
                // Only count the top non-eliminated candidate
                break; 
            }
        }
    }
}

bool print_winner(candidates_t *candidates,int voter_count){
    // Calculate majority
    int majority = voter_count / 2;
    for (int i = 0; i < candidates->count; i++){
        if (candidates->candidates[i].votes > majority){
            printf("%s\n", candidates->candidates[i].name);
            // Found a winner
            return true;
        }
    }
    // No winner yet
    return false;
}

int find_min(candidates_t *candidates){
    // Start with maximum possible votes
    int min_votes = MAX_VOTERS;

    for (int i = 0; i < candidates->count; i++){
        if (!candidates->candidates[i].eliminated && candidates->candidates[i].votes < min_votes){
            // Update min if found fewer votes
            min_votes = candidates->candidates[i].votes;
        }
    }
    return min_votes;
}

bool is_tie(candidates_t *candidates,int min){
    for (int i = 0; i < candidates->count; i++){
        if (!candidates->candidates[i].eliminated && candidates->candidates[i].votes != min){
            // Not all remaining candidates are tied
            return false;
        }
    }
    // All remaining candidates have the same votes
    return true;
}

void eliminate(candidates_t *candidates,int min){
    for (int i = 0; i < candidates->count; i++){
        if (candidates->candidates[i].votes == min){
            // Eliminate this candidate
            candidates->candidates[i].eliminated = true;
        }
    }
}


int get_votes(candidates_t candidates,int pref_table[MAX_VOTERS][MAX_CANDIDATES],int voter_count){
       // Get votes from each voter
    for (int i = 0; i < voter_count; i++){
        printf("\n");
        for (int j = 0; j < candidates.count; j++){
            char name[MAX_NAME];
            printf("Rank %i: ", j + 1);
            scanf("%s",name);
            if (!vote(&candidates,pref_table,i, j, name)){
                printf("Invalid vote.\n");
                return 1;
            }
        }
    }
    return 0;
}


void read_int(int *var){
    char dummy;
    // we use %c to capture the newline or enter key,
    // to avoid conflict in later codes
    // as only doing %d, will not clear the stdin
    // leaving newline in stding buffer
    // which gets read by next scanf, so to avoid it
    // we capture the newline in a dummy variable
    scanf("%d%c",var,&dummy);
}

void initialize_candidates(candidates_t *candidates,string argv[]){
     for (int i = 0; i < candidates->count; i++){
        candidates->candidates[i].name = argv[i + 1];
        candidates->candidates[i].votes = 0;
        candidates->candidates[i].eliminated = false;
    }
}


int main(int argc, string argv[]){
    // Check for invalid usage


    int pref_table[MAX_VOTERS][MAX_CANDIDATES];
    int voter_count;

    if (argc < 2 || argc > MAX_CANDIDATES + 1){
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }
    
    candidates_t candidates = (candidates_t){
        .candidates = malloc(sizeof(candidate)*MAX_CANDIDATES),
        .count = argc-1
    };
    
    initialize_candidates(&candidates,argv);

    printf("Number of voters: ");
    read_int(&voter_count);

    if(get_votes(candidates,pref_table,voter_count)){
        return 1;
    }


    // Keep conducting rounds until a winner is found
    while (true){
        // Tabulate the votes
        tabulate(&candidates,pref_table,voter_count);

        // Check if a candidate has won
        if (print_winner(&candidates,voter_count)){
            break;
        }

        // Find the minimum number of votes
        int min = find_min(&candidates);

        // Check for a tie
        if (is_tie(&candidates,min)){
            for (int i = 0; i < candidates.count; i++){
                if (!candidates.candidates[i].eliminated){
                    printf("%s\n", candidates.candidates[i].name);
                }
            }
            break;
        }

        // Eliminate candidates with the minimum votes
        eliminate(&candidates,min);

        // Reset the votes for the next round
        for (int i = 0; i < candidates.count; i++){
            candidates.candidates[i].votes = 0;
        }
    }
    free(candidates.candidates);
    return 0;
}
