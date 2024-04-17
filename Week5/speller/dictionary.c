// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int word_number = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char lcword[LENGTH + 1];

    for (int i = 0; i < LENGTH + 1; i++)
        lcword[i] = tolower(word[i]);


    unsigned int hash_number = hash(lcword);

    node *trav = table[hash_number];

    while (trav != NULL)
    {
        if (strcasecmp(trav->word , word) == 0)
            return true;

        trav = trav->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    char *alphabet = "abcdefghijklmnopqrstuvwxyz";

    unsigned int letter_number = 0;
    for (int i = 0; word[0] != alphabet[i]; i++)
        letter_number++;

    return letter_number;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    FILE *dic_contents = fopen(dictionary , "r");
    if (dic_contents == NULL)
        return false;


    //Insert word from dictionary
    char *load_word = malloc(LENGTH + 1);
    if (load_word == NULL)
    {
        return false;
    }

    while (fscanf(dic_contents, "%s" , load_word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
            return false;

        strcpy(new_node->word , load_word);
        new_node->next = NULL;

        unsigned int hash_number = hash(load_word);

        new_node->next = table[hash_number];
        table[hash_number] = new_node;

        word_number++;
    }

    free(load_word);
    fclose(dic_contents);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_number;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor->next != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        free(cursor);
    }

    return true;
}
