// open the dic file
// read by scanf words
// create node in the hash data struct
// load it with words

// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = LENGTH   * 'z';
int countw = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
// hash the word
//  point to the index at node table
// loop over the index linked list


bool check(const char *word)
{
    int index = hash(word);
    node *check = table[index];

    while (check != NULL)
    {
        if (strcasecmp(check->word, word) == 0)
        {
            return true;
        }
        check = check->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int s = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        s += tolower(word[i]);
    }
    return (s % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *fptr = fopen(dictionary, "r");
    // sc = malloc(sizeof(node));
    char str[LENGTH + 1];
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    while (fscanf(fptr, "%s", str) != EOF)
    {
        int hashn = hash(str);
        node *tmp = malloc(sizeof(node));
        if (!tmp)
        {
            return false;
        }
        strcpy(tmp->word, str);
        if (table[hashn] == NULL)
        {
            tmp->next = NULL;
            table[hashn] = tmp;
        }
        else
        {
            tmp->next = table[hashn];
            table[hashn] = tmp;
        }
        countw++;
    }
    node *buff = table[1];
    while (buff)
    {
        printf("//%s//", buff->word);
        buff = buff->next;
    }
    fclose(fptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return countw;
}

// Unloads dictionary from memory, returning true if successful, else false
// for loop while i < N
// tmp = cursor
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
